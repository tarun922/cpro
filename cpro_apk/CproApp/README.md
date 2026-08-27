# Cpro Android App (WebView wrapper)

Wraps https://tarun922.github.io/cpro/ in an Android app.

## Offline behavior
- When online: loads the live site normally and lets the WebView cache pages/assets as they load.
- When offline: forces the WebView to load from its cache (`LOAD_CACHE_ELSE_NETWORK`) instead of failing, so a page you've opened before can reopen without internet.
- Note: this depends on the site allowing normal browser caching (no special server work needed on your end) — visit each page once while online so it gets cached before trying it offline.

## How to build

### Option A: Android Studio (easiest, handles the SDK for you)
1. Install [Android Studio](https://developer.android.com/studio).
2. Open this folder (`CproApp`) as a project — it auto-generates the Gradle wrapper and downloads the Android SDK the first time you open it.
3. Click Run ▶, or Build > Generate Signed Bundle/APK.

### Option B: Command line on Fedora (no Android Studio)
You need Gradle + the Android SDK command-line tools once. Android Studio normally installs the SDK silently — doing it by hand is a one-time setup:

```bash
# 1. Java (17 is fine) and Gradle
sudo dnf install -y java-17-openjdk gradle

# 2. Android SDK command-line tools
mkdir -p ~/Android/Sdk/cmdline-tools
cd ~/Android/Sdk/cmdline-tools
curl -O https://dl.google.com/android/repository/commandlinetools-linux-11076708_latest.zip
unzip commandlinetools-linux-*.zip
mv cmdline-tools latest

# 3. Add to your shell profile (~/.bashrc), then reload
echo 'export ANDROID_HOME=$HOME/Android/Sdk' >> ~/.bashrc
echo 'export PATH=$PATH:$ANDROID_HOME/cmdline-tools/latest/bin:$ANDROID_HOME/platform-tools' >> ~/.bashrc
source ~/.bashrc

# 4. Install the exact platform + build-tools this project needs
yes | sdkmanager --licenses
sdkmanager "platforms;android-34" "build-tools;34.0.0"

# 5. Point Gradle at the SDK
cd /path/to/CproApp
echo "sdk.dir=$HOME/Android/Sdk" > local.properties

# 6. Generate the Gradle wrapper (this project doesn't ship gradle-wrapper.jar)
gradle wrapper --gradle-version 8.7

# 7. Build the debug APK
./gradlew assembleDebug
```

The APK lands at `app/build/outputs/apk/debug/app-debug.apk` — install it with:
```bash
adb install app/build/outputs/apk/debug/app-debug.apk
```

(`curl`/`unzip`/`adb` come from `dnf install curl unzip android-tools` if you don't have them.)

## Customize
- App name: `app/src/main/res/values/strings.xml`
- URL: `SITE_URL` constant in `app/src/main/java/com/tarun922/cpro/MainActivity.kt`
- Icon: `app/src/main/res/drawable/ic_launcher_foreground.xml` and colors in `colors.xml`
