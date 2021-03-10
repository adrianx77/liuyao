#include "Mouxing.hxx"
#include "../../base/Error.hxx"
#include "../../base/basic.hxx"
// #define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _mouxing_init = false;

static DIZHI_ZHI1 MouxingTable [] = {
    //申子辰
    {DZID_SHEN,DZID_XU,ZHI_XU},
    {DZID_ZI,DZID_XU, ZHI_XU},
    {DZID_CHEN,DZID_XU,ZHI_XU},

    //巳酉丑
    {DZID_SI,DZID_WEI,ZHI_WEI},
    {DZID_YOU,DZID_WEI,ZHI_WEI},
    {DZID_CHOU,DZID_WEI,ZHI_WEI},

    //寅午戌
    {DZID_YIN,DZID_CHEN,ZHI_CHEN},
    {DZID_WU,DZID_CHEN,ZHI_CHEN},
    {DZID_XU,DZID_CHEN,ZHI_CHEN},

    //亥卯未
    {DZID_HAI,DZID_CHOU,ZHI_CHOU},
    {DZID_MAO,DZID_CHOU,ZHI_CHOU},
    {DZID_WEI,DZID_CHOU,ZHI_CHOU}
};

Mouxing * Mouxing::_mouxings[12] = {};

Mouxing::Mouxing(int index)
{
    _id = SSID_MOUXING;
    _mouxingIndex = index;
}
const char * Mouxing::zhiname()
{
    return MouxingTable[_mouxingIndex].zhiname;
}
Mouxing& Mouxing::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<countof(MouxingTable);i++)
    {
        if(MouxingTable[i].timezhi == chankao)
            return *_mouxings[i];
    }
    throw Error(ERROR_INVALID);
}

void Mouxing::init()
{
    if(_mouxing_init)
        return;

    for(int i=0;i<countof(MouxingTable);i++)
    {
        _mouxings[i] = new Mouxing(i);
    }
    _mouxing_init = true;
}


}
}