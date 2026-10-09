#!/usr/bin/env python3
"""Mirror docs/tasks/ into GitHub issues (one epic + one issue per task).

Usage: python3 -I tools/issues_sync.py [--dry-run]

- Source of truth stays local: docs/tasks/README.md (board) + docs/tasks/T*.md.
- Each task gets an issue titled "Txx: <title>", with a body built from the task file
  (Goal, Deliverables, Status, Findings, Follow-ups), a status label, and the
  "Depends on" field linked to issue numbers.
- Sub-tasks (T10a, T10b, ...) become GitHub sub-issues of their parent (T10);
  top-level tasks become sub-issues of the epic.
- A status change posts a comment (with the current HEAD commit) and closes or reopens
  the issue. Done tasks are closed.
- The issue numbers are stored in docs/tasks/issues.json. Commit that file.
Requires the gh CLI, authenticated, inside the repo. Refuses to run unless the repo is private.
"""
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TASKS = os.path.join(ROOT, "docs", "tasks")
MAP_FILE = os.path.join(TASKS, "issues.json")
MARK = "<!-- synced by tools/issues_sync.py; edit docs/tasks/ instead -->"
STATUSES = {
    "todo": ("status:todo", "ededed"),
    "in-progress": ("status:in-progress", "fbca04"),
    "blocked": ("status:blocked", "d93f0b"),
    "done": ("status:done", "0e8a16"),
}
EXTRA_LABELS = {"type:epic": "5319e7", "type:task": "1d76db"}
DRY = "--dry-run" in sys.argv


def gh(*args, input=None, check=True):
    if DRY and args[0] in ("issue", "label") and args[1] in ("create", "edit", "close", "reopen", "comment"):
        print("DRY gh", " ".join(args[:3]))
        return ""
    r = subprocess.run(["gh", *args], cwd=ROOT, input=input, capture_output=True, text=True, timeout=120)
    if check and r.returncode != 0:
        raise RuntimeError(f"gh {' '.join(args[:4])} failed: {r.stderr.strip()}")
    return r.stdout


def norm_status(s):
    s = s.lower()
    if "done" in s:
        return "done"
    if "blocked" in s or "partial" in s:
        return "blocked"
    if "progress" in s:
        return "in-progress"
    return "todo"


def parse_board():
    rows = []
    for line in open(os.path.join(TASKS, "README.md"), encoding="utf-8"):
        m = re.match(r"\|\s*(T\d+[a-z]?)\s*\|\s*\[(.+?)\]\((.+?)\)\s*\|\s*(.*?)\s*\|\s*(.*?)\s*\|", line)
        if m:
            tid, title, path, deps, status = m.groups()
            rows.append({"id": tid, "title": title, "file": path, "deps": re.findall(r"T\d+[a-z]?", deps),
                         "dep_range": deps, "status_text": status, "status": norm_status(status)})
    return rows


def sections(path):
    text = open(os.path.join(TASKS, path), encoding="utf-8").read()
    out, cur = {}, None
    for line in text.splitlines():
        h = re.match(r"##\s+(.*)", line)
        if h:
            cur = h.group(1).strip()
            out[cur] = []
        elif cur:
            out[cur].append(line)
    return {k: "\n".join(v).strip() for k, v in out.items()}


def blob(path):
    return f"https://github.com/{REPO}/blob/main/docs/tasks/{path}"


def task_body(row, issue_of):
    sec = sections(row["file"])
    deps = ", ".join(f"#{issue_of[d]} ({d})" if d in issue_of else d for d in row["deps"]) or "—"
    parts = [MARK, f"**Task {row['id']}** · local file: [{row['file']}]({blob(row['file'])})",
             f"**Status:** {row['status_text']} · **Depends on:** {deps}"]
    for name in ("Goal", "Deliverables", "Findings", "Follow-ups"):
        body = sec.get(name, "")
        if body and not body.startswith("_(fill in"):
            parts.append(f"## {name}\n{body}")
    text = "\n\n".join(parts)
    return text if len(text) < 60000 else text[:60000] + f"\n\n… (truncated; see [{row['file']}]({blob(row['file'])}))"


def epic_body(rows, issue_of):
    done = sum(r["status"] == "done" for r in rows)
    lines = [MARK, "Epic tracking the FT-710 firmware analysis. The local board is "
             f"[docs/tasks/README.md]({blob('README.md')}); rules are in AGENTS.md.",
             f"**Progress:** {done}/{len(rows)} tasks done.", "",
             "| Task | Issue | Status |", "|---|---|---|"]
    for r in rows:
        lines.append(f"| {r['id']} {r['title']} | #{issue_of.get(r['id'], '?')} | {r['status_text']} |")
    return "\n".join(lines)


