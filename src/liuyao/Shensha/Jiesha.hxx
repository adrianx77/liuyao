#ifndef _JIESHA_HXX_
#define _JIESHA_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Jiesha:public ShenshaBase
        {
        private:
            static Jiesha * _jieshas[];
            int _jieshaIndex;
            Jiesha(int index);
            static void init();
        public:
            static Jiesha& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_JIESHA_HXX_