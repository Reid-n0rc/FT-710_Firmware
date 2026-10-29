#!/usr/bin/env python3
"""Memory-based admission for Ghidra/REA runs: start as many as RAM allows, no fixed slot count.

Usage: python3 -I tools/memgate.py <reserve_mb> -- <command...>
State (reservations, mutex) lives in $MEMGATE_DIR (default ~/.cache/ft710-memgate); all agents must share it.
A run is admitted when MemAvailable - (memory already-admitted runs may still grow into) - reserve >= SAFETY_MB.
"Still grow into" = sum over live runs of max(0, reserve - current RSS of that run's process tree).
"""
import fcntl, os, signal, subprocess, sys, time

SP = os.environ.get("MEMGATE_DIR", os.path.expanduser("~/.cache/ft710-memgate"))
RES = os.path.join(SP, "res")
MUTEX = os.path.join(SP, "memgate.lock")
SAFETY_MB = int(os.environ.get("MEMGATE_SAFETY_MB", "3072"))


def meminfo_avail_mb():
    with open("/proc/meminfo") as f:
        for line in f:
            if line.startswith("MemAvailable:"):
                return int(line.split()[1]) // 1024
    return 0


def proc_table():
    kids, rss = {}, {}
    for d in os.listdir("/proc"):
        if not d.isdigit():
            continue
        try:
            with open(f"/proc/{d}/stat") as f:
                st = f.read().rsplit(")", 1)[1].split()
            ppid, r = int(st[1]), int(st[21]) * os.sysconf("SC_PAGE_SIZE") // (1 << 20)
        except (OSError, IndexError, ValueError):
            continue
        kids.setdefault(ppid, []).append(int(d))
        rss[int(d)] = r
    return kids, rss


def tree_rss(pid, kids, rss):
    tot, stack = 0, [pid]
    while stack:
        p = stack.pop()
        tot += rss.get(p, 0)
        stack.extend(kids.get(p, []))
    return tot


def committed_mb():
    kids, rss = proc_table()
    tot = 0
    for name in os.listdir(RES):
        pid = int(name)
        if pid not in rss:
            os.unlink(os.path.join(RES, name))
            continue
        with open(os.path.join(RES, name)) as f:
            reserve = int(f.read().strip() or 0)
        tot += max(0, reserve - tree_rss(pid, kids, rss))
    return tot


def main():
    reserve = int(sys.argv[1])
    cmd = sys.argv[sys.argv.index("--") + 1:]
    os.makedirs(RES, exist_ok=True)
    waited = 0
    while True:
        with open(MUTEX, "w") as m:
            fcntl.flock(m, fcntl.LOCK_EX)
            avail, comm = meminfo_avail_mb(), committed_mb()
            if avail - comm - reserve >= SAFETY_MB:
                with open(os.path.join(RES, str(os.getpid())), "w") as f:
                    f.write(str(reserve))
                break
        if waited % 120 == 0:
            print(f"memgate: waiting (avail {avail} MB, committed {comm} MB, need {reserve}+{SAFETY_MB} MB)",
                  file=sys.stderr, flush=True)
        time.sleep(10)
        waited += 10
    child = subprocess.Popen(cmd)
    for s in (signal.SIGTERM, signal.SIGINT, signal.SIGHUP):
        signal.signal(s, lambda n, _f: child.send_signal(n))
    rc = child.wait()
    try:
        os.unlink(os.path.join(RES, str(os.getpid())))
    except OSError:
        pass
    sys.exit(rc)


if __name__ == "__main__":
    main()
