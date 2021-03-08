#include "Guiren.hxx"
#include "../../base/Error.hxx"
#define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _guiren_init = false;

static TIANGAN_ZHI2 GuiRenTable [] = {
    {TGID_JIA,{DZID_CHOU,DZID_WEI}, ZHI_CHOU "," ZHI_WEI },
    {TGID_WU,{DZID_CHOU,DZID_WEI},ZHI_CHOU "," ZHI_WEI},
    {TGID_YI,{DZID_ZI,DZID_SHEN},ZHI_ZI "," ZHI_SHEN},
    {TGID_JI,{DZID_ZI,DZID_SHEN},ZHI_ZI "," ZHI_SHEN},
    {TGID_BING,{DZID_HAI,DZID_YOU},ZHI_HAI "," ZHI_YOU},
    {TGID_DING,{DZID_HAI,DZID_YOU},ZHI_HAI "," ZHI_YOU},
    {TGID_REN,{DZID_MAO,DZID_SI},ZHI_MAO "," ZHI_SI},
    {TGID_GUI,{DZID_MAO,DZID_SI},ZHI_MAO "," ZHI_SI},
    {TGID_GEN,{DZID_WU,DZID_YIN},ZHI_WU "," ZHI_YIN},
    {TGID_XIN,{DZID_WU,DZID_YIN},ZHI_WU "," ZHI_YIN}
};
    Guiren * Guiren::_guirens[10] = {};

    Guiren::Guiren(int index)
    {
        _id = SSID_GUIREN;
        _guirenIndex = index;
    }
    const char * Guiren::zhiname()
    {
        return GuiRenTable[_guirenIndex].zhiname;
    }
    Guiren& Guiren::from(TianganDizhi * month,TianganDizhi * day)
    {
        init();
        TIANGAN_ID chankao = day->get_tiangan().id();
        for(int i=0;i<COUNTOF(GuiRenTable);i++)
        {
            if(GuiRenTable[i].gan == chankao)
                return *_guirens[i];
        }
        throw Error(ERROR_INVALID);
    }

    void Guiren::init()
    {
        if(_guiren_init)
            return;

        for(int i=0;i<COUNTOF(GuiRenTable);i++)
        {
            _guirens[i] = new Guiren(i);
        }
        _guiren_init = true;
    }


}    
}
