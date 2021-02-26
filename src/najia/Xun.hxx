#ifndef _XUN_HXX_
#define _XUN_HXX_
#include "Tiangan.hxx"
#include "Dizhi.hxx"
#include <vector>

namespace Zhouyi{

class TianganDizhi;
    class XunKong
    {
        XunKong(DIZHI_ID dz1,DIZHI_ID dz2,int index);
        DIZHI_ID _dizhi1;
        DIZHI_ID _dizhi2;
        int     _index;
    public:
        static XunKong& from(DIZHI_ID x);
        const char * get_name();
        static const char *  _names[];
        static XunKong _xunkong[];
    };
    
    class Xun
    {
        Xun(TIANGAN_ID xg,DIZHI_ID xz);
        static bool _inited;
        TIANGAN_ID    _gan;
        DIZHI_ID      _zhi;
        XunKong & _xunkong;
        static void init();
        static Xun * _xun[];
        static const char * _names[];
        std::vector<TianganDizhi*> _ganzhi;
    public:
        XunKong& get_xunkong();
        const char * get_name();
        friend TianganDizhi;
        static Xun& from(Tiangan& xg,Dizhi& xz);
        static Xun * * get_xun_table()
        {
            init();
            return _xun;
        }
        
        void dump_xun();
        void push_ganzhi(TianganDizhi *);
    };
}
#endif //_XUN_HXX_