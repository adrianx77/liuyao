#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tiangan.hxx"
#include "../base/Error.hxx"
namespace Zhouyi{
    const char * Tiangan::_names[] = {GAN_JIA, GAN_YI,GAN_BING,GAN_DING,GAN_WU,GAN_JI,GAN_GENG,GAN_XIN,GAN_REN,GAN_GUI};
    Tiangan Tiangan::_tiangans[] = {
        {TGID_JIA},{TGID_YI},{TGID_BING},{TGID_DING},{TGID_WU},{TGID_JI},{TGID_GEN},{TGID_XIN},{TGID_REN},{TGID_GUI}
    };
    WUXING_ID Tiangan::_Wuxings[] = {
        WXID_MU,WXID_MU,WXID_HUO,WXID_HUO,WXID_TU,WXID_TU,WXID_JIN,WXID_JIN,WXID_SHUI,WXID_SHUI
    };
    Tiangan::Tiangan(TIANGAN_ID gan)
    {
        _tiangan = gan;
    }
    TIANGAN_ID Tiangan::id()
    {
        return _tiangan;
    }
    Tiangan:: operator TIANGAN_ID ()
    {
        return _tiangan;
    }
    Tiangan & Tiangan::from(TIANGAN_ID gan)
    {
        if(gan<0)
            throw Error(ERROR_INVALID_ID);

        if(gan>=sizeof(_names)/sizeof(_names[0]))
            throw Error(ERROR_INVALID_ID);

        return _tiangans[gan];
    }
    const char* Tiangan::get_name()
    {
        if(_tiangan<0)
            return NULL;
        if(_tiangan>=sizeof(_names)/sizeof(_names[0]))
            return NULL;  
        return _names[_tiangan];
    }

    Tiangan& Tiangan::get_next()
    {
        int tg = _tiangan;
        tg++;
        if(tg>TGID_GUI)
            tg = 0;
        return from((TIANGAN_ID)tg);
    }

    Tiangan&  Tiangan::get_prev()
    {
        int tg = _tiangan;
        tg--;
        if(tg<0)
            tg = TGID_GUI;
        return from((TIANGAN_ID)tg);
    }

    Wuxing& Tiangan::get_wuxing()
    {
        return Wuxing::from(_Wuxings[_tiangan]);
    }

}