def ensure_labels():
    have = set(gh("label", "list", "--limit", "200", "--json", "name", "--jq", ".[].name").split())
    for name, color in [*STATUSES.values(), *EXTRA_LABELS.items()]:
        if name not in have:
            gh("label", "create", name, "--color", color)


def issue_state(num):
    j = json.loads(gh("issue", "view", str(num), "--json", "state,labels,body"))
    return j["state"], {l["name"] for l in j["labels"]}, j["body"]


def set_issue(num, title, body, status, labels_now, state):
    want = STATUSES[status][0]
    args = ["issue", "edit", str(num), "--title", title, "--body-file", "-"]
    for lab in labels_now:
        if lab.startswith("status:") and lab != want:
            args += ["--remove-label", lab]
    if want not in labels_now:
        args += ["--add-label", want]
    gh(*args, input=body)
    if status == "done" and state == "OPEN":
        gh("issue", "close", str(num), "--reason", "completed")
    elif status != "done" and state == "CLOSED":
        gh("issue", "reopen", str(num))


def rest_id(num):
    return gh("api", f"repos/{REPO}/issues/{num}", "--jq", ".id").strip()


def ensure_sub(parent, child):
    have = gh("api", f"repos/{REPO}/issues/{parent}/sub_issues", "--paginate", "--jq", ".[].number").split()
    if str(child) in have:
        return
    if DRY:
        print(f"DRY sub-issue #{child} -> #{parent}")
        return
    r = subprocess.run(["gh", "api", "-X", "POST", f"repos/{REPO}/issues/{parent}/sub_issues",
                        "-F", f"sub_issue_id={rest_id(child)}", "-F", "replace_parent=true"],
                       cwd=ROOT, capture_output=True, text=True, timeout=120)
    if r.returncode != 0:
        print(f"warn: sub-issue #{child} -> #{parent}: {r.stderr.strip()}", file=sys.stderr)


def main():
    global REPO
    info = json.loads(gh("repo", "view", "--json", "nameWithOwner,isPrivate"))
    if not info["isPrivate"]:
        sys.exit("refusing: repo is not private")
    REPO = info["nameWithOwner"]
    head = subprocess.run(["git", "rev-parse", "--short", "HEAD"], cwd=ROOT, capture_output=True,
                          text=True).stdout.strip()
    rows = parse_board()
    mapping = json.load(open(MAP_FILE)) if os.path.exists(MAP_FILE) else {}
    issue_of = {k: v for k, v in mapping.items() if k != "_status"}
    last = mapping.get("_status", {})
    ensure_labels()

    if "EPIC" not in issue_of:
        url = gh("issue", "create", "--title", "FT-710 firmware analysis (epic)", "--label", "type:epic",
                 "--body", MARK)
        issue_of["EPIC"] = int(url.strip().rsplit("/", 1)[-1]) if not DRY else 0
    for r in rows:  # create missing issues first so dependencies can link
        if r["id"] not in issue_of:
            url = gh("issue", "create", "--title", f"{r['id']}: {r['title']}", "--label", "type:task",
                     "--label", STATUSES[r["status"]][0], "--body", MARK)
            issue_of[r["id"]] = int(url.strip().rsplit("/", 1)[-1]) if not DRY else 0
            print(f"created #{issue_of[r['id']]} for {r['id']}")
    if DRY:
        return
    for r in rows:
        num = issue_of[r["id"]]
        state, labels, _ = issue_state(num)
        set_issue(num, f"{r['id']}: {r['title']}", task_body(r, issue_of), r["status"], labels, state)
        if last.get(r["id"]) and last[r["id"]] != r["status"]:
            gh("issue", "comment", str(num), "--body",
               f"Status: **{last[r['id']]} → {r['status']}** ({r['status_text']}) at commit `{head}`. "
               f"Details: [{r['file']}]({blob(r['file'])}).")
        last[r["id"]] = r["status"]
        parent = re.match(r"(T\d+)[a-z]$", r["id"])
        ensure_sub(issue_of[parent.group(1)] if parent and parent.group(1) in issue_of else issue_of["EPIC"], num)
    estate, elabels, _ = issue_state(issue_of["EPIC"])
    set_issue(issue_of["EPIC"], "FT-710 firmware analysis (epic)", epic_body(rows, issue_of),
              "done" if all(r["status"] == "done" for r in rows) else "in-progress", elabels, estate)
    with open(MAP_FILE, "w") as fh:
        json.dump({**issue_of, "_status": last}, fh, indent=1, sort_keys=True)
        fh.write("\n")
    print(f"synced {len(rows)} tasks + epic #{issue_of['EPIC']} in {REPO}")


if __name__ == "__main__":
    main()
