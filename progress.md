# Current progress

Updated: 2026-09-06
Main lesson: C001 — A C++ tool's behavior and contract
Active unit: P-CXX-001 / U2 — Construction, destruction, and invariants
Record: lessons/P-CXX-001-inheritance-polymorphism.md
C001 mastery status: attempted; revision needed
Execution state: C001 paused for a learner-requested prerequisite; P-CXX-001 active

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

## Active prerequisite

- ID: P-CXX-001 — Inheritance and polymorphism foundations.
- Why needed: C001 requires a base exception contract, derived range-specific context, safe virtual behavior through a base reference, and correct base/member construction order.
- Objective: design and implement small unrelated polymorphic types before resuming the Axiom exception hierarchy.
- Return point: C001's `Axiom::Exception` / `RangeException` header and implementation.
- Bounded completion evidence: demonstrated behavior through a base reference, correct constructor/destructor-order explanation, and one small transfer design. This prerequisite does not itself establish C001.

## Next action

Start P-CXX-001, Unit 2: predict and then demonstrate base/member/derived construction and reverse destruction order using a small unrelated traceable hierarchy. Ask one focused question at a time. Do not supply the exercise implementation.

## Preserved TypeScript evidence

L001 is deferred, not completed. Its full chronological record remains in lessons/L001-runtime-validation.md.

| Skill | Recorded evidence/status |
|---|---|
| Static types versus runtime values | P01 bounded check met; learner explanation recorded in L001. |
| Basic values and object properties | P02 bounded check met; classifications and property reasoning recorded. |
| Conditions and runtime checks | P03 revision needed at the latest repository checkpoint: bigint transfer case. |
| Parent runtime validator | Implementation not attempted. |
| C++ feature implementation | C001 attempted; prerequisite active before completion. |

P03 was implemented in an external Visual Studio TypeScript project. Learner-reported execution and screenshots are recorded in L001; source is not stored here. Later conversation reports include a bigint prediction, but this update does not establish a verified final correction. If TS resumes, inspect current source and actual output before reassessment.

## Deferred return point

If TypeScript is resumed: reconcile P03's bigint case with the latest learner code/output, then return to L001 question 1. This is not a blocker for C001. Preserve prior failures and evidence.

## Pending decisions

- Exact `Axiom::Exception` base interface and ownership semantics after P-CXX-001.
- C++ error representation beyond the C001 range case.
- JSON and MCP dependencies, evaluated when needed.
- Native IDE extension target and technology, later.

## Continuation instructions

Read AGENTS.md, learning-agreement.md, program-context.md, this file, the active prerequisite record, and C001. Ask one question at a time. Record predictions, attempts, actual results, hints, gaps, and one next action. Retention checks follow demonstrated work after two or three subsequent sessions.
