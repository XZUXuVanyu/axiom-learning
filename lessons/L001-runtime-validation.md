# L001 — Runtime validation of tool arguments

Mastery status: implementation not attempted
Execution state: paused for prerequisite assessment; P03 active
Normal budget: 45–60 minutes; first checkpoint: 10–15 minutes.

## Purpose

External tool arguments are runtime data. A TypeScript declaration expresses what the compiler can assume; it does not by itself inspect incoming values. This lesson teaches how runtime evidence supports safe use of an unknown input.

An input typed unknown can hold any value, but TypeScript requires sufficient evidence before allowing many operations on it. Narrowing means that checks or control flow establish a more specific type. A type assertion does not perform runtime checking or conversion.

## Learner-owned implementation

You implement the input validator and its relevant checks. The assistant will not supply the validator, its patch, or solution-equivalent pseudocode. Environment help and concept explanations are allowed.

## Scope and contract

Eventually write a function named parseAddArguments accepting unknown and returning a value with numeric a and b. Reject invalid input with an Error; exact error wording is not assessed. Return a fresh object and do not mutate the input. Arithmetic is outside this lesson.

For this beginner exercise, inputs are ordinary JSON-like values plus explicit invalid examples such as undefined and non-finite numbers. Successful objects have exactly two own enumerable string keys, a and b. Exotic proxies, getters, symbol keys, and custom prototype behavior are outside this lesson; this is not a hardened arbitrary-object validator.

Both fields must be finite numbers. Zero and negative numbers are valid. Do not coerce numeric strings. Do not use any, suppress compiler errors, or assert an unchecked value as the output type. No external validation library in this exercise, because the target is understanding narrowing.

NaN and Infinity cannot appear as JSON number literals, but can be passed directly to a function accepting unknown. Include them as direct-input checks.

## Acceptance examples

| Input description | Expected |
|---|---|
| Object: a = 2, b = 3 | Accept |
| Object: a = 0, b = -3.5 | Accept |
| Object: a = string "2", b = 3 | Reject |
| null or undefined | Reject |
| Array or primitive number/string | Reject |
| Object containing only a | Reject |
| Object with a, b, and extra | Reject |
| Either field is NaN or positive/negative Infinity | Reject |

Additional expectations: accepted input remains unchanged, and the return is a fresh object. These are finite behavioral checks, not proof of all possible behavior.

## Parent exercise — return here after prerequisites

1. In plain language, what must you establish about unknown input before using its a and b properties? An incomplete answer is welcome.
2. Does declaring that external data has a type change the data itself? Explain your prediction.
3. What editor and Node/TypeScript environment do you currently have? If you do not know, say so; setup guidance is a prerequisite, not a test of memory.

Stop at this checkpoint and request review. The tutor then teaches the smallest missing prerequisite before the coding attempt.

## Record — learner fills predictions and explanation

### Prediction/design

Pending.

### Attempts

For each meaningful attempt: file or code commit, command, actual output, interpretation, and hints received. Preserve earlier failures.

No attempt yet.

### Tutor review

2026-09-06 initial checkpoint: no learner code exists in `practice-plugin`; no attempt has been made or executed. Assistant-run environment inspection observed Node.js v24.19.0 and npm v11.17.0. No project package metadata or `tsc` executable was found. PowerShell blocked the script shims, while `npm.cmd` worked; an `npx.cmd` probe failed with `EPERM` during registry/cache access and installed nothing. TypeScript is not currently available through the inspected project or command path. No implementation hint has been given.

### Revision and learner explanation

Pending.

### Transfer check

Choose a small new input contract after the original attempt is understood; do not supply its implementation.

### Outcome

Status: not attempted.
Evidence source: no execution.
Remaining gaps: unassessed.
Next action: P01 foundations assessment below, then return to opening question 1.
Retention review: after two or three later sessions following demonstration.

## Prerequisite checkpoint — 2026-09-06

The learner raised a prerequisite problem: understanding unknown may require basic TypeScript grammar and datatypes first. The tutor acknowledged that L001's entry point should be adjusted. This is evidence of a reported obstacle, not a completed skills assessment. Earlier environment findings above remain historical evidence and were not rerun for this documentation update.

