#include <jni.h>
#include <cstring>                // <-- Needed for std::memcpy
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

// Simple test function: converts RGBA image to grayscale and back
extern "C"
JNIEXPORT void JNICALL
Java_com_example_edgeviewerandroid_FrameProcessor_nativeProcessFrame(
        JNIEnv* env,
        jclass /*clazz*/,
        jobject inputBuffer,
        jint width,
        jint height,
        jobject outputBuffer) {

    // Get pointer to input and output data
    auto* inPtr  = static_cast<unsigned char*>(env->GetDirectBufferAddress(inputBuffer));
    auto* outPtr = static_cast<unsigned char*>(env->GetDirectBufferAddress(outputBuffer));

    if (inPtr == nullptr || outPtr == nullptr) {
        return; // safety check
    }

    // Wrap input as OpenCV Mat (RGBA)
    cv::Mat src(height, width, CV_8UC4, inPtr);
    cv::Mat gray, dst;

    // Convert to grayscale
    cv::cvtColor(src, gray, cv::COLOR_RGBA2GRAY);

    // Simple edge or grayscale processing (for now just grayscale → RGBA)
    cv::cvtColor(gray, dst, cv::COLOR_GRAY2RGBA);

    // Copy result back to output buffer
    size_t totalBytes = static_cast<size_t>(width) * static_cast<size_t>(height) * 4;
    std::memcpy(outPtr, dst.data, totalBytes);
}
