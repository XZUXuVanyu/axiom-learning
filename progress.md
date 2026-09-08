# Current progress

Updated: 2026-09-08
Main lesson: C002 — From a physical equation to an executable state model
Active unit: derive state evolution from displacement and velocity
Record: lessons/C002-physical-state-model.md
Mastery status: attempted (opening conceptual answer only)
Execution state: paused at session boundary; ready to resume
Implementation: not attempted

## Current direction

C++ is primary; TypeScript remains deferred. Follow AGENTS.md and long-term/resume.md. The learner owns crucial derivation, implementation, validation, predictions, and explanations; the tutor reviews and documents evidence.

Current emphasis: physics/math-to-code, following C001's completed structure objective under long-term/weekly-plan.md. This is a study-block transition, not an inference about elapsed weeks or study hours.

## C002 checkpoint

Model: m x'' + b x' + k x = 0, with m > 0, b >= 0, k > 0; constant parameters, linear restoring force, viscous damping, no external driving, displacement measured from equilibrium.

Objective: express this second-order law as a first-order state evolution and implement the instantaneous rate calculation. Time integration and audio/integration infrastructure come later.

The learner correctly answered that displacement alone is insufficient and additional velocity information is needed. Evidence: conversation response on 2026-09-08. The tutor confirmed this for the specified model and parameters.

No derivation, C002 implementation, execution evidence, or transfer exercise has yet been supplied. C002 is not demonstrated.

## One next action

Ask: Taking displacement and velocity as the state, how would you express the time derivative of each component using the given equation?

Resume from the accepted state choice. Do not repeat the opening question. Teach a bounded prerequisite if needed, leaving crucial work to the learner.

## Completed work and remaining cleanup

- C001: demonstrated; final learner source 023b38dd47aeab64cbf79ced0935f7160bc8e0fc, closure commit 8d30628eb744f8c6b50ace58be4716351e0c3ab4. See lessons/C001-tool-contract.md.
- P-CXX-001 U1–U4: recorded as demonstrated; see lessons/P-CXX-001-inheritance-polymorphism.md.
- C001 execution evidence is learner-reported MSVC output/screenshots, not assistant-run.
- Reproducibility cleanup remains: uncommitted unused output.h dependency and missing direct standard-header dependencies. No source was changed in this planning session.
- The committed main's positive overflow throws before its negative-overflow call; the latter needs separate execution. Earlier records report separate negative rejection evidence.
- A base-wide ErrorKind remains deferred until a concrete second error family needs it.
- C001 retention check: after two or three subsequent completed sessions.

## Preserved TypeScript checkpoint

L001 is deferred, not completed. See lessons/L001-runtime-validation.md.
P01 and P02 have bounded checks recorded; P03's bigint transfer case still needs reconciliation with actual source/output. The parent runtime validator was not attempted. If TypeScript resumes, inspect the latest learner evidence before reassessment.

## History and continuity

The previous progress.md is preserved verbatim in reviews/2026-09-08-progress-before-c002.md as historical context, including failed attempts and superseded next actions. Use this file for the current checkpoint and the individual lesson records for evidence.

Long-term policy remains unchanged. Daily review follows long-term/commit-review.md and reviews/commit-check-state.json; this user-requested lesson documentation commit does not establish implementation progress or change the checker baseline.
