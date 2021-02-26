#ifndef _NAJIA_H_XX_
#define _NAJIA_H_XX_

#include "Tiangan.hxx"
#include "Dizhi.hxx"
#include "Xun.hxx"

namespace Zhouyi{
    
//天干地支
class TianganDizhi{
protected:
    TianganDizhi(Tiangan& gan,Dizhi& zhi,Tiangan& xg,Dizhi& xz);
    TianganDizhi(TIANGAN_ID gan,DIZHI_ID zhi,TIANGAN_ID xg,DIZHI_ID xz);
    Tiangan&   _tiangan;
    Dizhi&     _dizhi;
    Xun&       _xun;
    static const char * _ganzi_name[10][6];
    static TianganDizhi* _ganzhi[10][6];

    static bool _init;
    static void init();

public:
    const char * get_name()const;
    static TianganDizhi& from(Tiangan& gan,Dizhi& zhi);
    Tiangan&      get_tiangan()const {return _tiangan;}
    Dizhi&        get_dizhi()const {return _dizhi;}
    TianganDizhi & get_next();
    TianganDizhi & get_prev();
    Xun& get_xun();
};


}
#endif//_NAJIA_H_XX_
