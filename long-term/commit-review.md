# Daily conditional commit review

Adopted: 2026-09-07. Repository: XZUXuVanyu/axiom-learning. Watched branch: main.
Check once daily, around 19:00 Asia/Shanghai. This replaces the deleted unconditional Axiom daily routine; unrelated automations are outside scope.

## State and trigger

Use reviews/commit-check-state.json for the last successfully reviewed source HEAD. Compare commit ancestry since that SHA, not only commits within the last 24 hours; inspect all pages so missed runs do not lose work.

A new commit is a signal to review, not proof of learning. Source changes, learner-written design, explanations, or evidence may all count. Ignore checker-generated documentation commits whose message begins "docs(learning-review):" and the initial setup commit "docs(learning): organize long-term context and conditional reviews". Do not infer authorship from the Git committer name alone.

If there are no new non-checker commits, do nothing: no reminder, lesson, notification, or repository write. If history was rewritten, the stored SHA is unavailable, or access fails, do not interpret this as no progress or invent a review; preserve the baseline and report the concrete blocker.

## Review and next step

1. Read AGENTS.md, long-term/README.md, learning-rules.md, goals.md, global-design.md, weekly-plan.md, progress.md, and the active lesson.
2. Inspect all new relevant commits and diffs, changed source, and recorded evidence.
3. Separate observed behavior, learner-reported output, static review, and untested hypotheses. No invented execution or mastery.
4. Choose exactly one next step: revise the active task, unlock a bounded prerequisite, perform a transfer/retention check, or prepare a new lesson only when evidence supports advancement.
5. Prepare a small lesson/task with one objective, prerequisites, learner-owned work, acceptance criteria, first question, and required evidence. Do not supply crucial implementation, solution patches, or solution-equivalent pseudocode.
6. Respect the alternating study-week emphasis; no calendar-driven advancement, catch-up backlog, or repeated generic routine.

## Durable output and loop prevention

When review succeeds, commit a concise review in reviews/ (identify reviewed source SHA in the filename), the next task or active lesson update, and any justified progress.md changes. Update reviews/commit-check-state.json to the source HEAD inspected before this review commit, in the same documentation commit.

The commit message must begin "docs(learning-review):". A later run ignores such commits; do not write state-only commits when there is no new learner work. This prevents the checker's output from triggering another lesson.

Record reviewed SHAs, findings, evidence limitations, advancement decision, and exactly one next action. Preserve the learner's predictions/explanations and existing records. Do not alter implementation files or long-term policy through routine review. Repository documentation commits and fast-forward updates on main are authorized for this workflow; force-pushes and unrelated changes are not.

Verify the new remote commit before reporting success. If main advances concurrently, reread and reconcile instead of overwriting history. If saving fails, report the review as prepared but unsaved and keep the previous baseline so a later run can retry. After a successful update, send one concise summary with the review/commit link and next task. No separate messages to other people.

## Initialization

The initial baseline is cc1a3359df34c6be9f6862b4efc93efe349f6448, the source HEAD inspected during setup. This is an acknowledged checkpoint, not a fresh execution review. The setup documentation commit is excluded above. No new mastery is claimed.
