#ifndef _TIANXI_HXX_
#define _TIANXI_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Tianxi:public ShenshaBase
        {
        private:
            static Tianxi * _tianxis[];
            int _tianxiIndex;
            Tianxi(int index);
            static void init();
        public:
            static Tianxi& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_TIANXI_HXX_