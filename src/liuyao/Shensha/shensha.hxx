#ifndef _SHEN_SHA_HXX_
#define _SHEN_SHA_HXX_
#include "../../najia/TianganDizhi.hxx"

namespace Zhouyi
{
    namespace Shensha
    {
        typedef enum{
            SSID_GUIREN,
            SSID_LUSHEN,
            SSID_YANGREN,
            SSID_WENCHANG,
            SSID_YIMA,
            SSID_TAOHUA,
            SSID_JIANGXIN,
            SSID_JIESHA,
            SSID_HUAGAI,
            SSID_MOUXIN,
            SSID_TIANYI,
            SSID_TIANXI,
            SSID_ZAISHA
        }SHENSHA_ID;

        typedef struct 
        {
            TIANGAN_ID gan;     //日干
            DIZHI_ID   zhi[2];  //爻支
            const char * zhiname;
        }TIANGAN_ZHI;

        typedef struct 
        {
            DIZHI_ID    timezhi;     //日月支
            DIZHI_ID    zhi[2];  //爻支
            const char * zhiname;
        }DIZHI_ZHI;



    class ShenshaBase
    {
    protected:
        SHENSHA_ID _id;
    public:
        SHENSHA_ID id();
        virtual const char * name();
        virtual const char * zhiname();
    };

    class ShenshaFactory
    {
    public:
        static ShenshaBase* create(SHENSHA_ID id,TianganDizhi *month, TianganDizhi * day);
    };

    }//Shensha
}//Zhoyi

#endif//_SHEN_SHA_HXX_