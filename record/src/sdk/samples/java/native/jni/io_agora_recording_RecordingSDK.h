/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class io_agora_recording_RecordingSDK */

#ifndef _Included_io_agora_recording_RecordingSDK
#define _Included_io_agora_recording_RecordingSDK
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     io_agora_recording_RecordingSDK
 * Method:    createChannel
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILio/agora/recording/common/RecordingConfig;)Z
 */
JNIEXPORT jboolean JNICALL Java_io_agora_recording_RecordingSDK_createChannel
  (JNIEnv *, jobject, jstring, jstring, jstring, jint, jobject);

/*
 * Class:     io_agora_recording_RecordingSDK
 * Method:    leaveChannel
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_io_agora_recording_RecordingSDK_leaveChannel
  (JNIEnv *, jobject, jlong);

/*
 * Class:     io_agora_recording_RecordingSDK
 * Method:    setVideoMixingLayout
 * Signature: (JLio/agora/recording/common/Common/VideoMixingLayout;)I
 */
JNIEXPORT jint JNICALL Java_io_agora_recording_RecordingSDK_setVideoMixingLayout
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     io_agora_recording_RecordingSDK
 * Method:    startService
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_io_agora_recording_RecordingSDK_startService
  (JNIEnv *, jobject, jlong);

/*
 * Class:     io_agora_recording_RecordingSDK
 * Method:    stopService
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_io_agora_recording_RecordingSDK_stopService
  (JNIEnv *, jobject, jlong);

/*
 * Class:     io_agora_recording_RecordingSDK
 * Method:    getProperties
 * Signature: (J)Lio/agora/recording/common/RecordingEngineProperties;
 */
JNIEXPORT jobject JNICALL Java_io_agora_recording_RecordingSDK_getProperties
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
