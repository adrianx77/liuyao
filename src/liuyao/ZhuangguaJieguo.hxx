#ifndef _ZHUANGGUA_JIEGUO_HXX_
#define _ZHUANGGUA_JIEGUO_HXX_
#include "Liuqin.hxx"
#include "LiuqinChonggua.hxx"
#include "liushen.hxx"
#include <string>
#include "../najia/Shensha/shensha.hxx"
namespace Zhouyi{

using namespace Shensha;
class ZhuangguaJieguo
{
private:
    LiuqinChonggua * _bengua;
    LiuqinChonggua * _zhigua;
    TianganDizhi   * _ganzhi[GZI_MAX];
    Liushen  *       _liushen[LSID_MAX];
    ShenshaBase *    _shengsha[SSID_MAX];
    ZhuangguaJieguo(LiuqinChonggua * ben, LiuqinChonggua *bian,TianganDizhi * gz[GZI_MAX],Liushen * startLiushen);
public:
    static ZhuangguaJieguo * from(LiuqinChonggua * ben, LiuqinChonggua *bian,Lunar * lunar);
    static ZhuangguaJieguo * from(LiuqinChonggua * ben, LiuqinChonggua *bian,TianganDizhi * gz[GZI_MAX]);

    //六神（六兽）
    Liushen * liushen(int pos);

    //神煞
    ShenshaBase * shensha(SHENSHA_ID id);
    size_t  shensha_count();
    //卜卦时间
    TianganDizhi * year();
    TianganDizhi * month();
    TianganDizhi * day();
    TianganDizhi * hour();

    //本卦
    LiuqinChonggua * bengua();
    LiuqinChonggua * zhigua();

    // 爻
    Dizhi * yao_zhi(int pos);
    bool    yao_bian(int pos);  //是否为变
    Dizhi * bian_zhi(int pos);

    void dum(std::string & str);
};



}
#endif//_ZHUANGGUA_JIEGUO_HXX_