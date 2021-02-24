#ifndef _TIANGAN_HXX_
#define _TIANGAN_HXX_
#include "element.hxx"

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
    }TIANGANID;

//天干
    class Tiangan{

    public:
        static const char * _names[];
        static bool get_name(TIANGANID gan,char * name);
        static Tiangan * from(TIANGANID gan);
        static TIANGANID get_next(TIANGANID gan);
        static TIANGANID get_prev(TIANGANID gan);
        static WUXING_ID get_element(TIANGANID gan);
    };


}
#endif//_TIANGAN_HXX_