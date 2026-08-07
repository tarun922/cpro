# cpro notes — setup

1. Copy this whole `docs` folder into the root of your `cpro` repo (so the path is `cpro/docs/index.html`).
2. Push it:
   ```
   git add docs
   git commit -m "add notes app"
   git push
   ```
3. On GitHub: go to your repo → Settings → Pages → under "Build and deployment" set Source = "Deploy from a branch", Branch = `main`, Folder = `/docs`. Save.
4. Wait ~1 min, then your app is live at:
   https://tarun922.github.io/cpro/
5. Open that link on your phone. Tap the browser menu → "Add to Home screen" — it installs like an app, works offline, and auto-pulls any new .c file you push to the repo.

That's it, no APK needed for this part — this alone gives you an installable app icon on your phone.
