#ifndef _NAJIA_H_XX_
#define _NAJIA_H_XX_

#include "Tiangan.hxx"
#include "Dizhi.hxx"

namespace Zhouyi{
    

    class TianganDizhi;
    class XunKong
    {
        XunKong(DIZHIID dz1,DIZHIID dz2,int index)
        {

        }
        DIZHIID _Dizhi1;
        DIZHIID _Dizhi2;
        int     _index;
    public:
        static XunKong * from(DIZHIID x);
        const char * get_name();
        static const char *  _names[];
        static XunKong _xunkong[];
    };

    class Xun
    {
        Xun(TIANGANID xg,DIZHIID xz);
        static bool _inited;
        TIANGANID    _gan;
        DIZHIID      _zhi;
        XunKong * _xunkong;
        static void init();
        static Xun * _xun[];
        static const char * _names[];
    public:
        XunKong * get_xunkong();
        const char * get_name();
        friend TianganDizhi;
        static Xun* from(TIANGANID xg,DIZHIID xz);
    };


    //天干地支
    class TianganDizhi{
    protected:
        TianganDizhi(TIANGANID gan,DIZHIID zhi,TIANGANID xg,DIZHIID xz);
        TIANGANID   _tiangan;
        DIZHIID     _dizhi;
        Xun *       _xun;
        static const char * _ganzi_name[][6];
        static TianganDizhi _ganzhi[][6];
    public:
        const char * get_name();
        static TianganDizhi * from(TIANGANID gan,DIZHIID zhi);
        TianganDizhi * get_next();
        TianganDizhi * get_prev();
        Xun* get_xun();
    };


}
#endif//_NAJIA_H_XX_
