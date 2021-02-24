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
    public:
        void init();
        static Xun * _xun[];
        static Xun* from(TIANGANID xg,DIZHIID xz);
    };


    //天干地支
    class TianganDizhi{
    protected:
        TianganDizhi(TIANGANID gan,DIZHIID zhi,TIANGANID xg,DIZHIID xz){
            _tiangan = gan;
            _dizhi   = zhi;
            printf("%d %d\n",gan,zhi);
            _xun = Xun::from(xg,xz);
        }
    public:
        bool get_name(char * sbName);
        static const char * _ganzi_name[][6];
        static TianganDizhi _ganzhi[][6];
        
        static TianganDizhi * from(TIANGANID gan,DIZHIID zhi);

        TIANGANID   _tiangan;
        DIZHIID     _dizhi;
        Xun *       _xun;
        static TianganDizhi * get_next(TianganDizhi * gz);
        static TianganDizhi * get_prev(TianganDizhi * gz);
        static XunKong* get_xunkong(TianganDizhi * gz);
    };


}
#endif//_NAJIA_H_XX_
