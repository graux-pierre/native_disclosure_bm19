#include <jni.h>
#include <string>

extern "C" JNIEXPORT void JNICALL
Java_lu_uni_graux_bm19_MainActivity_arrayCopyUsingJNI(
        JNIEnv* env,
        jobject thisObj) {
    jclass cid = env->GetObjectClass(thisObj);
    jclass cid2 = env->FindClass("lu/uni/graux/bm19/MainActivity");

    jfieldID fidImei = env->GetFieldID(cid, "imei", "[C");
    jcharArray imei = (jcharArray) env->GetObjectField(thisObj, fidImei);

    jsize len = env->GetArrayLength(imei);
    jcharArray imeiCopy = env->NewCharArray(len);

    jchar* nativeBuf = (jchar*) malloc(sizeof(jchar)*len);
    env->GetCharArrayRegion(imei, 0, len/2, nativeBuf);
    jchar* imeiBuf = env->GetCharArrayElements(imei, NULL);
    for(jsize i = len/2; i<len ; i++) {
        nativeBuf[i] = imeiBuf[i];
    }
    env->ReleaseCharArrayElements(imei, imeiBuf, JNI_COMMIT);
    env->SetCharArrayRegion(imeiCopy, 0, len, nativeBuf);
    free(nativeBuf);

    jfieldID fidNotImei = env->GetFieldID(cid2, "notImei", "[C");
    env->SetObjectField(thisObj, fidNotImei, imeiCopy);
}