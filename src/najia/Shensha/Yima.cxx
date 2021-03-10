#include "Yima.hxx"
#include "../../base/Error.hxx"
#include "../../base/basic.hxx"
// #define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _yima_init = false;

static DIZHI_ZHI1 YimaTable [] = {
    //申子辰
    {DZID_SHEN,DZID_YIN,ZHI_YIN},
    {DZID_ZI,DZID_YIN, ZHI_YIN},
    {DZID_CHEN,DZID_YIN,ZHI_YIN},

    //巳酉丑
    {DZID_SI,DZID_HAI,ZHI_HAI},
    {DZID_YOU,DZID_HAI,ZHI_HAI},
    {DZID_CHOU,DZID_HAI,ZHI_HAI},

    //寅午戌
    {DZID_YIN,DZID_SHEN,ZHI_SHEN},
    {DZID_WU,DZID_SHEN,ZHI_SHEN},
    {DZID_XU,DZID_SHEN,ZHI_SHEN},

    //亥卯未
    {DZID_HAI,DZID_SI,ZHI_SI},
    {DZID_MAO,DZID_SI,ZHI_SI},
    {DZID_WEI,DZID_SI,ZHI_SI}
};

Yima * Yima::_yimas[12] = {};

Yima::Yima(int index)
{
    _id = SSID_YIMA;
    _yimaIndex = index;
}
const char * Yima::zhiname()
{
    return YimaTable[_yimaIndex].zhiname;
}
Yima& Yima::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<countof(YimaTable);i++)
    {
        if(YimaTable[i].timezhi == chankao)
            return *_yimas[i];
    }
    throw Error(ERROR_INVALID);
}

void Yima::init()
{
    if(_yima_init)
        return;

    for(int i=0;i<countof(YimaTable);i++)
    {
        _yimas[i] = new Yima(i);
    }
    _yima_init = true;
}


}
}