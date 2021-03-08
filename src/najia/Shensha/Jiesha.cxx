#include "Jiesha.hxx"
#include "../../base/Error.hxx"
#define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _jiesha_init = false;

static DIZHI_ZHI1 JieshaTable [] = {
    //申子辰
    {DZID_SHEN,DZID_SI,ZHI_SI},
    {DZID_ZI,DZID_SI, ZHI_SI},
    {DZID_CHEN,DZID_SI,ZHI_SI},

    //巳酉丑
    {DZID_SI,DZID_YIN,ZHI_YIN},
    {DZID_YOU,DZID_YIN,ZHI_YIN},
    {DZID_CHOU,DZID_YIN,ZHI_YIN},

    //寅午戌
    {DZID_YIN,DZID_HAI,ZHI_HAI},
    {DZID_WU,DZID_HAI,ZHI_HAI},
    {DZID_XU,DZID_HAI,ZHI_HAI},

    //亥卯未
    {DZID_HAI,DZID_SHEN,ZHI_SHEN},
    {DZID_MAO,DZID_SHEN,ZHI_SHEN},
    {DZID_WEI,DZID_SHEN,ZHI_SHEN}
};

Jiesha * Jiesha::_jieshas[12] = {};

Jiesha::Jiesha(int index)
{
    _id = SSID_JIESHA;
    _jieshaIndex = index;
}
const char * Jiesha::zhiname()
{
    return JieshaTable[_jieshaIndex].zhiname;
}
Jiesha& Jiesha::from(TianganDizhi * month,TianganDizhi * day)
{
    init();
    DIZHI_ID chankao = day->get_dizhi().id();
    for(int i=0;i<COUNTOF(JieshaTable);i++)
    {
        if(JieshaTable[i].timezhi == chankao)
            return *_jieshas[i];
    }
    throw Error(ERROR_INVALID);
}

void Jiesha::init()
{
    if(_jiesha_init)
        return;

    for(int i=0;i<COUNTOF(JieshaTable);i++)
    {
        _jieshas[i] = new Jiesha(i);
    }
    _jiesha_init = true;
}


}
}