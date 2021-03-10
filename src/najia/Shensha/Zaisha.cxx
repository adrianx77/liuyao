#include "Zaisha.hxx"
#include "../../base/Error.hxx"
#include "../../base/basic.hxx"
// #define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _zaisha_init = false;

static DIZHI_ZHI1 ZaishaTable [] = {
    //申子辰
    {DZID_SHEN,DZID_WU,ZHI_WU},
    {DZID_ZI,DZID_WU, ZHI_WU},
    {DZID_CHEN,DZID_WU,ZHI_WU},

    //巳酉丑
    {DZID_SI,DZID_MAO,ZHI_MAO},
    {DZID_YOU,DZID_MAO,ZHI_MAO},
    {DZID_CHOU,DZID_MAO,ZHI_MAO},

    //寅午戌
    {DZID_YIN,DZID_ZI,ZHI_ZI},
    {DZID_WU,DZID_ZI,ZHI_ZI},
    {DZID_XU,DZID_ZI,ZHI_ZI},

    //亥卯未
    {DZID_HAI,DZID_YOU,ZHI_YOU},
    {DZID_MAO,DZID_YOU,ZHI_YOU},
    {DZID_WEI,DZID_YOU,ZHI_YOU}
};

Zaisha * Zaisha::_zaishas[12] = {};

Zaisha::Zaisha(int index)
{
    _id = SSID_ZAISHA;
    _zaishaIndex = index;
}
const char * Zaisha::zhiname()
{
    return ZaishaTable[_zaishaIndex].zhiname;
}
Zaisha& Zaisha::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<countof(ZaishaTable);i++)
    {
        if(ZaishaTable[i].timezhi == chankao)
            return *_zaishas[i];
    }
    throw Error(ERROR_INVALID);
}

void Zaisha::init()
{
    if(_zaisha_init)
        return;

    for(int i=0;i<countof(ZaishaTable);i++)
    {
        _zaishas[i] = new Zaisha(i);
    }
    _zaisha_init = true;
}


}
}