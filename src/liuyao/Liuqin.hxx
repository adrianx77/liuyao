#ifndef _LIUQIN_HXX_
#define _LIUQIN_HXX_
#include "../najia/TianganDizhi.hxx"
#define LIUQIN_XIONGDI   "兄弟"
#define LIUQIN_FUMU      "父母"
#define LIUQIN_GUANGUI   "官鬼"
#define LIUQIN_QICAI     "妻财"
#define LIUQIN_ZISUN     "子孙"

namespace Zhouyi{

typedef enum{
    LQID_XIONGDI,
    LQID_FUMU,
    LQID_GUANGUI,
    LQID_QICAI,
    LQID_ZISUN
}LIUQIN_ID;

class Liuqin{
protected:
    LIUQIN_ID    _liuqin;
    static const char * _names[];
    static Liuqin * _liuqins[];
//初始化
    static bool _init;
    static void init();
    Liuqin(LIUQIN_ID lq);
public:
    static Liuqin & from(LIUQIN_ID lq);
    static Liuqin & from(Dizhi& wo, Dizhi & ta);
    static Liuqin & from(WUXING_ID wo,WUXING_ID ta);
    LIUQIN_ID  id()const;
    operator LIUQIN_ID() const;
    const char * get_name();
};


}


#endif//_LIUQIN_HXX_