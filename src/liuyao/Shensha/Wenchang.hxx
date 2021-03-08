#ifndef _WENCHANG_HXX_
#define _WENCHANG_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Wenchang:public ShenshaBase
        {
        private:
            static Wenchang * _wenchangs[];
            int _wenchangIndex;
            Wenchang(int index);
            static void init();
        public:
            static Wenchang& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_WENCHANG_HXX_