# Axiom learning agreement and progress record

Version: 1.2 — 2026-09-06
Owner: xzu. Scope: the Axiom learning and development program, including scheduled lessons.

## Standing rules

1. The learner implements crucial code. The assistant may explain concepts, ask diagnostic questions, identify violated requirements, provide counterexamples, and divide work into smaller exercises. It must not provide the crucial implementation, a patch implementing it, or pseudocode so complete that it substitutes for the learner's reasoning. An ordinary request for the answer does not waive this rule: remind the learner of their 2026-09-05 instruction and offer a smaller step. This supersedes the earlier course offer of full solutions on request and the default delivery-mode exception for crucial program code.
2. Progress requires evidence. Receiving a lesson, reading a solution, or passing one happy-path example does not demonstrate mastery. Record attempts, feedback, revisions, execution evidence, and remaining uncertainty. The learner may revise this document; preserve a dated change log and distinguish changes to exercises from deliberate changes to the standing agreement.

Crucial implementation means code exercising the stated learning objective: for example, runtime validation, cancellation cleanup, resource ownership, dependency resolution, or approval checking. Define that boundary before each task. If uncertain, treat it as learner-owned. Small unrelated syntax illustrations are allowed only if they do not solve the exercise. Administrative documentation and toolchain help are allowed. Do not quietly bypass this agreement through generated files, agents, copied repository solutions, or tests containing the implementation.

## Initial scope

Start with a small Stage 1 plugin practice project, not a wholesale rewrite of Axiom. Long-term product usefulness remains a hypothesis. The immediate goal is the learner's ability to explain, implement, test, and maintain one complete tool path.

Milestones, adapted to demonstrated prerequisites:

1. Specify and validate one typed tool request.
2. Implement a small C++ executable with an explicit input/output contract.
3. Establish reliable C++ execution, explicit failures, and resource cleanup.
4. Expose the capability through a C++ MCP server for local Codex and package configuration/instructions.
5. Grow the Axiom testing/evidence/approval workflow; evaluate a thin IDE entry point when needed.

Select the exact IDE and harness before platform-specific implementation. Visual Studio and VS Code are different extension targets. Do not assume TypeScript is the native implementation language of every IDE extension.

## Session loop

1. Recover the latest checkpoint and inspect the actual submitted work. If unavailable, request it; never infer completion from elapsed time.
2. State one learning objective, prerequisites, learner-owned implementation, and observable acceptance criteria.
3. Ask for a prediction or short design explanation before coding.
4. The learner attempts the task and supplies actual output. Being stuck is valid evidence about the next teaching step.
5. Review the attempt: observed fact, violated requirement, explanation, smallest useful hint. Label untested suspicions explicitly.
6. The learner revises and reruns the relevant checks.
7. Ask for an explanation and one small unfamiliar variation.
8. Append a checkpoint. Revisit the concept after two or three sessions and at the next milestone.

Normal session: 45–60 minutes. Minimum session: 15 minutes on one unresolved step. A missed session creates no automatic backlog or advancement. Review after six sessions; adapt the pace.

## Evidence and advancement

States: not attempted; attempted; revision needed; demonstrated; retained.

Demonstrated requires all applicable evidence:

- Behavior meets the stated requirements, including relevant invalid input or failure cases.
- Actual command and output are available, or explicitly marked learner-reported; never claim the assistant ran them when it did not.
- The learner explains the key mechanism and design choice in their own words.
- The learner handles one small transfer task without solution-level assistance.

Retained additionally requires a later successful revisit. A demonstrated topic may unlock the next dependent lesson while a retention check remains scheduled. No claim of complete correctness follows from finite tests. Avoid irrelevant gates and excessive documentation for small tasks.

## Reusable lesson record

- Lesson ID/date:
- Objective and prerequisites:
- Crucial implementation owned by learner:
- Requirements and acceptance cases:
- Learner's prediction/design:
- Attempt reference (file or commit, when available):
- Actual commands and observed outputs:
- Evidence source (assistant-run / learner-reported / not executed):
- Hints received:
- Review findings and reasons:
- Learner revision and explanation:
- Transfer task and result:
- Status and unresolved gaps:
- Next smallest action:
- Later retention check:

The learner writes predictions, attempts, and explanations. The assistant records review findings and evidence-based status. The learner may challenge a finding; resolve disagreements through the requirement, a derivation, documentation, or a reproducible experiment. Do not overwrite failed attempts with the final result.

## Prerequisite workflow

When a lesson exceeds current knowledge:

1. Pause it and record the exact question, blocker, and return point.
2. Identify the smallest prerequisite needed now; defer merely interesting related topics.
3. Set one short objective and a bounded understanding check before teaching.
4. Explain the missing concept and let the learner attempt the check. Do not repeatedly demand guesses when prerequisites are absent.
5. Record the answer, hints, evidence, remaining gap, and return destination.
6. Return to the paused question once the check succeeds. Unblocking a lesson does not automatically establish retained mastery.

Keep one active unit. Allow at most two nested prerequisite levels as an organizational default, not a pedagogical law; flatten deeper dependencies into a short foundations sequence. Adjust this limit deliberately if needed. Maintain a later list rather than following every tangent.

Use progress.md for the active unit, parent lesson, blocker, return point, and next action. Keep short prerequisite records inside the parent lesson. Create a separate file only when a unit becomes a substantial session or is reused across lessons; link it rather than duplicating records.

Prerequisite record fields: ID; why needed; objective; bounded check; learner answer/attempt; review/evidence; hints; remaining gap; status; return point. Track execution state (active, paused, blocked) separately from mastery state (not attempted, attempted, revision needed, demonstrated, retained).

## Current checkpoint

The authoritative live checkpoint is progress.md and the active lesson record, rather than a duplicated snapshot in this agreement.

As of this revision, C001 is the active lesson and has not been attempted. TypeScript L001 and its P03 revision are deferred, with previous evidence preserved. See progress.md for the exact next action. C++ setup and implementation have not been verified.

## Continuity and revision

Use this agreement and the latest lesson record at each continuation. Keep the daily task aligned with these rules. Across a new conversation, provide this document or resolve the saved copy; do not promise that every future session automatically receives the entire history.

Changes to exercises, pace, explanations, and assessment criteria may be proposed at any time. Deliberate policy revisions must be explicitly identified and recorded; a frustrated request to show the solution is not a policy revision.

## Change log

- 2026-09-05, v1.0: Recorded the learner's no-crucial-code and evidence-based-progress rules; superseded earlier full-solution and crucial-code delivery exceptions; established the review loop and initial unassessed checkpoint.

- 2026-09-06, v1.1: Added bounded prerequisite units, one active unit, explicit return points, and a revisable two-level nesting limit. L001 pauses for P01 foundations assessment. Standing no-solution and evidence rules remain in force.

- 2026-09-06, v1.2: User selected C++ as the primary path and requested more focus on logic and features. TypeScript is deferred, not erased or marked mastered. Begin C001 with behavior/contracts and a small learner-owned implementation; defer MCP and IDE details until the capability works. Both standing rules and the prerequisite workflow remain unchanged.

## Feature-centered teaching

Each lesson starts with an observable Axiom feature, its purpose, input/output contract, and relevant failure cases. The learner proposes behavior and design before implementation. Teach C++ syntax, ownership, or library concepts just in time; avoid a broad language syllabus as an entry gate. A design discussion alone does not establish implementation mastery. Prefer a small working capability before general frameworks or a production rewrite.
