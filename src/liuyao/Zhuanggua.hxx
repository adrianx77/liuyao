#ifndef _ZHUANG_GUA_HXX_
#define _ZHUANG_GUA_HXX_

#include "../najia/QiguaGanzhi.hxx"
#include "ZhuangguaJieguo.hxx"
#include "Yao.hxx"

namespace Zhouyi{
    
class Zhuanggua
{
private:

public:
    ZhuangguaJieguo * zhuanggua(YAO_ID yaos[6],DateTime * dt);
    ZhuangguaJieguo * zhuanggua(YAO_ID yaos[6]);
};





}




#endif//_ZHUANG_GUA_YAO_HXX_