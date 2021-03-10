#include "Tianyi.hxx"
#include "../../base/Error.hxx"
#include "../../base/basic.hxx"
// #define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _tianyi_init = false;

static DIZHI_ZHI1 TianyiTable [] = {
    {DZID_ZI,  DZID_HAI,ZHI_HAI},
    {DZID_CHOU,DZID_ZI,  ZHI_ZI },
    {DZID_YIN, DZID_CHOU,ZHI_CHOU},
    {DZID_MAO, DZID_YIN, ZHI_YIN},
    {DZID_CHEN,DZID_MAO, ZHI_MAO},
    {DZID_SI,  DZID_CHEN,ZHI_CHEN},
    {DZID_WU,  DZID_SI,  ZHI_SI },
    {DZID_WEI, DZID_WU,  ZHI_WU },
    {DZID_SHEN,DZID_WEI, ZHI_WEI},
    {DZID_YOU, DZID_SHEN,ZHI_SHEN},
    {DZID_XU,  DZID_YOU, ZHI_YOU},
    {DZID_HAI, DZID_XU,  ZHI_XU }
};                       

Tianyi * Tianyi::_tianyis[12] = {};

Tianyi::Tianyi(int index)
{
    _id = SSID_TIANYI;
    _tianyiIndex = index;
}
const char * Tianyi::zhiname()
{
    return TianyiTable[_tianyiIndex].zhiname;
}
Tianyi& Tianyi::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<countof(TianyiTable);i++)
    {
        if(TianyiTable[i].timezhi == chankao)
            return *_tianyis[i];
    }
    throw Error(ERROR_INVALID);
}

void Tianyi::init()
{
    if(_tianyi_init)
        return;

    for(int i=0;i<countof(TianyiTable);i++)
    {
        _tianyis[i] = new Tianyi(i);
    }
    _tianyi_init = true;
}


}
}