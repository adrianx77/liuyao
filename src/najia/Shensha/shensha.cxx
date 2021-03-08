#include "shensha.hxx"
#include "../../najia/TianganDizhi.hxx"
#include "Guiren.hxx"
#include "Lushen.hxx"
#include "Yangren.hxx"
#include "Wenchang.hxx"
#include "Yima.hxx"
#include "Xianchi.hxx"
#include "Jiangxing.hxx"
#include "Jiesha.hxx"
#include "Huagai.hxx"
#include "Mouxing.hxx"
#include "Tianyi.hxx"
#include "Tianxi.hxx"
#include "Zaisha.hxx"


#define SHENSHA_GUIREN      "贵人"
#define SHENSHA_LUSHEN      "禄神"
#define SHENSHA_YANGREN     "羊刃"
#define SHENSHA_WENCHANG    "文昌"
#define SHENSHA_YIMA        "驿马"
#define SHENSHA_TAOHUA      "桃花"
#define SHENSHA_JIANGXING   "将星"
#define SHENSHA_JIESHA      "劫煞"
#define SHENSHA_HUAGAI      "华盖"
#define SHENSHA_MOUXING     "谋星"
#define SHENSHA_TIANYI      "天医"
#define SHENSHA_TIANXI      "天喜"
#define SHENSHA_ZAISHA      "灾煞"
static const char * Names[] ={
    SHENSHA_GUIREN,
    SHENSHA_LUSHEN,
    SHENSHA_YANGREN,
    SHENSHA_WENCHANG,
    SHENSHA_YIMA,
    SHENSHA_TAOHUA,
    SHENSHA_JIANGXING,
    SHENSHA_JIESHA,
    SHENSHA_HUAGAI,
    SHENSHA_MOUXING,
    SHENSHA_TIANYI,
    SHENSHA_TIANXI,
    SHENSHA_ZAISHA
};
namespace Zhouyi{
    namespace Shensha
    {

        const char * ShenshaBase::name()
        {
            return Names[_id];
        }

        const char * ShenshaBase::zhiname()
        {
            return NULL;
        }

        ShenshaBase* ShenshaFactory::create(SHENSHA_ID id,TianganDizhi *month, TianganDizhi * day)
        {
            switch (id)
            {
            case SSID_GUIREN:
                return &Guiren::from(month,day);
            case SSID_LUSHEN:
                return &Lushen::from(month,day);
            case SSID_YANGREN:
                return &Yangren::from(month,day);                
            case SSID_WENCHANG:
                return &Wenchang::from(month,day);                         
            case SSID_YIMA:
                return &Yima::from(month,day);                         
            case SSID_TAOHUA:
                return &Xianchi::from(month,day);                         
            case SSID_JIANGXING:
                return &Jiangxing::from(month,day);                         
            case SSID_JIESHA:
                return &Jiesha::from(month,day);                         
            case SSID_HUAGAI:
                return &Huagai::from(month,day);                         
            case SSID_MOUXING:
                return &Mouxing::from(month,day);                         
            case SSID_TIANYI:
                return &Tianyi::from(month,day);                         
            case SSID_TIANXI:
                return &Tianxi::from(month,day);                         
            case SSID_ZAISHA:
                return &Zaisha::from(month,day);                         
            default:
                break;
            }            
            return NULL;
        }



    }
}