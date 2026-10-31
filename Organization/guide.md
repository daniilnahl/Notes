# Keeping the notes organized

[Home](../README.md) · [Inbox](../Inbox/index.md) · [Backlog](backlog.md) · [Templates](../Templates/index.md)

## Naming and folders

- Use descriptive lowercase Markdown filenames with hyphens: `binary-search.md`.
- Use readable subject folders with hyphens between words: `Binary-Search/`.
- Keep established language names (`C++`, `Python`) and code filenames, especially Java class names and local include targets.
- Create a subfolder when it groups several useful files. Keep examples and their local dependencies together.
- Keep existing AI training workspaces and local environment paths in place.

## Where a note belongs

| Content | Main home |
| --- | --- |
| General algorithm or technique | Algorithms |
| General data structure and implementation | Data-Structures |
| Language syntax, APIs, or idioms | Languages |
| Hardware behavior or embedded constraints | Embedded-Systems |
| ML concepts, training, or inference | Artificial-Intelligence |
| CPU and memory organization | Computer-Architecture |
| Original lectures, assignments, and course PDFs | Courses |
| Individual practice problem | Leetcode-Notes |
| General computing tools and terminology | General-Information |

Give each reusable concept one main note. Link to it from course notes, practice problems, and related subjects. Keep board-specific instructions separate from protocol concepts and connect them with links.

## Capture and review

1. Capture quickly in Inbox using a template when useful.
2. During a weekly review, file notes and add them to the appropriate index.
3. Add one or two useful related links and record sources while they are available.
4. Track planned topics in the backlog rather than creating empty notes.
5. Split a broad note when its sections become independently useful references.

Each subject index is a curated starting point. Update it when adding or moving notes. Existing notes include links back to their index and the home page. In Obsidian, automatic link updates are enabled; review relative links when moving files outside Obsidian.

## Backup and migration

The full pre-reorganization working folder, including Git history and untracked or ignored content, is stored in `Backups/notes-before-streamlining-2026-10-27.tar.gz`. Its adjacent SHA-256 file records the archive checksum. Backups are excluded from Git.

The archive was read in full and all 338 visible files were compared against their original contents before migration. To restore, extract it into a separate empty folder and open that folder as the vault. This avoids mixing the old and reorganized layouts.

The [rename map](rename-map.csv) records original and current paths, including the disposition of empty notes. Source code, PDFs, and images retain their original bytes. The original problem comment template is preserved under Templates.
