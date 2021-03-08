#ifndef _ZHUANGGUA_JIEGUO_HXX_
#define _ZHUANGGUA_JIEGUO_HXX_
#include "Liuqin.hxx"
#include "LiuqinChonggua.hxx"
#include "liushen.hxx"
#include <string>
#include "Shensha/shensha.hxx"
namespace Zhouyi{


class ZhuangguaJieguo
{
private:
    LiuqinChonggua * _bengua;
    LiuqinChonggua * _zhigua;
    TianganDizhi   * _ganzhi[4];
    Liushen  *       _liushen[6];
    Shensha::ShenshaBase * _shengsha[13];
    ZhuangguaJieguo(LiuqinChonggua * ben, LiuqinChonggua *bian,TianganDizhi * gz[4],Liushen * startLiushen);
public:
    static ZhuangguaJieguo * from(LiuqinChonggua * ben, LiuqinChonggua *bian,Lunar * lunar);
    Liushen * liushen(int pos);
    void dum(std::string & str);
};



}
#endif//_ZHUANGGUA_JIEGUO_HXX_