# P-CXX-001 — C++ inheritance and polymorphism foundations

Date: 2026-09-06
Parent lesson: C001 — A C++ tool's behavior and contract
Mastery status: U1–U3 demonstrated; U4 attempted (design revision pending)
Execution state: active; U4 is the current unit
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

## U3 — active: ownership and substitutability

### Feature

A caller wants to retain several different output sinks through a common base interface without leaking objects, losing derived behavior, or deleting them incorrectly.

### Conceptual target

- A base object stored **by value** cannot retain a derived-only portion; this is object slicing.
- Polymorphic objects should normally be manipulated through references/pointers to the base contract.
- Ownership must be explicit. Standard RAII owners should release resources automatically.
- A publicly deletable polymorphic base requires a public virtual destructor; a protected destructor deliberately prevents deletion through the base interface.

### Opening question — ask only this first

Suppose a concrete `MemoryOut` object is copied into a variable whose declared type is `OutSink` (not a reference or pointer). What information/behavior do you predict is lost, and why might the code be rejected before runtime in the current design?

Stop after the prediction; review it before any implementation.

## U4 — active: error-family design transfer

### Feature

Before returning to C001, design an unrelated validation-error family that shares message and source context while one subtype adds its own domain data. This tests field placement and substitutability without implementing the Axiom exception hierarchy.

### Opening question — ask only this first

Imagine a document-importer with several failures. Propose one base error contract that every importer error needs, and one specific derived error whose extra data cannot sensibly live in every base error. Name the extra data and explain why it belongs only in that subtype.

Do not use `Axiom::Exception`, numeric overflow, or C001 class names. Stop after the design answer; review it before code.

## Return to C001

Return when U1–U3 have demonstrated evidence and U4's field-placement design check is met. Resume at C001's `Axiom::Exception` / `RangeException` header design, then implement and test the actual tool.

## Record

### Learner prediction/design

U1: the learner chose output sinks. The common contract is text output; destinations differ. The learner correctly identified that calls through `OutSink&` use virtual dispatch based on the object's actual derived type.

### Attempts and execution evidence

U1 learner-reported/screenshot evidence: Visual Studio/MSVC Debug x64 build succeeded with zero errors. `Output(OutSink&, text)` dispatched to console, file, and memory sinks. The memory sink stored `msg0` through `msg15`, preserved one valid empty string, and returned no value for later indices. The final visible output distinguished an ordinary message, the stored empty-string case (`Null Str` in the learner's label), and missing identifiers (`Invalid ID`). Source was submitted in conversation but is not committed to this repository.

### Tutor review

2026-09-06: U1 demonstrated dynamic dispatch through a base reference, correct static-versus-dynamic type explanation, and a third `MemoryOut` transfer variant. Review findings: `MemoryOut::read` initially fell off a non-void function on invalid input; learner revised its contract to `std::optional<std::string>`. The test now distinguishes no result from an existing empty string. Direct includes for `<vector>` and `<cstdint>` remain an engineering cleanup item unless already added locally. The label `Null Str` refers to an empty string, not a null string/pointer. U2 demonstrated. Learner-built trace evidence: base member (UID 0) constructed before the base constructor body; derived members constructed in declaration order (UIDs 1 then 2) despite the opposite initializer-list text; destruction occurred as derived body, derived members in reverse declaration order, base body, then base member. U3 demonstrated. Learner-reported/screenshot-visible evidence: a `vector<unique_ptr<OutSink>>` owned MemoryOut, FileOut, and ConsoleOut; calls were made through base pointers without casts or manual delete. Ownership transfer moved the ConsoleOut owner out of the vector; the original slot was checked as null and the program exited normally. Destruction logs showed the moved ConsoleOut once, then the remaining vector-owned derived/base pairs. This was an MSVC observation; no vector element-destruction order was assumed. U4 has a first design attempt under review.

### U4 first design attempt and review

2026-09-07: The learner identified occurrence time and error category as possible base-wide information, proposed a `SystemError` subtype with a system error code, and noted that document-specific errors should not be conflated with underlying system failures. The learner then proposed that every error class inherit `std::exception`, override `what()`, and carry `error_info`; the source of `system_error_code` was not yet identified. Review: only the family base needs to directly inherit `std::exception` and implement the common `what()` behavior; derived classes inherit that implementation. `error_info` must be decomposed into specific information with a stated consumer. A meaningful `SystemError` must represent an expected, recoverable lower-layer failure (for example, an operating-system/filesystem or decoder-library reported error), not a memory access violation or generic process crash. The learner selected the operating-system/filesystem branch: `SystemError` represents a failure while opening or reading the input, whereas a corrupted file header is a document-content failure. The next design step is to decide which precise base fields are necessary for all importer failures and which lower-layer fields belong only to `SystemError`.

### Revision and transfer

U1 transfer demonstrated: `MemoryOut` added without changing the caller function. U2 transfer demonstrated: a second derived member was declared in the opposite order from the initializer-list text. The learner predicted and observed declaration-order construction and reverse-order destruction. U3 transfer demonstrated: the learner stored heterogeneous sinks as `std::unique_ptr<OutSink>` in one vector, transferred one owner with move semantics, observed the source slot become null, avoided dereference, and observed normal derived-then-base destruction. U4 first design attempt recorded; revision pending.

### Outcome

Status: U1–U3 demonstrated; U4 attempted (design revision pending).
Next action: refine the U4 base contract and choose a concrete, recoverable source for subtype-specific system error information.
Retention: revisit polymorphic dispatch two or three sessions after demonstrated work.
