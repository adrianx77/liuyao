#ifndef _NAJIA_H_XX_
#define _NAJIA_H_XX_

#define  GAN_JIA    "甲"
#define  GAN_YI     "乙"
#define  GAN_BING   "丙"
#define  GAN_DING   "丁"
#define  GAN_WU     "戊"
#define  GAN_JI     "己"
#define  GAN_GEN    "艮"
#define  GAN_XIN    "辛"
#define  GAN_REN    "壬"
#define  GAN_GUI    "癸"

#define  ZHI_ZI       "子"
#define  ZHI_CHOU     "丑"
#define  ZHI_YIN      "寅"
#define  ZHI_MAO      "卯"
#define  ZHI_CHEN     "辰"
#define  ZHI_SI       "巳"
#define  ZHI_WU       "午"
#define  ZHI_WEI      "未"
#define  ZHI_SHEN     "申"
#define  ZHI_YOU      "酉"
#define  ZHI_XU       "戌"
#define  ZHI_HAI      "亥"


namespace Zhouyi{
    typedef enum {
        GANID_INVALID = -1,
        GANID_JIA = 0,
        GANID_YI,
        GANID_BING,
        GANID_DING,
        GANID_WU,
        GANID_JI,
        GANID_GEN,
        GANID_XIN,
        GANID_REN,
        GANID_GUI
    }GAN_ID;

    typedef enum {
        ZHIID_INVALIDE = -1,
        ZHIID_ZI = 0,
        ZHIID_CHOU,
        ZHIID_YIN,
        ZHIID_MAO,
        ZHIID_CHEN,
        ZHIID_SI,
        ZHIID_WU,
        ZHIID_WEI,
        ZHIID_SHEN,
        ZHIID_YOU,
        ZHIID_XU,
        ZHIID_HAI
    }ZHI_ID;

    class GanzhiZhuhe
    {
    public:
        GAN_ID Stem;
        ZHI_ID Branch;
    };

    class XunKong
    {
    public:
        ZHI_ID Branch[2];
    };


    class GanZhi{

    public:
        static GAN_ID get_next_stem(GAN_ID stem);
        static ZHI_ID get_next_branch(ZHI_ID branch);
        static ZHI_ID get_prev_branch(ZHI_ID branch);
        static GAN_ID get_prev_stem(GAN_ID stem);
        static GanzhiZhuhe get_next_stembranch(GanzhiZhuhe sb);
        static GanzhiZhuhe get_prev_stembranch(GanzhiZhuhe sb);
        static XunKong get_ganzhi_kong(GanzhiZhuhe sb);
        static bool get_xunkong_name(XunKong xk,char * name);
        static bool get_gan_name(GAN_ID stem,char * name);
        static bool get_zhi_name(ZHI_ID branch,char * name);
        static bool get_ganzhi_name(GanzhiZhuhe sb,char * sbName);
        static bool get_gan_element();
        
    };

}
#endif//_NAJIA_H_XX_
