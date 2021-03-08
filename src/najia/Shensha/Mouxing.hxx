#ifndef _MOUXING_HXX_
#define _MOUXING_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Mouxing:public ShenshaBase
        {
        private:
            static Mouxing * _mouxings[];
            int _mouxingIndex;
            Mouxing(int index);
            static void init();
        public:
            static Mouxing& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_MOUXING_HXX_