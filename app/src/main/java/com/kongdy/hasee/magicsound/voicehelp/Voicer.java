package com.kongdy.hasee.magicsound.voicehelp;

/**
 * @author kongdy
 * @date 2017-03-10 17:32
 * @TIME 17:32
 **/

public class Voicer {

    /** 女声 **/
    public static final int MODE_GRIL = 1;
    /** 大叔 **/
    public static final int MODE_UNCLE = 2;
    /** 萝莉 **/
    public static final int MODE_LOLI = 3;
    /** 搞怪 **/
    public static final int MODE_INTER = 4;
    /** 恐怖 **/
    public static final int MODE_TERROR = 5;
    /** 空灵 **/
    public static final int MODE_GHOST = 6;

    public static native void fix(String path,int mode);

    static{
        System.loadLibrary("JasonVoicer");
        System.loadLibrary("fmod");
        System.loadLibrary("fmodL");
    }
}
