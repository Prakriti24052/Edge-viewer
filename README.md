# Edge Viewer – Android + Web

A lightweight Android + Web system for real-time image processing using **OpenCV (C++)**, **JNI**, and a **Next.js (TypeScript)** dashboard.

---

## Features Implemented

### Android (Native)
- Real-time frame capture using **CameraX**
- JNI bridge to **C++**
- Image processing using **OpenCV**:
  - Grayscale conversion
  - Edge detection
  - ByteBuffer → Mat → Processed PNG
- Returns processed frame to Kotlin/Jetpack UI
- **arm64-v8a** native build support
- Fully offline native image pipeline

### Web Dashboard (Next.js)
- PNG upload → processed preview
- Simulated frame viewer
- Simple API route for mock processing
- Modular **TypeScript + React** components

---

## Setup Instructions

### **Android Setup**

#### Install:
- Android Studio  
- **NDK (Side-by-side)**  
- **CMake 3.18+**  
- JDK 17+  
- OpenCV Android SDK  

#### Add Required Native Libraries  
From:  
`OpenCV-android-sdk/sdk/native/libs/arm64-v8a/`

Copy into:  
`app/src/main/jniLibs/arm64-v8a/`

You **must** include:
- `libopencv_java4.so`  
- `libc++_shared.so`  **

#### Build & Install
```bash
gradlew clean
gradlew assembleDebug
adb -s <device> install -r app/build/outputs/apk/debug/app-debug.apk

