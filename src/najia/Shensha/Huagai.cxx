#include "Huagai.hxx"
#include "../../base/Error.hxx"
#define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _huagai_init = false;

static DIZHI_ZHI1 HuagaiTable [] = {
    //申子辰
    {DZID_SHEN,DZID_CHEN,ZHI_CHEN},
    {DZID_ZI,DZID_CHEN, ZHI_CHEN},
    {DZID_CHEN,DZID_CHEN,ZHI_CHEN},

    //巳酉丑
    {DZID_SI,DZID_CHOU,ZHI_CHOU},
    {DZID_YOU,DZID_CHOU,ZHI_CHOU},
    {DZID_CHOU,DZID_CHOU,ZHI_CHOU},

    //寅午戌
    {DZID_YIN,DZID_XU,ZHI_XU},
    {DZID_WU,DZID_XU,ZHI_XU},
    {DZID_XU,DZID_XU,ZHI_XU},

    //亥卯未
    {DZID_HAI,DZID_WEI,ZHI_WEI},
    {DZID_MAO,DZID_WEI,ZHI_WEI},
    {DZID_WEI,DZID_WEI,ZHI_WEI}
};

Huagai * Huagai::_huagais[12] = {};

Huagai::Huagai(int index)
{
    _id = SSID_HUAGAI;
    _huagaiIndex = index;
}
const char * Huagai::zhiname()
{
    return HuagaiTable[_huagaiIndex].zhiname;
}
Huagai& Huagai::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<COUNTOF(HuagaiTable);i++)
    {
        if(HuagaiTable[i].timezhi == chankao)
            return *_huagais[i];
    }
    throw Error(ERROR_INVALID);
}

void Huagai::init()
{
    if(_huagai_init)
        return;

    for(int i=0;i<COUNTOF(HuagaiTable);i++)
    {
        _huagais[i] = new Huagai(i);
    }
    _huagai_init = true;
}


}
}