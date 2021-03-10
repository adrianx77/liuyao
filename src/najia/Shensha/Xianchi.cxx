#include "Xianchi.hxx"
#include "../../base/Error.hxx"
#include "../../base/basic.hxx"
// #define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _xianchi_init = false;

static DIZHI_ZHI1 XianchiTable [] = {
    //申子辰
    {DZID_SHEN,DZID_YOU,ZHI_YOU},
    {DZID_ZI,DZID_YOU, ZHI_YOU},
    {DZID_CHEN,DZID_YOU,ZHI_YOU},

    //巳酉丑
    {DZID_SI,DZID_WU,ZHI_WU},
    {DZID_YOU,DZID_WU,ZHI_WU},
    {DZID_CHOU,DZID_WU,ZHI_WU},

    //寅午戌
    {DZID_YIN,DZID_MAO,ZHI_MAO},
    {DZID_WU,DZID_MAO,ZHI_MAO},
    {DZID_XU,DZID_MAO,ZHI_MAO},

    //亥卯未
    {DZID_HAI,DZID_ZI,ZHI_ZI},
    {DZID_MAO,DZID_ZI,ZHI_ZI},
    {DZID_WEI,DZID_ZI,ZHI_ZI}
};

Xianchi * Xianchi::_xianchis[12] = {};

Xianchi::Xianchi(int index)
{
    _id = SSID_TAOHUA;
    _xianchiIndex = index;
}
const char * Xianchi::zhiname()
{
    return XianchiTable[_xianchiIndex].zhiname;
}
Xianchi& Xianchi::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<countof(XianchiTable);i++)
    {
        if(XianchiTable[i].timezhi == chankao)
            return *_xianchis[i];
    }
    throw Error(ERROR_INVALID);
}

void Xianchi::init()
{
    if(_xianchi_init)
        return;

    for(int i=0;i<countof(XianchiTable);i++)
    {
        _xianchis[i] = new Xianchi(i);
    }
    _xianchi_init = true;
}


}
}