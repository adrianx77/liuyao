#ifndef _LIUYAO_DEF_HXX_
#define _LIUYAO_DEF_HXX_
#include "basedef.hxx"

#define GUANAME_QIAN   "乾"
#define GUANAME_DUI    "兑"
#define GUANAME_LI     "离"
#define GUANAME_ZHEN   "震"
#define GUANAME_XUN    "巽"
#define GUANAME_KAN    "坎"
#define GUANAME_GEN    "艮"
#define GUANAME_KUN    "坤"

typedef enum{
    GUAINDEX_QIAN   = 0,
	GUAINDEX_DUI    = 1,
	GUAINDEX_LI     = 2, 
	GUAINDEX_ZHEN   = 3,
	GUAINDEX_XUN    = 4,
	GUAINDEX_KAN    = 5,
	GUAINDEX_GEN    = 6,
	GUAINDEX_KUN    = 7
}GUA_INDEX;

#define RELATIVE_XIONGDI   "兄弟"
#define RELATIVE_FUMU      "父母"
#define RELATIVE_GUANGUI   "官鬼"
#define RELATIVE_QICAI     "妻财"
#define RELATIVE_ZISUN     "子孙"

typedef enum{
    RELATIVEINDEX_XIONGDI,
    RELATIVEINDEX_FUMU,
    RELATIVEINDEX_GUANGUI,
    RELATIVEINDEX_
}RELATIVE_INDEX;


#define YAO_SHAOYIN    "▆▆　▆▆ "
#define YAO_SHAOYANG   "▆▆▆▆▆ "
#define YAO_LAOYIN     "▆▆　▆▆x"
#define YAO_LAOYANG    "▆▆▆▆▆o"

#define YAO_YIN     "▆▆　▆▆"
#define YAO_YANG    "▆▆▆▆▆"

#define YAOWEI_SHI     "世"
#define YAOWEI_YING    "应"
#define YAOWEI_KONG    "　"
typedef enum {
    YAOWEIINDEX_KONG,
    YAOWEIINDEX_SHI,
    YAOWEIINDEX_YING
    }YAOWEI_INDEX;

#define CREATURE_QINGLONG  "青龙"
#define CREATURE_ZHUQUE    "朱雀"
#define CREATURE_GOUCHEN   "勾陈"
#define CREATURE_TENGSHE   "螣蛇"
#define CREATURE_BAIHU     "白虎"
#define CREATURE_XUANWU    "玄武"

typedef enum {
    CREATUREINDEX_QINGLONG    = 0,
    CREATUREINDEX_ZHUQUE      = 1,
    CREATUREINDEX_GOUCHEN     = 2,
    CREATUREINDEX_TENGSHE     = 3,
    CREATUREINDEX_BAIHU       = 4,
    CREATUREINDEX_XUANWU      = 5
}CREATURE_INDEX;

typedef struct 
{
    GUA_INDEX    Index;
    const char * Name;
    const char * Yao[3];
    const char * element;
}PUREGUA;

typedef struct 
{
    GUA_INDEX GongIndex;
    const char * Name;
    const char * Yao[6];
    YAOWEI_INDEX YaoWeiIndex[6];
    const char * element;
}DOUBLEGUA;

typedef struct 
{
    const char * Yao[6];
}RESULTGUA;

extern bool  get_gua_name(GUA_INDEX gua,char * name);
extern void dump_gua( const PUREGUA * gua);
extern void dump_doublegua(const DOUBLEGUA * gua);
#endif//_LIUYAO_DEF_HXX_