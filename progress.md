# Current progress

Updated: 2026-09-06
Main lesson: C001 — A C++ tool's behavior and contract
Active unit: C001 opening feature-contract discussion
Record: lessons/C001-tool-contract.md
Mastery status: not attempted
Execution state: active; awaiting learner design

## Current decision

C++ is primary; TypeScript is deferred. Focus on Axiom's features, logic, contracts, and failure behavior. Teach language details when needed. The learner implements crucial code; documented evidence and bounded prerequisites remain required.

## Next action

In the new conversation, read the agreement and C001. Ask its opening question about successful versus failed tool calls. Review the learner's answer before selecting the smallest coding step. Do not start with a broad C++ syntax test or supply the implementation.

## Preserved TypeScript evidence

L001 is deferred, not completed. Its full chronological record remains in lessons/L001-runtime-validation.md.

| Skill | Recorded evidence/status |
|---|---|
| Static types versus runtime values | P01 bounded check met; learner explanation recorded in L001. |
| Basic values and object properties | P02 bounded check met; classifications and property reasoning recorded. |
| Conditions and runtime checks | P03 revision needed at the latest repository checkpoint: bigint transfer case. |
| Parent runtime validator | Implementation not attempted. |
| C++ feature implementation | Not attempted in this course; toolchain unverified. |

P03 was implemented in an external Visual Studio TypeScript project. Learner-reported execution and screenshots are recorded in L001; source is not stored here. Later conversation reports include a bigint prediction, but this update does not establish a verified final correction. If TS resumes, inspect current source and actual output before reassessment.

Initial environment inspection recorded Node.js v24.19.0 and npm v11.17.0, blocked PowerShell shims, working npm.cmd, no tsc in the inspected path, and an npx.cmd EPERM failure that installed nothing. These are historical observations; later L001 screenshots reported TypeScript execution elsewhere. No environment commands were rerun for this update.

## Deferred return point

If TypeScript is resumed: reconcile P03's bigint case with the latest learner code/output, then return to L001 question 1. This is not a blocker for C001. Preserve prior failures and evidence.

## Pending decisions

- C++ compiler/build environment and minimum standard, chosen from the learner's actual setup.
- Smallest result/error representation after the learner specifies behavior.
- JSON and MCP dependencies, evaluated when needed.
- Native IDE extension target and technology, later.

## Continuation instructions

Read AGENTS.md, learning-agreement.md, program-context.md, this file, and C001. Ask one question at a time. Record predictions, attempts, actual results, hints, gaps, and one next action. No current prerequisite is active; create one only for a concrete blocker. Retention checks follow demonstrated work after two or three subsequent sessions.
