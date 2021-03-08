#include "Tianxi.hxx"
#include "../../base/Error.hxx"
#define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _tianxi_init = false;

static DIZHI_ZHI1 TianxiTable [] = {
    {DZID_YIN, DZID_XU,  ZHI_XU},
    {DZID_MAO, DZID_XU,  ZHI_XU},
    {DZID_CHEN,DZID_XU,  ZHI_XU},
    {DZID_SI,  DZID_CHOU,ZHI_CHOU},
    {DZID_WU,  DZID_CHOU,ZHI_CHOU },
    {DZID_WEI, DZID_CHOU,ZHI_CHOU },
    {DZID_SHEN,DZID_CHEN,ZHI_CHEN},
    {DZID_YOU, DZID_CHEN,ZHI_CHEN},
    {DZID_XU,  DZID_CHEN,ZHI_CHEN},
    {DZID_HAI, DZID_WEI, ZHI_WEI },
    {DZID_ZI,  DZID_WEI, ZHI_WEI},
    {DZID_CHOU,DZID_WEI, ZHI_WEI }
};                       

Tianxi * Tianxi::_tianxis[12] = {};

Tianxi::Tianxi(int index)
{
    _id = SSID_TIANXI;
    _tianxiIndex = index;
}
const char * Tianxi::zhiname()
{
    return TianxiTable[_tianxiIndex].zhiname;
}
Tianxi& Tianxi::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<COUNTOF(TianxiTable);i++)
    {
        if(TianxiTable[i].timezhi == chankao)
            return *_tianxis[i];
    }
    throw Error(ERROR_INVALID);
}

void Tianxi::init()
{
    if(_tianxi_init)
        return;

    for(int i=0;i<COUNTOF(TianxiTable);i++)
    {
        _tianxis[i] = new Tianxi(i);
    }
    _tianxi_init = true;
}


}
}