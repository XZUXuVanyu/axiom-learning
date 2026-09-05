# L001 — Runtime validation of tool arguments

Status: not attempted
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

## Begin here — no implementation yet

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
Next action: opening questions above.
Retention review: after two or three later sessions following demonstration.
