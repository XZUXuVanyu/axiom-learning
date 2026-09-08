# C002 — From a physical equation to an executable state model

Date: 2026-09-08
Mastery status: attempted (opening conceptual question only)
Execution state: paused at session boundary; ready to resume
Implementation: not attempted
Normal budget: 45–60 minutes, with bounded prerequisites if needed.

## Objective and purpose

Express a second-order physical law as a first-order state evolution suitable for computation. Given physical parameters and the instantaneous state, calculate the state's instantaneous rate of change.

This starts the physics/math-to-code emphasis of long-term/weekly-plan.md after C001's bounded structure objective. It is not a claim that a calendar week has elapsed. The oscillator is a stepping stone toward physical audio, not a validated bubble-acoustics model.

## Physical model and scope

Use a freely moving, linearly damped mass–spring system:

m x'' + b x' + k x = 0, with m > 0, b >= 0, k > 0.

Displacement x is measured from equilibrium. Assume constant parameters, a linear restoring force, viscous damping, and no external driving. The learner will identify all SI units and define the numerical input domain and failure contract.

Time integration, audio output, JSON/MCP, and general framework design are outside C002.

## Learner-owned work

The learner chooses the state representation, derives its evolution, implements the rate calculation and parameter checks, and writes relevant checks. Predictions, numerical reference values, and the final explanation belong to the learner.

The tutor explains missing prerequisites, reviews dimensions and logic, and gives progressively smaller hints. Do not supply crucial implementation, a finished architecture, or solution-equivalent pseudocode. Keep one focused question active.

## Acceptance criteria

- Every parameter and state component has an explicit physical meaning and SI unit.
- The state contains enough information to determine its instantaneous evolution for the specified parameters.
- The implementation agrees with independently calculated reference cases.
- Cases include equilibrium, displacement with zero velocity, and motion through equilibrium.
- Invalid parameters are handled according to the learner's stated contract.
- The learner explains the state model and handles the transfer case: set damping to zero and predict what changes.

Implementation output, explanation, and transfer evidence are still required before demonstrated status. Finite checks do not establish universal correctness.

## Sequence

1. Identify the information needed for an instantaneous state.
2. Derive the state evolution and check units.
3. State the input/failure contract and predict reference cases.
4. Implement locally in C++ and provide actual output.
5. Review discrepancies, revise, explain, and perform the transfer exercise.

Teach only prerequisites needed at the current step. Follow the bounded prerequisite workflow in long-term/learning-rules.md.

## Opening question and learner evidence — 2026-09-08

Tutor question: If displacement x(t) is known at one instant, is it enough to determine subsequent motion? If not, what additional instantaneous information is needed?

Learner's exact answer:

> No, that's not enougth cause additional velocity information should be known.

Review: correct for this model. Given the specified parameters, displacement and velocity together specify the instantaneous state. This establishes only the opening conceptual response; it does not establish the derivation or implementation.

Evidence source: learner's conversation response. No C002 source, execution, reference calculations, or transfer result has been supplied. Tutor feedback confirmed the state choice; no crucial solution was supplied.

## Prediction, attempt, and final explanation

Pending learner work. Do not fill these in on the learner's behalf.

## Exact return point and next action

Continue from the accepted state choice (displacement and velocity); do not repeat the opening question or restart C001.

Ask one question: Taking displacement and velocity as the state, how would you express the time derivative of each component using the given equation?

If this is unfamiliar, explain the smallest missing prerequisite before asking for a derivation.

## Later work and retention

C003 is provisionally finite-step time evolution and numerical-error assessment; it has not begun. Select its scope from C002 evidence.
Revisit C001 after two or three subsequent completed sessions; no retention claim is established here.
