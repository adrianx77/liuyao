#include "Jiangxing.hxx"
#include "../../base/Error.hxx"
#include "../../base/basic.hxx"
// #define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _jiangxing_init = false;

static DIZHI_ZHI1 JiangxingTable [] = {
    //申子辰
    {DZID_SHEN,DZID_ZI,ZHI_ZI},
    {DZID_ZI,DZID_ZI, ZHI_ZI},
    {DZID_CHEN,DZID_ZI,ZHI_ZI},

    //巳酉丑
    {DZID_SI,DZID_YOU,ZHI_YOU},
    {DZID_YOU,DZID_YOU,ZHI_YOU},
    {DZID_CHOU,DZID_YOU,ZHI_YOU},

    //寅午戌
    {DZID_YIN,DZID_WU,ZHI_WU},
    {DZID_WU,DZID_WU,ZHI_WU},
    {DZID_XU,DZID_WU,ZHI_WU},

    //亥卯未
    {DZID_HAI,DZID_MAO,ZHI_MAO},
    {DZID_MAO,DZID_MAO,ZHI_MAO},
    {DZID_WEI,DZID_MAO,ZHI_MAO}
};

Jiangxing * Jiangxing::_jiangxings[12] = {};

Jiangxing::Jiangxing(int index)
{
    _id = SSID_JIANGXING;
    _jiangxingIndex = index;
}
const char * Jiangxing::zhiname()
{
    return JiangxingTable[_jiangxingIndex].zhiname;
}
Jiangxing& Jiangxing::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<countof(JiangxingTable);i++)
    {
        if(JiangxingTable[i].timezhi == chankao)
            return *_jiangxings[i];
    }
    throw Error(ERROR_INVALID);
}

void Jiangxing::init()
{
    if(_jiangxing_init)
        return;

    for(int i=0;i<countof(JiangxingTable);i++)
    {
        _jiangxings[i] = new Jiangxing(i);
    }
    _jiangxing_init = true;
}


}
}