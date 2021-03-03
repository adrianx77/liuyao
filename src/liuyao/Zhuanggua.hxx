#ifndef _ZHUANG_GUA_HXX_
#define _ZHUANG_GUA_HXX_

#include "../najia/Lunar.hxx"
#include "ZhuangguaJieguo.hxx"
#include "Yao.hxx"

namespace Zhouyi{
    
class Zhuanggua
{
private:

public:
    static ZhuangguaJieguo * zhuanggua(YAO_ID yaos[6],Lunar * lunar);
    static ZhuangguaJieguo * zhuanggua(YAO_ID yaos[6]);
};





}




#endif//_ZHUANG_GUA_YAO_HXX_