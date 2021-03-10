#include "Lushen.hxx"
#include "../../base/Error.hxx"
#include "../../base/basic.hxx"
// #define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _lushen_init = false;

static TIANGAN_ZHI1 LushenTable [] = {
    {TGID_JIA,DZID_YIN, ZHI_YIN},
    {TGID_YI,DZID_MAO,ZHI_MAO},
    {TGID_BING,DZID_SI,ZHI_SI},
    {TGID_DING,DZID_WU,ZHI_WU},
    {TGID_WU,DZID_SI,ZHI_SI},
    {TGID_JI,DZID_WU,ZHI_WU},
    {TGID_GEN,DZID_SHEN,ZHI_SHEN},
    {TGID_XIN,DZID_YOU,ZHI_YOU},
    {TGID_REN,DZID_HAI,ZHI_HAI},
    {TGID_GUI,DZID_ZI,ZHI_ZI}
};

Lushen * Lushen::_lushens[10] = {};

    Lushen::Lushen(int index)
    {
        _id = SSID_LUSHEN;
        _lushenIndex = index;
    }
    const char * Lushen::zhiname()
    {
        return LushenTable[_lushenIndex].zhiname;
    }
    Lushen& Lushen::from(TianganDizhi * month,TianganDizhi * day)
    {
        init();
        TIANGAN_ID chankao = day->get_tiangan().id();
        for(int i=0;i<countof(LushenTable);i++)
        {
            if(LushenTable[i].gan == chankao)
                return *_lushens[i];
        }
        throw Error(ERROR_INVALID);
    }

    void Lushen::init()
    {
        if(_lushen_init)
            return;

        for(int i=0;i<countof(LushenTable);i++)
        {
            _lushens[i] = new Lushen(i);
        }
        _lushen_init = true;
    }


}
}