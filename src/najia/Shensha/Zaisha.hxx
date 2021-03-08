#ifndef _ZAISHA_HXX_
#define _ZAISHA_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Zaisha:public ShenshaBase
        {
        private:
            static Zaisha * _zaishas[];
            int _zaishaIndex;
            Zaisha(int index);
            static void init();
        public:
            static Zaisha& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_ZAISHA_HXX_