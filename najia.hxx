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
    STEMINDEX_INVALID = -1,
    STEMINDEX_JIA = 0,
    STEMINDEX_YI,
    STEMINDEX_BING,
    STEMINDEX_DING,
    STEMINDEX_WU,
    STEMINDEX_JI,  
    STEMINDEX_GEN, 
    STEMINDEX_XIN, 
    STEMINDEX_REN, 
    STEMINDEX_GUI 
}GAN_INDEX;

typedef enum {
    BRANCHINDEX_INVALIDE = -1,
    BRANCHINDEX_ZI = 0,
    BRANCHINDEX_CHOU,
    BRANCHINDEX_YIN,
    BRANCHINDEX_MAO,
    BRANCHINDEX_CHEN,
    BRANCHINDEX_SI,
    BRANCHINDEX_WU,
    BRANCHINDEX_WEI,
    BRANCHINDEX_SHEN,
    BRANCHINDEX_YOU,
    BRANCHINDEX_XU,
    BRANCHINDEX_HAI
}ZHI_INDEX;

typedef struct StemBranch
{
    GAN_INDEX Stem;
    ZHI_INDEX Branch;
}GANZHI;

typedef struct XunKong
{
    ZHI_INDEX Branch[2];
}XUNKONG;

class GanZhi{
static bool get_gan_name(GAN_INDEX stem,char * name);
static bool get_zhi_name(ZHI_INDEX branch,char * name);
static bool get_ganzhi_name(GANZHI sb,char * sbName);
static XUNKONG get_ganzhi_kong(GANZHI sb);
static bool get_xunkong_name(XUNKONG xk,char * name);
}

}
#endif//_NAJIA_H_XX_