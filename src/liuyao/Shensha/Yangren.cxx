#include "Yangren.hxx"
#include "../../base/Error.hxx"
#define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _yangren_init = false;

static TIANGAN_ZHI1 YangrenTable [] = {
    {TGID_JIA,DZID_MAO,ZHI_MAO},
    {TGID_YI,DZID_YIN, ZHI_YIN},
    {TGID_BING,DZID_WU,ZHI_WU},
    {TGID_DING,DZID_SI,ZHI_SI},
    {TGID_WU,DZID_WU,ZHI_WU},
    {TGID_JI,DZID_SI,ZHI_SI},
    {TGID_GEN,DZID_YOU,ZHI_YOU},
    {TGID_XIN,DZID_SHEN,ZHI_SHEN},
    {TGID_REN,DZID_ZI,ZHI_ZI},
    {TGID_GUI,DZID_HAI,ZHI_HAI}
};

Yangren * Yangren::_yangrens[10] = {};

    Yangren::Yangren(int index)
    {
        _id = SSID_YANGREN;
        _yangrenIndex = index;
    }
    const char * Yangren::zhiname()
    {
        return YangrenTable[_yangrenIndex].zhiname;
    }
    Yangren& Yangren::from(TianganDizhi * month,TianganDizhi * day)
    {
        init();
        TIANGAN_ID chankao = day->get_tiangan().id();
        for(int i=0;i<COUNTOF(YangrenTable);i++)
        {
            if(YangrenTable[i].gan == chankao)
                return *_yangrens[i];
        }
        throw Error(ERROR_INVALID);
    }

    void Yangren::init()
    {
        if(_yangren_init)
            return;

        for(int i=0;i<COUNTOF(YangrenTable);i++)
        {
            _yangrens[i] = new Yangren(i);
        }
        _yangren_init = true;
    }


}
}