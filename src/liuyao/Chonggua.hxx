#ifndef _CHONG_GUA_HXX_
#define _CHONG_GUA_HXX_
#include "Gua.hxx"
#include "Guayao.hxx"

#define YAOWEI_SHI     "世"
#define YAOWEI_YING    "应"
#define YAOWEI_KONG    "　"


#define GUAXING_LIUCHONG    "六冲"
#define GUAXING_LIUCHE      "六合"
#define GUAXING_YOUHUN      "游魂"
#define GUAXING_GUIHUN      "归魂"

namespace Zhouyi{
typedef enum {
    YWID_KONG,
    YWID_SHI,
    YWID_YING
}SHIYING_ID;

typedef enum{
    GXID_KONG,
    GXID_LIUCHONG,
    GXID_LIUHE,
    GXID_YOUHUN,
    GXID_GUIHUN
}GUAXING_ID;


class Chonggua{
    Chonggua();
protected:
    int  _shiwei;
    int  _yingwei;
    const char * _name;
    GuaYao * _guayao[6];
    Gua& _shanggua;
    Gua& _xiagua;
    Wuxing& _wuxing;
    GUAXING_ID _guaxing;
    static Chonggua * _chonggua[8][8];

//初始化
    static bool _init;
    Chonggua(BAGUA_ID sgid,BAGUA_ID xgid,int s,int y,WUXING_ID wx,GUAXING_ID gx,const char * name);
public:
    static void init();
    static Chonggua & from(BAGUA_ID sgid,BAGUA_ID xgid);
    const char* get_guaxing_name();
    const char* get_name();
};

}
#endif//_CHONG_GUA_HXX_
