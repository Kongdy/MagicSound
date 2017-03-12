//
// Created by e9060 on 2017/3/11.
//
#include "com_kongdy_hasee_magicsound_voicehelp_Voicer.h"
#include "inc/fmod.hpp"
#include <android/log.h>

/**
 * android系统日志log输出
 */
#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,##__VA_ARGS__)
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"jason",FORMAT,##__VA_ARGS__)


#define MODE_GRIL 1
#define MODE_UNCLE 2
#define MODE_LOLI 3
#define MODE_INTER 4
#define MODE_TERROR 5
#define MODE_GHOST 6

JNIEXPORT void JNICALL Java_com_kongdy_hasee_magicsound_voicehelp_Voicer_fix
        (JNIEnv *env, jclass jcls, jstring path_jstr,jint mode_jint){

    FMOD::System *system;
    FMOD::System_Create(&system);

    void *extradriverdata = 0;
    FMOD::Sound *sound;
    FMOD::DSP *dsp;
    FMOD::Channel *channel;
    /**
     * maxchannel:最大声道数量
     * flags:音频处理模式
     * extradriverdata：字面翻译，作用不详
     */
    system->init(5,FMOD_INIT_NORMAL,extradriverdata);
    // java string->c char
    const char* path_cstr = env->GetStringUTFChars(path_jstr,JNI_FALSE);
    // 创建sound
    system->createSound(path_cstr,FMOD_DEFAULT,0,&sound);

    switch (mode_jint) {
        case MODE_GRIL:
            LOGI("%s","女声");
            system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT,&dsp);
            dsp->setParameterInt(FMOD_DSP_TYPE_PITCHSHIFT,2.5);
            system->playSound(sound,0,false,&channel);
            channel->addDSP(0,dsp);
            break;
        default:
            break;
    }

    // 释放资源

};
