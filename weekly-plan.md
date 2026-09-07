# Alternating-week learning plan

Adopted: 2026-09-07. Trial: four study weeks, then review.
This changes scheduling and project emphasis, not the standing implementation or evidence rules.

## Shared project and sequence

Use one evolving C++ project across both kinds of week. Start from the current C001 checkpoint; move toward an offline physical-audio tool before a VST or broader Axiom platform.

| Week | Emphasis | Intended outcome |
|---|---|---|
| 1 | Software structure | Finish C001's bounded contract and failure behavior; produce a working component with documented boundaries. |
| 2 | Physics/math to code | A small physical-model prototype with stated assumptions, units, and independent reference checks. |
| 3 | Structure and integration | Wrap the prototype with parameter input, execution, output, and reproducibility as a reusable standalone tool. |
| 4 | Physics and validation | Investigate parameter dependence, numerical error, and model limitations; produce a useful, supported result. |

These are planning targets, not completion claims or fixed deadlines. Week 1 is the next study block; exact calendar dates and actual study hours are not yet recorded. Missed days do not automatically advance work.

A damped oscillator is the proposed first physics exercise because analytical behavior can supply an independent reference. It is a stepping stone toward bubble sound, not an already validated bubble model. Select the exact physical question and bounded objective before implementing. General water sound and a DAW instrument remain later goals.

## Physics/math-to-code reasoning

1. Define the physical question and observable.
2. State assumptions, units, and intended domain.
3. Identify variables, parameters, equations, and initial conditions.
4. Choose a numerical representation and identify introduced approximations.
5. Predict a reference or limiting case before coding.
6. Implement, compare actual results, and explain discrepancies.

Assess separately whether the physical equations apply, whether the numerical method is suitable, and whether the code implements that method correctly. Plausible sound alone does not validate the physics.

## Operating rules

- Alternate emphasis, not rigid subject boundaries. Learn necessary C++ during a physics week and use the model during a structure week.
- Keep one active task. Use the existing bounded prerequisite workflow and a later list.
- End each week with a checkpoint. Preserve unfinished status and an explicit return point. Carry over a blocker only when it genuinely prevents the next task; otherwise record it and switch emphasis.
- Every structure task must serve the next experiment. Avoid general infrastructure until an observed need justifies it.
- The learner retains crucial implementation, numerical-method choices, validation logic, and relevant learning checks. The assistant explains, decomposes, reviews, and documents evidence without supplying the crucial solution.
- This plan does not authorize broader production implementation by agents or revise the no-crucial-code agreement.
- Retention checks remain due after two or three subsequent sessions, irrespective of week boundaries.

## Compact weekly record

Append one weekly block to the active lesson and link it from progress.md; do not duplicate the full lesson history.

- Week number, actual dates, emphasis, and shared project:
- Bounded objective and learner-owned work:
- Learner prediction/design:
- Attempt/commit references and actual commands/output, with evidence source:
- Hints, review findings, and revisions:
- Learner explanation and transfer/retention evidence:
- Status, unresolved gap, and exact return point:
- One next action:

Leave the learner's prediction and explanation for the learner. No implementation or new mastery is established by adopting this plan.

## Four-week review

Review whether the learner can explain and reuse the work, whether it produces useful output, and whether structural work enables experiments. Compare actual study effort and recurring blockers; revise scope or cadence rather than count topics or infer progress from elapsed time.
