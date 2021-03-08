#ifndef _GUIREN_HXX_
#define _GUIREN_HXX_
#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Guiren:public ShenshaBase
        {
        private:
            static Guiren * _guirens[];
            int _guirenIndex;
            Guiren(int index);
            static void init();
        public:
            static Guiren& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}

#endif//_GUIREN_HXX_