| Unit | Why needed | Bounded check | State |
|---|---|---|---|
| P01: values, variables, type annotations | Separate actual data from static declarations | Explain value versus annotation on a small unrelated example | Bounded check met; narrow prerequisite evidence |
| P02: basic values and object properties | Recognize the kinds of input being discussed | Distinguish numbers, strings, objects, null, and undefined, and describe a property | Bounded check met; narrow prerequisite evidence |
| P03: conditions and runtime checks | Understand evidence used for narrowing | Implement and explain a small runtime-value classifier using `unknown`; submit output | Active; unassessed |

This sequence is provisional. Skip supported prerequisites based on learner evidence. Do not teach all TypeScript datatypes merely to complete a checklist.

### P01 short record

- Why needed: the meaning of unknown depends on distinguishing runtime values from type information.
- Objective: understand values, variables, and basic type-annotation syntax.
- Check: after a brief explanation, predict whether changing an annotation changes the actual value in an unrelated example, and explain why.
- Learner answer/attempt: predicted that changing an annotation does not change the runtime value; compared the annotation to a tag and related it cautiously to a C++ declaration.
- Review/evidence: learner-reported explanation in the lesson conversation. Core distinction between static annotation and runtime value is correct. The C++ analogy needs a boundary: TypeScript annotations are erased before JavaScript runs.
- Hints: explanation of value, variable, and annotation; no validator implementation.
- Remaining gap: P02 bounded check is met. P03 remains active; the parent validator remains unattempted.
- Mastery status: bounded check met; this is prerequisite evidence, not implementation mastery.
- Return point: L001 opening question 1; assess P02/P03 if still needed.
- Next action: complete the P03 runtime-value classifier quest below. No parent-validator implementation yet.

### P02 short record

- Why needed: the parent contract refers to runtime numbers, strings, null, ordinary objects, property keys, and property values.
- Objective: distinguish relevant runtime values and describe object properties accurately.
- Bounded check evidence: learner classified `20` as a number, `"20"` as a string, `null` as neither, and `{ a: 20 }` as an object. Learner identified the key `"a"` and value `20`, and explained that `{ a: "20", b: 3 }` fails a numeric-`a`/numeric-`b` contract.
- Review: correct. The learner also derived the required validation order: outer ordinary-object check, required-property existence, then property-value type checks.
- Hints received: runtime/static distinction; why `null` must be excluded; the difference between `any` and `unknown`; no validator implementation.
- Mastery status: bounded check met; this is prerequisite evidence, not implementation mastery.
- Return point: P03 conditions/runtime checks.
- Next action: complete the P03 quest below.

### P03 real code quest — runtime-value classifier

- Objective: write and explain a small program whose control flow safely distinguishes runtime categories received as `unknown`.
- Crucial implementation: learner-owned. The learner writes the classifier and the test calls. The assistant may review an attempt but will not provide its implementation, patch, or solution-equivalent pseudocode.
- Function contract: implement `classifyRuntimeValue(value: unknown)`. It must return exactly one of the labels `"undefined"`, `"null"`, `"number"`, `"string"`, `"boolean"`, `"array"`, `"object"`, or `"other"`.
- Scope: ordinary JavaScript runtime values only. Use `unknown`; do not use `any`, type assertions to bypass checks, or external libraries. `null` must be distinguished from ordinary objects, and arrays must be distinguished from ordinary objects.
- Required observations: demonstrate the function on `undefined`, `null`, `-3`, `"20"`, `false`, an array, an ordinary object, and one value that should produce `"other"` (for example, a function).
- Acceptance criteria: every required input produces its specified category; code compiles/runs; the learner supplies the actual command and output; the learner explains why the `null`/array cases need special treatment; and the learner predicts one new test before running it.
- Relation to the parent lesson: this quest deliberately does not inspect `a` or `b`, enforce exact object keys, test finite numbers, or return parsed arguments. It prepares only the runtime-check/narrowing prerequisite.
- Current status: not attempted. No code or output has been submitted.

### Later questions

- 2026-09-06 auxiliary explanation: `any`, `unknown`, `undefined`, `never`, `null`, and `void`. This is conceptual context only; it does not add a separate active unit or demonstrate P03.
