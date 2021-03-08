#ifndef _YIMA_HXX_
#define _YIMA_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Yima:public ShenshaBase
        {
        private:
            static Yima * _yimas[];
            int _yimaIndex;
            Yima(int index);
            static void init();
        public:
            static Yima& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_YIMA_HXX_