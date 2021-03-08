#ifndef _LUSHEN_HXX_
#define _LUSHEN_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Lushen:public ShenshaBase
        {
        private:
            static Lushen * _lushens[];
            int _lushenIndex;
            Lushen(int index);
            static void init();
        public:
            static Lushen& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_LUSHEN_HXX_