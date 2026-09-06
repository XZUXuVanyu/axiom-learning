# C001 — A C++ tool's behavior and contract

Date: 2026-09-06
Mastery status: attempted; revision needed
Execution state: paused for P-CXX-001 — Inheritance and polymorphism foundations
Normal budget: 45–60 minutes; first checkpoint: 10–15 minutes.

## Feature and purpose

Build one small capability whose caller can distinguish a valid result from a rejected request. This prepares Axiom to invoke tools and record dependable evidence. Start with adding two numbers as a deliberately small tool; the learning objective is the contract and failure behavior, not arithmetic sophistication.

C++ is the implementation language. We focus first on behavior and logic. MCP, plugin packaging, storage, and IDE integration come after a standalone capability works.

## Learner-owned work

The learner specifies the behavior, proposes component responsibilities, implements validation/result logic, and writes relevant checks. The assistant explains concepts, reviews attempts, and gives bounded hints. It must not supply crucial implementation, a finished architecture, or solution-equivalent pseudocode.

## Resolved contract decisions

- Inputs: exactly two `int32_t` operands for the first version.
- Success: their mathematical sum is representable as `int32_t`; zero is an ordinary valid result.
- Failure: a mathematical sum outside `[-2^{31}, 2^{31}-1]` is rejected through an exception path.
- Intended diagnostic boundary: a reusable `Axiom::Exception` base with a range-specific derived error carrying stable operation identity, operands, and source-location context.
- Source-location semantics: the desired location is the tool call site, not a refactor-sensitive helper location.

## Acceptance and evidence

Before coding, write concrete expected outcomes for a normal case, a relevant rejection case, and one boundary case. The learner must explain why each matters. Refine these based on the chosen numeric contract.

To mark demonstrated: actual behavior meets the agreed cases; the learner supplies source and command/output; explains the central design; and handles a small unfamiliar variation. Finite tests do not prove universal correctness.

## Learner prediction and design

- Successful inputs were defined as acceptable numeric values whose sum stays in range.
- The learner chose `int32_t` to give a fixed, explicit numeric range.
- The learner chose exceptions rather than explicit result values, because a valid result can be zero and failures should propagate to a boundary catch.
- A reusable range error should retain inputs and be usable by later numeric tools.
- The learner identified that a stable operation identity cannot be inferred solely from `std::source_location`, because helpers and refactors change locations.
- The learner proposed `Axiom::Exception` as a base with derived exceptions, then reported insufficient confidence in inheritance/polymorphism design.

## Attempts and execution evidence

Environment: Visual Studio/MSVC; C++20 selected by the learner.

Learner-submitted source and screenshot evidence showed:

- `add(13, 36)` produced `49`.
- `add(-13, 13)` produced `0`.
- `add(2147483647, -12341)` produced `2147471306`.
- `add(2147483647, 234)` entered the exception path.
- The catch printed `int __cdecl main(void)`, confirming that the current implementation stored only `location.function_name()` in `std::overflow_error::what()`.

Evidence source: learner-reported source and screenshot; not assistant-run on the learner's Windows environment.

## Tutor review

- Initial attempted check evaluated `a + b` before detecting overflow; that could cause signed-overflow undefined behavior.
- Revision formed the candidate result in `int64_t` first, then compared it with `int32_t` limits. This resolves that specific overflow-detection defect.
- The current standard `std::overflow_error` experiment does not retain a full `std::source_location`, operation identifier, or operands.
- `numeric_tool.cpp` must directly include `<limits>` if it uses `std::numeric_limits`.
- The draft `Axiom::Exception` hierarchy needs a clear base contract, virtual dispatch, ownership/lifetime understanding, and correct initialization of derived fields. This is the active concrete blocker.

## Prerequisite and return point

P-CXX-001 is active. It is deliberately unrelated to the C001 exception implementation where possible, so its exercise does not become a copied solution.

Return only after the prerequisite's bounded evidence is met. Then resume at: design the `Axiom::Exception` base contract and a `RangeException` constructor chain; implement and rerun C001's boundary tests.

## Revision, explanation, and transfer

Pending after prerequisite completion.

## Checkpoint

Next action: P-CXX-001 Unit 1 opening question.
Remaining gaps: reusable exception hierarchy, complete diagnostic accessors, actual C001 source committed to the learning repository, explanation, and transfer behavior.
Retention: revisit after demonstrated work and two or three subsequent sessions.
