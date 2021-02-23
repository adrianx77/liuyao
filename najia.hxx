#ifndef _NAJIA_H_XX_
#define _NAJIA_H_XX_


#define  STEM_JIA    "甲"
#define  STEM_YI     "乙"
#define  STEM_BING   "丙"
#define  STEM_DING   "丁"
#define  STEM_WU     "戊"
#define  STEM_JI     "己"
#define  STEM_GEN    "艮"
#define  STEM_XIN    "辛"
#define  STEM_REN    "壬"
#define  STEM_GUI    "癸"

#define  BRANCH_ZI       "子"
#define  BRANCH_CHOU     "丑"
#define  BRANCH_YIN      "寅"
#define  BRANCH_MAO      "卯"
#define  BRANCH_CHEN     "辰"
#define  BRANCH_SI       "巳"
#define  BRANCH_WU       "午"
#define  BRANCH_WEI      "未"
#define  BRANCH_SHEN     "申"
#define  BRANCH_YOU      "酉"
#define  BRANCH_XU       "戌"
#define  BRANCH_HAI      "亥"

typedef enum {
    STEMINDEX_JIA,
    STEMINDEX_YI,
    STEMINDEX_BING,
    STEMINDEX_DING,
    STEMINDEX_WU,
    STEMINDEX_JI,  
    STEMINDEX_GEN, 
    STEMINDEX_XIN, 
    STEMINDEX_REN, 
    STEMINDEX_GUI 
}STEM_INDEX;

typedef enum {
    BRANCHINDEX_ZI,
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
}BRANCH_INDEX;

typedef struct StemBranch
{
    STEM_INDEX Stem;
    BRANCH_INDEX Branch;
}STEAMBRANCH;

typedef struct XunKong
{
    BRANCH_INDEX Branch[2];
}XUNKONG;


extern bool get_stem_name(STEM_INDEX stem,char * name);
extern bool get_branch_name(BRANCH_INDEX branch,char * name);
extern bool get_stembranch_name(STEAMBRANCH sb,char * sbName);
extern XUNKONG get_stembranch_kong(STEAMBRANCH sb);
extern bool get_xunkong_name(XUNKONG xk,char * name);
#endif//_NAJIA_H_XX_