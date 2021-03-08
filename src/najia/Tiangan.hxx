#ifndef _TIANGAN_HXX_
#define _TIANGAN_HXX_

#include "../base/Wuxing.hxx"

namespace Zhouyi{


#define  GAN_JIA    "甲"
#define  GAN_YI     "乙"
#define  GAN_BING   "丙"
#define  GAN_DING   "丁"
#define  GAN_WU     "戊"
#define  GAN_JI     "己"
#define  GAN_GENG   "庚"
#define  GAN_XIN    "辛"
#define  GAN_REN    "壬"
#define  GAN_GUI    "癸"

typedef enum {
    TGID_INVALID = -1,
    TGID_JIA = 0,
    TGID_YI,
    TGID_BING,
    TGID_DING,
    TGID_WU,
    TGID_JI,
    TGID_GEN,
    TGID_XIN,
    TGID_REN,
    TGID_GUI
}TIANGAN_ID;

//天干
class Tiangan{
protected:
    Tiangan(TIANGAN_ID gan);
    TIANGAN_ID _tiangan;
    static const char * _names[];
    static Tiangan* _tiangans[];
//初始化    
    static bool   _init;
    static void init();   
public:
    TIANGAN_ID id()const;
    operator TIANGAN_ID()const;
    static Tiangan& from(TIANGAN_ID gan);
    const char* name();
    Tiangan& get_next();
    Tiangan& get_prev();
    Wuxing& get_wuxing();
};


}
#endif//_TIANGAN_HXX_