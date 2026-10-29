#!/usr/bin/env python3
"""Log machine health while a heavy job runs, so a host hang leaves evidence (AGENTS.md "Hardware use").

Usage: tools/healthlog.py [--watch PID] [--label TEXT] [--interval SEC] [--dir DIR]
  --watch PID   stop when PID exits (tools/ghidra-cap.sh passes the job's PID); without it, run until killed
  HEALTH_SYSLOG remote syslog host[:port], UDP [192.168.10.50:514]; empty or 0 turns it off
  HEALTH_DIR    log directory [~/.cache/ft710-health]; HEALTH_INTERVAL seconds between samples [10]

Every line goes to the remote syslog (facility local0, tag ft710-health; GAP/WARN/KERNEL at warning, the rest
at info) and to a local file as a fallback for the last lines a hang keeps off the network: one file per
run, health-<UTC time>-<pid>.log, plus health-latest.log pointing at it. Each sample is one line of
key=value fields, flushed and fsynced so it survives a hard reset:
  temps (C): cpu_pkg, core_max, board sensors (nct6687), nvme, gpu; fans (rpm); cpu MHz avg/min
  thr=      CPU thermal-throttle events since the last sample
  load, run= runnable tasks, iowait=% / steal=% of CPU time since the last sample
  mem (MB): avail, free, dirty, wback, shmem; cg= this container's cgroup usage
  majflt/s  major page faults per second (high = memory thrashing, the usual cause of a no-swap freeze)
  oom=      kernel OOM kills since the last sample; job_rss= MB of the watched process tree, dec= decompiler count
Also logs: GAP when a sample is late by more than 3 intervals (the host stalled), new kernel messages about
OOM, hung tasks, throttling, MCE or I/O errors, and at start a warning if the previous run has no END line
(it was cut off by a hang or reset).
"""
import argparse, glob, os, re, socket, subprocess, sys, time


def rd(path, default=None):
    try:
        with open(path) as f:
            return f.read().strip()
    except OSError:
        return default


def hwmon():
    """name -> {(sysfs key, label): value} for every hwmon device."""
    out = {}
    for h in sorted(glob.glob("/sys/class/hwmon/hwmon*")):
        name = rd(h + "/name", "?")
        vals = out.setdefault(name, {})
        for inp in glob.glob(h + "/*_input"):
            key = os.path.basename(inp)[:-6]
            v = rd(inp)
            if v is None or not v.lstrip("-").isdigit():
                continue
            vals[(key, rd(f"{h}/{key}_label", key))] = int(v)
    return out


