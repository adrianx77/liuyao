#ifndef _XIANCHI_HXX_
#define _XIANCHI_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Xianchi:public ShenshaBase
        {
        private:
            static Xianchi * _xianchis[];
            int _xianchiIndex;
            Xianchi(int index);
            static void init();
        public:
            static Xianchi& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_XIANCHI_HXX_