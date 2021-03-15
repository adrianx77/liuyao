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
    static ZhuangguaJieguo * zhuanggua(BAGUA_ID beng[2],BAGUA_ID bian[2],Lunar * lunar);
    static ZhuangguaJieguo * zhuanggua(BAGUA_ID beng[2],BAGUA_ID bian[2]);
};





}




#endif//_ZHUANG_GUA_YAO_HXX_