#ifndef _QIGUA_GAN_ZHI_HXX_
#define _QIGUA_GAN_ZHI_HXX_
#include "TianganDizhi.hxx"
namespace Zhouyi{


class DateTime{
protected:
    TianganDizhi * ganzhi[4];
    DateTime(TIANGAN_ID yg,DIZHI_ID yz,TIANGAN_ID mg,DIZHI_ID mz,TIANGAN_ID dg,DIZHI_ID dz,TIANGAN_ID sg,DIZHI_ID sz);
    
public:
    static DateTime * now();
    static DateTime * create(int year,int month,int day,int shi);
    static DateTime * create(int year,int month,int day);
    static DateTime * create(DIZHI_ID month,TIANGAN_ID daygan,DIZHI_ID dayzhi);
    TianganDizhi * year();
    TianganDizhi * month();
    TianganDizhi * day();
    TianganDizhi * shi();
};




}
#endif//_QIGUA_GAN_ZHI_HXX_