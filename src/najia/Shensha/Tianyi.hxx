#ifndef _TIANYI_HXX_
#define _TIANYI_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Tianyi:public ShenshaBase
        {
        private:
            static Tianyi * _tianyis[];
            int _tianyiIndex;
            Tianyi(int index);
            static void init();
        public:
            static Tianyi& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_TIANYI_HXX_