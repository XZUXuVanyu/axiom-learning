# Program context

Recorded 2026-09-05 from the project conversation.

## Learning goals

1. Basic/intermediate TypeScript, advanced C++, and practical project design.
2. Harness plugins and bridges, eventually DAW/CAD integration.
3. Support ongoing development without taking over crucial implementation.

Background: C/C++ basics, OOP, some data structures, STM32 firmware experience; limited TypeScript. These are reported background, not course assessments.

## Axiom direction

Axiom CoLab is intended to connect goals, candidate implementations, ordinary build/test/debug workflows, validation, approval, and reusable toolkits. It may later support interactive experiments and real instruments such as the learner's STM32 optical-pulse recorder.

Working direction: begin with a lightweight integration for an existing IDE; preserve UI-independent tool/evidence services; consider an interactive laboratory later. A new full IDE and a 3D engine are deferred. Product usefulness and commercial differentiation remain hypotheses, not established facts.

The practice repository is not a full Axiom rewrite. Build one understandable vertical path first: validated request -> C++ tool -> TypeScript process bridge -> harness exposure -> thin IDE entry point. Keep the current production repository separate.

Exact harness, IDE extension technology, and toolchain versions are not selected. Visual Studio and VS Code are distinct products. Do not assume a Visual Studio extension is implemented in TypeScript. Choose technology based on current official interfaces before platform-specific work.

Longer-term ideas: computational tools, application bridges, and physical instruments can share discovery/evidence conventions but need different execution models. Precise timing and immediate hardware protection belong in local firmware/control hardware, not the LLM loop.

## Learning organization

Use a project conversation for each lesson and Git-tracked local code/Markdown as the authoritative learning record. CLI is optional. Provide the agreement/checkpoint in new sessions when unavailable; do not assume automatic cross-session context. Daily lessons already exist around 19:00 Asia/Shanghai, starting September 6; this package does not create another schedule.
