#ifndef _YANGREN_HXX_
#define _YANGREN_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Yangren:public ShenshaBase
        {
        private:
            static Yangren * _yangrens[];
            int _yangrenIndex;
            Yangren(int index);
            static void init();
        public:
            static Yangren& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_YANGREN_HXX_