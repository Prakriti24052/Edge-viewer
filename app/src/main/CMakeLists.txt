# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.
cmake_minimum_required(VERSION 3.22.1)

# Declares the project name.
project("edgeviewerandroid")

# -------------------------
# OpenCV INCLUDE DIRECTORY
# -------------------------
# Tell CMake where the OpenCV headers are located (paths are relative to
# CMAKE_SOURCE_DIR which is already set to app/src/main)
include_directories(${CMAKE_SOURCE_DIR}/cpp/include)

# ---------------------------------
# Import the prebuilt OpenCV .so
# ---------------------------------
add_library(opencv_java4 SHARED IMPORTED)

set_target_properties(opencv_java4 PROPERTIES
        IMPORTED_LOCATION
        "${CMAKE_SOURCE_DIR}/jniLibs/arm64-v8a/libopencv_java4.so"
)

# ---------------------------------
# Build your native library
# ---------------------------------
add_library(${CMAKE_PROJECT_NAME} SHARED
        # List C/C++ source files (paths are relative to CMAKE_SOURCE_DIR)
        jni/FrameProcessor.cpp
)

# -------------------------
# Android log library
# -------------------------
find_library(log-lib log)

# -----------------------------------------
# Link your library with OpenCV + android
# -----------------------------------------
target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log
        ${log-lib}
        opencv_java4
)
