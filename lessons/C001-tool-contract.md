# C001 — A C++ tool's behavior and contract

Date: 2026-09-06
Mastery status: not attempted
Execution state: active
Normal budget: 45–60 minutes; first checkpoint: 10–15 minutes.

## Feature and purpose

Build one small capability whose caller can distinguish a valid result from a rejected request. This prepares Axiom to invoke tools and record dependable evidence. Start with adding two numbers as a deliberately small tool; the learning objective is the contract and failure behavior, not arithmetic sophistication.

C++ is the implementation language. We focus first on behavior and logic. MCP, plugin packaging, storage, and IDE integration come after a standalone capability works.

## Learner-owned work

The learner specifies the behavior, proposes component responsibilities, implements validation/result logic, and writes relevant checks. The assistant explains concepts, reviews attempts, and gives bounded hints. It must not supply crucial implementation, a finished architecture, or solution-equivalent pseudocode.

## Opening checkpoint — ask only this first

A caller asks your tool to add two numbers. What should count as a successful call, and what should the caller receive when the request cannot be accepted? Describe your intended behavior in plain language, with one success example and one failure example.

Review that answer before discussing representation or coding. Do not require unfamiliar C++ syntax to answer.

## Contract questions to resolve together

These are a discussion backlog, not simultaneous homework:
- Which numeric values does this first version support?
- What does a result mean, and how is failure distinguishable from a valid zero?
- What should happen if valid operands produce an unrepresentable result?
- Which component interprets incoming data, and which performs the operation?
- What should the tool leave unchanged when it rejects a request?

Keep the learner's decisions and reasons below. Do not pre-fill the final design.

## First implementation scope

After reviewing the contract, agree on one small standalone C++ implementation and observable checks. Begin with direct local calls; add structured external input as a later bounded step. Do not implement JSON parsing, MCP lifecycle, or an IDE extension in the first attempt. Choose build commands from the actual local environment. No C++ compiler has been verified in this course update.

External data will still require runtime validation even though C++ is statically typed. When external input is introduced, distinguish malformed input, invalid tool arguments, and execution failure according to the agreed contract.

## Acceptance and evidence

Before coding, write concrete expected outcomes for a normal case, a relevant rejection case, and one boundary case. The learner must explain why each matters. Refine these based on the chosen numeric contract.

To mark demonstrated: actual behavior meets the agreed cases; the learner supplies source and command/output; explains the central design; and handles a small unfamiliar variation. Finite tests do not prove universal correctness.

## Learner prediction and design

Pending learner response.

## Attempts and execution evidence

None. No source, command, or output submitted for C001.

## Tutor review

2026-09-06: documented the user-authorized C++ direction and feature-centered lesson. This is preparation only, not skill evidence. TypeScript history remains in L001.

## Revision, explanation, and transfer

Pending. Select the transfer task after the original attempt is understood.

## Prerequisites and return point

No active prerequisite. If blocked, record the exact issue, teach one smallest prerequisite, define its bounded check, and return to the paused contract/implementation question. Use at most two nested levels by default.

## Checkpoint

Next action: learner answers the opening success/failure question.
Remaining gaps: contract, C++ environment, implementation, and behavior evidence unassessed.
Retention: revisit after demonstrated work and two or three subsequent sessions.
