# Program context

Recorded 2026-09-05; direction revised by the learner on 2026-09-06.

## Learning goals

1. Advanced C++ and practical project design through working features; basic/intermediate TypeScript deferred.
2. Harness plugins and bridges, eventually DAW/CAD integration.
3. Support ongoing development without taking over crucial implementation.

Background: C/C++ basics, OOP, some data structures, STM32 firmware experience; limited TypeScript. These are reported background, not course assessments.

## Axiom direction

Axiom CoLab is intended to connect goals, candidate implementations, ordinary build/test/debug workflows, validation, approval, and reusable toolkits. It may later support interactive experiments and real instruments such as the learner's STM32 optical-pulse recorder.

Working direction: begin with a lightweight integration for an existing IDE; preserve UI-independent tool/evidence services; consider an interactive laboratory later. A new full IDE and a 3D engine are deferred. Product usefulness and commercial differentiation remain hypotheses, not established facts.

The practice repository is not a full Axiom rewrite. Build one understandable vertical path first: validated request -> standalone C++ capability -> C++ MCP server for local Codex -> plugin packaging -> incremental Axiom features. Evaluate IDE integration separately. Keep the current production repository separate.

Local Codex through MCP is the initial harness target. Exact C++ libraries, IDE extension technology, and toolchain versions are not selected. Visual Studio and VS Code are distinct products. Do not assume a Visual Studio extension is implemented in TypeScript. Choose technology based on current official interfaces before platform-specific work.

Longer-term ideas: computational tools, application bridges, and physical instruments can share discovery/evidence conventions but need different execution models. Precise timing and immediate hardware protection belong in local firmware/control hardware, not the LLM loop.

## Learning organization

Use a project conversation for each lesson and Git-tracked local code/Markdown as the authoritative learning record. CLI is optional. Provide the agreement/checkpoint in new sessions when unavailable; do not assume automatic cross-session context. Daily lessons already exist around 19:00 Asia/Shanghai, starting September 6; this package does not create another schedule.

## Implementation boundary and priorities — 2026-09-06

All executable Axiom functionality may be C++; plugin manifests/connection settings are JSON and workflow instructions are Markdown. Codex communicates with the C++ MCP executable as a separate process. This plan does not require a TypeScript wrapper or changes to Codex's core. Pure C++ does not mean zero configuration or dependency management.

Integration references checked in the preceding conversation:
- https://learn.chatgpt.com/docs/extend/mcp?surface=cli
- https://developers.openai.com/plugins/build/plugins

Recheck current interfaces when integration begins. No C++ MCP SDK has been selected or verified. A Codex plugin is not itself a native Visual Studio extension.

Priorities: useful behavior, explicit contracts, testable logic, observable failures, evidence records, and human approval. Long-term pipeline: idea -> agent proposal -> candidate implementation -> human/AI-assisted build/test/debug -> approval tied to tested evidence -> toolkit registration. Build each part incrementally. Approval enforcement belongs in executable logic, not merely skill instructions. Do not claim the plugin grants unrestricted control or persistent learning automatically.
