# P-CXX-001 — C++ inheritance and polymorphism foundations

Date: 2026-09-06
Parent lesson: C001 — A C++ tool's behavior and contract
Mastery status: U1 demonstrated; U2 not attempted
Execution state: active; U2 is the current unit
Normal budget: four focused sessions of 45–60 minutes; no automatic advancement.

## Why this exists

C001 paused at the design of `Axiom::Exception` and `RangeException`. The immediate blocker is not syntax alone: it is deciding which responsibility belongs to a base class, what a derived class adds, what dynamic dispatch guarantees through a base reference, and how construction/destruction order preserves invariants.

This prerequisite uses small, unrelated examples. It must not directly implement the C001 exception hierarchy or become a copyable solution for it.

## Objective

After this unit, the learner can design and implement a small polymorphic family in C++, explain its runtime behavior through a base reference, and reason correctly about base/member/derived construction and destruction.

## Standing implementation boundary

The learner owns all exercise implementations, tests, and revisions. The assistant may explain language semantics, review submitted attempts, identify violated requirements, and give bounded counterexamples. It must not provide crucial exercise code, a patch, or solution-equivalent pseudocode.

## Learning map

| Unit | Feature question | Bounded learner-owned work | Evidence required |
|---|---|---|---|
| U1: Base contract and dynamic dispatch | What behavior is genuinely common, and why call it through a base reference? | Design and implement an unrelated two-variant reporting feature with one shared base interface and one virtual operation. | Predict then demonstrate distinct derived behavior through a base reference/pointer; explain why non-virtual dispatch would differ. |
| U2: Construction, destruction, and invariants | In what order do base, members, and derived state come into existence and disappear? | Create a small traceable base/derived example whose constructors and destructors visibly report lifecycle order. | Predict the exact order before running; submit actual output and explain reverse destruction. |
| U3: Ownership and substitutability | Which data are base-wide, which are derived-only, and what must never be sliced or leaked? | Revise the U1 design to store polymorphic objects safely without leaking or copying away derived behavior. | Explain ownership choice, slicing risk, and why base destruction is safe. |
| U4: Error-family design transfer | Can the same reasoning describe an error family without solving C001? | On paper, design a new unrelated validation-error family with common message/context and one subtype-specific field; then implement only if the design review succeeds. | State field placement reasons; handle one unfamiliar subtype variation. |

## U1 — demonstrated

### Feature

A caller wants to ask different report objects for a summary, while holding them through the same base interface. The caller must get behavior appropriate to the object actually created, not merely to the static type of its variable.

### Conceptual target

- A base class expresses the operations every family member promises.
- A derived class adds or specializes behavior.
- A virtual member function selects behavior using the object's dynamic type when accessed through a base reference or pointer.
- Inheritance is justified by a substitutability relationship, not merely by code reuse.

### Learner-owned implementation

Do not write C001 error classes yet. Implement a small unrelated two-variant reporting feature after the design checkpoint is reviewed. Choose names and domain yourself; avoid copying a `Shape` tutorial unchanged.

### Acceptance criteria

Before code:

1. Name one shared operation and state what every variant guarantees.
2. Name one behavior that differs between variants.
3. Predict what a caller holding a base reference should observe for each variant.
4. Explain one reason a non-virtual base operation would be insufficient.

After code:

1. Show actual build/run output for both variants through a base reference or pointer.
2. Explain static type versus dynamic type in that output.
3. Add one small third-variant transfer case without solution-level help.
4. Record all hints and revisions.

### Opening question — ask only this first

Choose an unrelated feature domain with two variants (for example, two kinds of report, message, or measurement). In plain language:

- What is the one operation every variant must support?
- What must differ between the two variants?
- Why should a caller be allowed to use either through one common base type?

Stop after answering; review the design before code.

## U2 — active: construction, destruction, and invariants

### Feature

A caller needs confidence about when a base part, its members, and derived-only state come into existence and are destroyed. This determines whether a derived class may rely on base invariants and why cleanup runs in reverse order.

### Learner-owned task

Build one small, unrelated traceable base/derived hierarchy. Use one member object owned by the base and another owned by the derived class; each construction and destruction event must leave an observable trace. Create the most-derived object in a local scope; do not use heap allocation.

Before coding, predict the complete event sequence. After coding, run it and compare every observed event with the prediction.

### Acceptance criteria

1. Actual output identifies base construction, base-member construction, derived construction, derived-member construction, and their destruction events.
2. The learner gives a complete predicted order before execution.
3. The learner explains why destruction reverses the relevant construction dependencies.
4. One transfer variation adds a second member or another inheritance level and predicts the new sequence.

### Opening question — ask only this first

Consider a derived object whose base class owns one member and whose derived class owns one additional member. Without writing code, list the order in which you predict these four phases occur:

- base member construction;
- base constructor body;
- derived member construction;
- derived constructor body.

Stop after the prediction; review it before implementation.

## U3 — deferred

Begin only after U2 is demonstrated. Keep resource ownership examples small and use standard RAII types; no raw ownership exercise is required unless a concrete gap appears.

## U4 — deferred transfer

Begin only after U3 is demonstrated. Its purpose is to map demonstrated principles back to error-family design without supplying C001 implementation.

## Return to C001

Return when U1–U3 have demonstrated evidence and U4's field-placement design check is met. Resume at C001's `Axiom::Exception` / `RangeException` header design, then implement and test the actual tool.

## Record

### Learner prediction/design

U1: the learner chose output sinks. The common contract is text output; destinations differ. The learner correctly identified that calls through `OutSink&` use virtual dispatch based on the object's actual derived type.

### Attempts and execution evidence

U1 learner-reported/screenshot evidence: Visual Studio/MSVC Debug x64 build succeeded with zero errors. `Output(OutSink&, text)` dispatched to console, file, and memory sinks. The memory sink stored `msg0` through `msg15`, preserved one valid empty string, and returned no value for later indices. The final visible output distinguished an ordinary message, the stored empty-string case (`Null Str` in the learner's label), and missing identifiers (`Invalid ID`). Source was submitted in conversation but is not committed to this repository.

### Tutor review

2026-09-06: U1 demonstrated dynamic dispatch through a base reference, correct static-versus-dynamic type explanation, and a third `MemoryOut` transfer variant. Review findings: `MemoryOut::read` initially fell off a non-void function on invalid input; learner revised its contract to `std::optional<std::string>`. The test now distinguishes no result from an existing empty string. Direct includes for `<vector>` and `<cstdint>` remain an engineering cleanup item unless already added locally. The label `Null Str` refers to an empty string, not a null string/pointer. U2 is now active.

### Revision and transfer

U1 transfer demonstrated: `MemoryOut` added without changing the caller function. U2 transfer pending.

### Outcome

Status: U1 demonstrated; U2 not attempted.
Next action: answer the U2 construction-order prediction question.
Retention: revisit polymorphic dispatch two or three sessions after demonstrated work.
