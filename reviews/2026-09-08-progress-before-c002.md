# Current progress

Updated: 2026-09-08
Main lesson: C001 — A C++ tool's behavior and contract
Active unit: C001 — A C++ tool's behavior and contract
Record: lessons/C001-tool-contract.md
Completed prerequisite record: lessons/P-CXX-001-inheritance-polymorphism.md
C001 mastery status: demonstrated
Execution state: C001 complete; next feature not yet selected

## Current decision

C++ is primary; TypeScript is deferred. Focus on Axiom's features, logic, contracts, and failure behavior. The learner implements crucial code; documented evidence and bounded prerequisites remain required.

C001 uses Visual Studio/MSVC with C++20. The first tool contract is two `int32_t` operands; successful calls return a representable sum (including zero); an unrepresentable mathematical sum is an exception path. The intended long-term error boundary is a reusable `Axiom::Exception` base plus more specific derived errors.

## C001 checkpoint

The learner proposed and executed a standalone add tool. Learner-reported/screenshot-visible output was:

```text
49
0
2147471306
int __cdecl main(void)
```

The implementation was revised to form the candidate sum in `int64_t` before checking `int32_t` bounds, avoiding the earlier invalid pattern that evaluated `a + b` before the overflow check. The last call correctly entered the exception path.

The current experimental code throws `std::overflow_error(location.function_name())`. It proves propagation and default-argument call-site capture, but it does not retain a full `std::source_location`, an operation identifier, or operands. The learner began designing `Axiom::Exception` and `RangeException`, then identified inheritance/polymorphism design as a concrete blocker.

## Completed prerequisite

- ID: P-CXX-001 — Inheritance and polymorphism foundations.
- Why needed: C001 requires a base exception contract, derived range-specific context, safe virtual behavior through a base reference, and correct base/member construction order.
- Objective: design and implement small unrelated polymorphic types before resuming the Axiom exception hierarchy.
- Status: U1–U4 demonstrated. U4 established a common importer-error context (path, message, log timestamp) and a system-only lower-layer error code boundary.
- Return point: C001's `Axiom::Exception` / `RangeException` header and implementation.
- Bounded completion evidence: demonstrated behavior through a base reference, correct constructor/destructor-order explanation, and one small transfer design. This prerequisite does not itself establish C001.

## Alternating-week trial — 2026-09-07

Plan: weekly-plan.md. Adopted four study weeks alternating structure, physics/math-to-code, integration, and physics/validation on one evolving project.
Current emphasis: Week 1 — structure; continue C001. Exact study dates/hours are not yet recorded.
Next physics focus: proposed damped-oscillator prototype with analytical reference checks; not attempted or assessed.
Preserve unfinished return points at week boundaries; review the cadence after four study weeks. Both learning rules remain unchanged.

## Next action

Resume C001 at `Axiom::Exception` / `RangeException` header design. Ask one focused design question at a time; the learner owns the implementation.

## Preserved TypeScript evidence

L001 is deferred, not completed. Its full chronological record remains in lessons/L001-runtime-validation.md.

| Skill | Recorded evidence/status |
|---|---|
| Static types versus runtime values | P01 bounded check met; learner explanation recorded in L001. |
| Basic values and object properties | P02 bounded check met; classifications and property reasoning recorded. |
| Conditions and runtime checks | P03 revision needed at the latest repository checkpoint: bigint transfer case. |
| Parent runtime validator | Implementation not attempted. |
| C++ feature implementation | C001 attempted; prerequisite complete and C001 resumed; revision pending. |

P03 was implemented in an external Visual Studio TypeScript project. Learner-reported execution and screenshots are recorded in L001; source is not stored here. Later conversation reports include a bigint prediction, but this update does not establish a verified final correction. If TS resumes, inspect current source and actual output before reassessment.

## Deferred return point

If TypeScript is resumed: reconcile P03's bigint case with the latest learner code/output, then return to L001 question 1. This is not a blocker for C001. Preserve prior failures and evidence.

## Pending decisions

- Exact `Axiom::Exception` base interface and ownership semantics.
- C++ error representation beyond the C001 range case.
- JSON and MCP dependencies, evaluated when needed.
- Native IDE extension target and technology, later.

## Continuation instructions

Read AGENTS.md, learning-agreement.md, program-context.md, this file, the active prerequisite record, and C001. Ask one question at a time. Record predictions, attempts, actual results, hints, gaps, and one next action. Retention checks follow demonstrated work after two or three subsequent sessions.

## Repository continuity and conditional review — 2026-09-07

Durable program documents now live in long-term/; follow long-term/resume.md in a fresh conversation. Daily checks follow long-term/commit-review.md and reviews/commit-check-state.json. No new learner commit means no action. A new commit triggers review and one appropriate next step, not automatic advancement. This administrative update preserves C001's active checkpoint and establishes no new mastery.


## 2026-09-08 C001 source checkpoint

Learner source was committed in `08c2d5a909dd4244b9164b4fdf103ee59ab030a2` under `practice-plugin/c001/`. The learner-reported Visual Studio/MSVC C++20 runs show normal values `4`, `INT32_MAX`, and `INT32_MIN`; range rejections for `INT32_MAX + 1` and `INT32_MIN - 1`; call-site source-location output; and a typed `operation_type::numeric_add` comparison after catching `range_exception`. This evidence is learner-reported/screenshots; it was not executed by the reviewer.

Static review found the exception hierarchy now preserves message text, source location, operands, and operation identity. It still needs one focused revision: make the `what()` declaration and definition consistently `noexcept` (or record the precise compiler error if that fails). Direct header dependencies and the unused `output.h` dependency remain cleanup/reproducibility items.

## Next action

Resolve the `what() noexcept` declaration/definition mismatch, rebuild, and record the exact compiler result. Then explain the distinction between a base-wide `ErrorKind` and a range-specific `OperationType`.


## 2026-09-08 C001 closure

Final learner source revision: `023b38dd47aeab64cbf79ced0935f7160bc8e0fc`. The `what()` declaration and definition now consistently use `noexcept`; the learner-reported MSVC output rebuilt successfully and showed the three normal/boundary results plus the `numeric_add` range-rejection diagnostic.

C001 is demonstrated: source and actual learner-reported output are recorded; the learner explained message ownership and caller-site source-location capture; and the transfer check used structured `operation_type::numeric_add` rather than parsing `what()`. This establishes the bounded C001 contract only, not complete future exception taxonomy design.

## Next action

Choose the next feature-centered lesson from the C++ tool path. Keep a possible base-level `ErrorKind` as a deferred design item; do not add it until a second exception family creates an actual use case.
