#include "Wenchang.hxx"
#include "../../base/Error.hxx"
#define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))

namespace Zhouyi
{
namespace Shensha{

static bool _wenchang_init = false;

static TIANGAN_ZHI1 WenchangTable [] = {
    {TGID_JIA,DZID_SI,ZHI_SI},
    {TGID_YI,DZID_WU, ZHI_WU},
    {TGID_BING,DZID_SHEN,ZHI_SHEN},
    {TGID_DING,DZID_YOU,ZHI_YOU},
    {TGID_WU,DZID_SHEN,ZHI_SHEN},
    {TGID_JI,DZID_YOU,ZHI_SI},
    {TGID_GEN,DZID_HAI,ZHI_HAI},
    {TGID_XIN,DZID_ZI,ZHI_ZI},
    {TGID_REN,DZID_YIN,ZHI_YIN},
    {TGID_GUI,DZID_MAO,ZHI_MAO}
};

Wenchang * Wenchang::_wenchangs[10] = {};

    Wenchang::Wenchang(int index)
    {
        _id = SSID_WENCHANG;
        _wenchangIndex = index;
    }
    const char * Wenchang::zhiname()
    {
        return WenchangTable[_wenchangIndex].zhiname;
    }
    Wenchang& Wenchang::from(TianganDizhi * month,TianganDizhi * day)
    {
        init();
        TIANGAN_ID chankao = day->get_tiangan().id();
        for(int i=0;i<COUNTOF(WenchangTable);i++)
        {
            if(WenchangTable[i].gan == chankao)
                return *_wenchangs[i];
        }
        throw Error(ERROR_INVALID);
    }

    void Wenchang::init()
    {
        if(_wenchang_init)
            return;

        for(int i=0;i<COUNTOF(WenchangTable);i++)
        {
            _wenchangs[i] = new Wenchang(i);
        }
        _wenchang_init = true;
    }


}
}