# cpro notes — setup

1. Copy this whole `docs` folder into the root of your `cpro` repo (so the path is `cpro/docs/index.html`).
2. Push it:
   ```
   git add docs
   git commit -m "redesign notes app"
   git push
   ```
3. On GitHub: go to your repo → Settings → Pages → under "Build and deployment" set Source = "Deploy from a branch", Branch = `main`, Folder = `/docs`. Save.
4. Wait ~1 min, then your app is live at:
   https://tarun922.github.io/cpro/
5. Open that link on your phone. Tap the browser menu → "Add to Home screen" — it installs like an app, works offline, and auto-pulls any new .c file you push to the repo.

That's it, no APK needed for this part — this alone gives you an installable app icon on your phone.

## What changed in this pass

- Split the old single `index.html` (with inline `<style>`/`<script>`) into separate files, so each piece is easy to find and edit on its own:
  - `css/tokens.css` — colors, fonts, spacing variables (edit this to retheme)
  - `css/layout.css` — header, sidebar, tabs, responsive grid
  - `css/components.css` — code viewer + notes card styling
  - `js/config.js` — repo owner/name, cache key
  - `js/highlight.js` — the C syntax highlighter
  - `js/notesParser.js` — turns `//` comment blocks into note cards
  - `js/github.js` — fetches `.c` files from GitHub + localStorage cache
  - `js/render.js` — all DOM rendering (sidebar, tabs, code, notes)
  - `js/app.js` — boots the app, wires theme toggle + search + service worker
- New UI:
  - Desktop (≥860px) now shows a real two-pane layout: a file sidebar on the left, code in the middle, and a sticky notes rail on the right — instead of everything stacked in one column.
  - Mobile keeps the horizontal-scrolling file tabs, now paired with the same component styles as desktop.
  - Added a file search/filter box (desktop), a copy-code button, a line/notes counter, and a live status pill with a pulsing dot instead of plain text.
  - Notes use a proper sans-serif (Inter) for the annotation text so it reads better than mono at small sizes, while code and UI chrome stay in JetBrains Mono.
  - Theme choice (dark/light) now persists across visits.
- `sw.js` was updated to cache the new file list (bumped to `cpro-notes-shell-v2`, so old cached shells get replaced automatically on next load).