def temps_fans():
    hw, f = hwmon(), []
    core = hw.get("coretemp", {})
    pkg = next((v for (_, k), v in core.items() if k.startswith("Package")), None)
    cores = [v for (_, k), v in core.items() if k.startswith("Core")]
    if pkg is not None:
        f.append(f"cpu_pkg={pkg // 1000}")
    if cores:
        f.append(f"core_max={max(cores) // 1000}")
    for name, vals in hw.items():
        if name.startswith("nct"):
            for (key, label), v in sorted(vals.items()):
                label = label.replace(" ", "_")
                if key.startswith("fan") and v:  # this board reports 0 for fans the driver can't read
                    f.append(f"{label}={v}")
                elif key.startswith("temp"):
                    f.append(f"{label}={v // 1000}")
    nv = [v for n, vals in hw.items() if n == "nvme" for (_, k), v in vals.items() if k == "Composite"]
    if nv:
        f.append("nvme=" + "/".join(str(v // 1000) for v in nv))
    return f


def gpu():
    try:
        r = subprocess.run(["nvidia-smi", "--query-gpu=temperature.gpu", "--format=csv,noheader"],
                           capture_output=True, text=True, timeout=5)
        t = r.stdout.split()
        return [f"gpu={t[0]}"] if r.returncode == 0 and t else []
    except (OSError, subprocess.TimeoutExpired):
        return []


def cpufreq():
    mhz = [int(v) // 1000 for p in glob.glob("/sys/devices/system/cpu/cpu[0-9]*/cpufreq/scaling_cur_freq")
           if (v := rd(p)) and v.isdigit()]
    return [f"mhz={sum(mhz) // len(mhz)}", f"mhz_min={min(mhz)}"] if mhz else []


def throttle_total():
    n = 0
    for p in glob.glob("/sys/devices/system/cpu/cpu[0-9]*/thermal_throttle/*_throttle_count"):
        v = rd(p)
        n += int(v) if v and v.isdigit() else 0
    return n


def cpustat():
    for line in (rd("/proc/stat", "") or "").splitlines():
        if line.startswith("cpu "):
            return [int(x) for x in line.split()[1:]]
    return []


def vmstat():
    d = {}
    for line in (rd("/proc/vmstat", "") or "").splitlines():
        k, _, v = line.partition(" ")
        if k in ("pgmajfault", "oom_kill"):
            d[k] = int(v)
    return d


def meminfo():
    d = {}
    for line in (rd("/proc/meminfo", "") or "").splitlines():
        k, _, v = line.partition(":")
        d[k] = int(v.split()[0]) // 1024 if v.split() else 0
    return d


def tree_rss(root):
    """MB of RSS for root and its descendants, and how many are Ghidra decompiler processes."""
    kids, info = {}, {}
    for st in glob.glob("/proc/[0-9]*/stat"):
        s = rd(st)
        if not s:
            continue
        pid = int(st.split("/")[2])
        comm = s[s.index("(") + 1:s.rindex(")")]
        rest = s[s.rindex(")") + 2:].split()
        kids.setdefault(int(rest[1]), []).append(pid)
        info[pid] = (comm, int(rest[21]) * os.sysconf("SC_PAGE_SIZE") // 1048576)
    total = dec = 0
    todo = [root]
    while todo:
        p = todo.pop()
        if p in info:
            total += info[p][1]
            dec += info[p][0].startswith("decompile")
        todo += kids.get(p, [])
    return total, dec


KERN = re.compile(r"oom|out of memory|hung_task|blocked for more than|throttl|mce|machine check|"
                  r"i/o error|nvme.*(timeout|reset)|soft lockup|rcu.*stall", re.I)


def kernel_lines(seen):
    try:
        r = subprocess.run(["dmesg"], capture_output=True, text=True, timeout=5)
    except (OSError, subprocess.TimeoutExpired):
        return seen, []
    lines = r.stdout.splitlines()
    if not lines:
        return seen, []
    # the ring buffer rotates, so find the last line seen instead of counting lines
    new = []
    if seen is not None:
        idx = len(lines) - 1 - lines[::-1].index(seen) if seen in lines else -1
        new = lines[idx + 1:]
    return lines[-1], [l for l in new if KERN.search(l)]


def syslog_sender(spec):
    """Return send(msg, warn) for RFC 3164 UDP syslog to host[:port], or None when turned off."""
    if not spec or spec == "0":
        return None
    host, _, port = spec.partition(":")
    try:
        addr = socket.getaddrinfo(host, int(port or 514), type=socket.SOCK_DGRAM)[0]
        sock = socket.socket(addr[0], socket.SOCK_DGRAM)
    except (OSError, ValueError):
        return None
    me, tag = socket.gethostname(), f"ft710-health[{os.getpid()}]"

    def send(msg, warn):
        pri = 16 * 8 + (4 if warn else 6)  # local0.warning / local0.info
        line = f"<{pri}>{time.strftime('%b %e %H:%M:%S')} {me} {tag}: {msg}"
        try:
            sock.sendto(line.encode()[:8000], addr[4])
        except OSError:
            pass  # the network may be what is failing; the local file still has the line
    return send


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--watch", type=int)
    ap.add_argument("--label", default="")
    ap.add_argument("--interval", type=float, default=float(os.environ.get("HEALTH_INTERVAL", 10)))
    ap.add_argument("--dir", default=os.environ.get("HEALTH_DIR", os.path.expanduser("~/.cache/ft710-health")))
    a = ap.parse_args()
    os.makedirs(a.dir, exist_ok=True)

    latest = os.path.join(a.dir, "health-latest.log")
    prev = os.path.realpath(latest) if os.path.islink(latest) else None
    path = os.path.join(a.dir, time.strftime("health-%Y%m%dT%H%M%SZ", time.gmtime()) + f"-{os.getpid()}.log")
    f = open(path, "a")
    try:
        os.unlink(latest)
    except OSError:
        pass
    try:
        os.symlink(os.path.basename(path), latest)
    except OSError:
        pass

    send = syslog_sender(os.environ.get("HEALTH_SYSLOG", "192.168.10.50:514"))

    def log(msg):
        f.write(time.strftime("%Y-%m-%dT%H:%M:%S%z ") + msg + "\n")
        f.flush()
        os.fsync(f.fileno())
        if send:
            send(msg, msg.split(" ", 1)[0] in ("GAP", "WARN", "KERNEL"))

    log(f"START watch={a.watch} label={a.label!r} interval={a.interval}s nproc={os.cpu_count()}")
    if prev and os.path.exists(prev):
        tail = (rd(prev, "") or "").splitlines()[-1:]
        if tail and " END " not in tail[0]:
            log(f"WARN previous run {os.path.basename(prev)} has no END line; last sample: {tail[0]}")

    seen, _ = kernel_lines(None)
    c0, v0, t0 = cpustat(), vmstat(), throttle_total()
    last = time.monotonic()
    while True:
        time.sleep(a.interval)
        now = time.monotonic()
        dt = now - last
        last = now
        if dt > 3 * a.interval:
            log(f"GAP sampler stalled {dt:.0f}s (expected {a.interval:.0f}s)")
        if a.watch and not os.path.exists(f"/proc/{a.watch}"):
            log(f"END job {a.watch} exited")
            return

        c1, v1, t1 = cpustat(), vmstat(), throttle_total()
        d = [y - x for x, y in zip(c0, c1)] or [0]
        tot = sum(d) or 1
        iowait = 100 * d[4] / tot if len(d) > 4 else 0
        steal = 100 * d[7] / tot if len(d) > 7 else 0
        m = meminfo()
        la = (rd("/proc/loadavg", "0 0 0 0/0") or "").split()
        fields = temps_fans() + gpu() + cpufreq() + [
            f"thr={t1 - t0}",
            f"load={la[0]}", f"run={la[3].split('/')[0]}",
            f"iowait={iowait:.0f}%", f"steal={steal:.0f}%",
            f"avail={m.get('MemAvailable', 0)}", f"free={m.get('MemFree', 0)}", f"dirty={m.get('Dirty', 0)}",
            f"wback={m.get('Writeback', 0)}", f"shmem={m.get('Shmem', 0)}",
        ]
        cg = rd("/sys/fs/cgroup/memory.current")
        if cg and cg.isdigit():
            fields.append(f"cg={int(cg) // 1048576}")
        fields += [f"majflt/s={(v1.get('pgmajfault', 0) - v0.get('pgmajfault', 0)) / dt:.0f}",
                   f"oom={v1.get('oom_kill', 0) - v0.get('oom_kill', 0)}"]
        if a.watch:
            rss, dec = tree_rss(a.watch)
            fields += [f"job_rss={rss}", f"dec={dec}"]
        log(" ".join(fields))
        seen, klines = kernel_lines(seen)
        for kl in klines:
            log("KERNEL " + kl)
        c0, v0, t0 = c1, v1, t1


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
