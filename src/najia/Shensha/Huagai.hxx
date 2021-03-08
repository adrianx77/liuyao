#ifndef _HUAGAI_HXX_
#define _HUAGAI_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Huagai:public ShenshaBase
        {
        private:
            static Huagai * _huagais[];
            int _huagaiIndex;
            Huagai(int index);
            static void init();
        public:
            static Huagai& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_HUAGAI_HXX_