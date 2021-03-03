#ifndef _LIUSHEN_DEF_HXX_
#define _LIUSHEN_DEF_HXX_
#include "../base/Wuxing.hxx"
#include "../najia/Lunar.hxx"
#define LIUSHEN_QINGLONG  "青龙"
#define LIUSHEN_ZHUQUE    "朱雀"
#define LIUSHEN_GOUCHEN   "勾陈"
#define LIUSHEN_TENGSHE   "螣蛇"
#define LIUSHEN_BAIHU     "白虎"
#define LIUSHEN_XUANWU    "玄武"

namespace Zhouyi{

typedef enum {
    LSID_QINGLONG    = 0,
    LSID_ZHUQUE      = 1,
    LSID_GOUCHEN     = 2,
    LSID_TENGSHE     = 3,
    LSID_BAIHU       = 4,
    LSID_XUANWU      = 5
}LIUSHEN_ID;

class Liushen{
private:
    LIUSHEN_ID _id;
    static void init();
    Liushen(LIUSHEN_ID id);
public:
    static Liushen * from(Lunar *lunar);
    LIUSHEN_ID   id();
    const char * name();
    Liushen * next();
};

}




#endif//_LIUSHEN_DEF_HXX_
