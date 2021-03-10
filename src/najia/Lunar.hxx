#ifndef _QIGUA_GAN_ZHI_HXX_
#define _QIGUA_GAN_ZHI_HXX_
#include "TianganDizhi.hxx"
namespace Zhouyi{

typedef enum
{
    GZI_YEAR = 0,
    GZI_MONTH,
    GZI_DAY,
    GZI_HOUR,
    GZI_MAX
}GANZHI_INDEX;

class Lunar{
protected:
    TianganDizhi * _ganzhi[GZI_MAX];
    Lunar(TIANGAN_ID yg,DIZHI_ID yz,TIANGAN_ID mg,DIZHI_ID mz,TIANGAN_ID dg,DIZHI_ID dz,TIANGAN_ID sg,DIZHI_ID sz);
    
public:
    static Lunar * now();
    static Lunar * create(int year,int month,int day,int hour);
    static Lunar * create(int year,int month,int day);
    TianganDizhi * year();
    TianganDizhi * month();
    TianganDizhi * day();
    TianganDizhi * hour();
};




}
#endif//_QIGUA_GAN_ZHI_HXX_