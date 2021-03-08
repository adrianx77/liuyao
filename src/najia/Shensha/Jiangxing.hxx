#ifndef _JIANGXING_HXX_
#define _JIANGXING_HXX_

#include "shensha.hxx"
namespace Zhouyi
{
    namespace Shensha
    {


        class Jiangxing:public ShenshaBase
        {
        private:
            static Jiangxing * _jiangxings[];
            int _jiangxingIndex;
            Jiangxing(int index);
            static void init();
        public:
            static Jiangxing& from(TianganDizhi * month,TianganDizhi * day);
            const char * zhiname();
        };
    }
}



#endif//_JIANGXING_HXX_