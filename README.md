# Axiom learning repository

Start here. This is a learning project for xzu, not the production Axiom CoLab repository.

## Start

1. Extract this directory and open it in your normal editor/IDE.
2. Read AGENTS.md and learning-agreement.md.
3. Create your local Git repository here and connect your own empty GitHub repository. This package contains no .git directory and creates no remote repository.
4. Begin lessons/L001-runtime-validation.md. No implementation is supplied.
5. Share code, a diff, a file, or a repository link plus branch/commit whenever you want review. Include the command/output and your question. A new remote commit is not automatically read by the assistant: identify the revision you want reviewed.

## Daily workflow

One conversation per lesson, continuing that conversation for revisions. Implement locally in practice-plugin/. Codex CLI is optional; it must follow AGENTS.md. Start each session from progress.md and the lesson file. End by recording evidence and the exact next step; unfinished work is a valid checkpoint. Commit meaningful attempts and the updated records. Avoid putting a commit's own future hash inside itself: reference a preceding code commit or relevant file instead.

The learner writes predictions, code, and explanations. The assistant may draft factual review notes, but the learner reviews them. Preserve failed attempts through Git and brief notes instead of copying all code into Markdown. A daily reminder resumes the current lesson; it does not imply mastery or create a backlog.

## Resume message

Read AGENTS.md, learning-agreement.md, progress.md, and the current lesson. Summarize the checkpoint and the learner-owned implementation. Teach with hints and questions; do not implement crucial code. Review the specific files/revision I provide. Distinguish observed output from untested inference.

## Files

- AGENTS.md: assistant operating instructions.
- learning-agreement.md: standing teaching rules.
- program-context.md: goals, product direction, and deferred choices.
- progress.md: current checkpoint and skill evidence.
- lessons/: lesson worksheet and reusable template.
- practice-plugin/: evolving learner-owned implementation.

This starter provides documentation only. It contains no TypeScript runtime, compiler, C++ toolchain, packages, executable implementation, or completed tests. Choose and verify the environment interactively before the first code run.
