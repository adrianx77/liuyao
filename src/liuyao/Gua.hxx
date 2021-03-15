#ifndef _GUA_HXX_
#define _GUA_HXX_
#include "Yao.hxx"
#include "../base/Wuxing.hxx"

#define GUANAME_QIAN   "乾"
#define GUANAME_DUI    "兑"
#define GUANAME_LI     "离"
#define GUANAME_ZHEN   "震"
#define GUANAME_XUN    "巽"
#define GUANAME_KAN    "坎"
#define GUANAME_GEN    "艮"
#define GUANAME_KUN    "坤"

namespace Zhouyi{
typedef enum{
    BGID_INVALID= -1,
    BGID_QIAN   = 0,
	BGID_DUI    = 1,
	BGID_LI     = 2, 
	BGID_ZHEN   = 3,
	BGID_XUN    = 4,
	BGID_KAN    = 5,
	BGID_GEN    = 6,
	BGID_KUN    = 7
}BAGUA_ID;

typedef enum{
    YWID_DI,
    YWID_REN,
    YWID_TIAN,
}YAOWEI_ID;



class Gua{
protected:
    BAGUA_ID _id;
    Wuxing & _wuxing;
    Yao * _yao[3];
    static Gua * _guas[];

    //初始化
    static bool _init;
    static void init();
    Gua(BAGUA_ID id);
public:
    static Gua & from(BAGUA_ID id);
    static Gua & from(YAO_ID _1,YAO_ID _2,YAO_ID _3);
    const char * name();
    Yao & yao(YAOWEI_ID yaowei);
    BAGUA_ID id();
};

}
#endif//_GUA_HXX_