#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tiangan.hxx"
#include "../base/Error.hxx"
namespace Zhouyi{
    static TIANGAN_ID tianganInit[] = {TGID_JIA,TGID_YI,TGID_BING,TGID_DING,TGID_WU,TGID_JI,TGID_GEN,TGID_XIN,TGID_REN,TGID_GUI};
    static WUXING_ID Wuxings[] = {WXID_MU,WXID_MU,WXID_HUO,WXID_HUO,WXID_TU,WXID_TU,WXID_JIN,WXID_JIN,WXID_SHUI,WXID_SHUI};

    bool   Tiangan::_init = false;
    const char * Tiangan::_names[] = {GAN_JIA, GAN_YI,GAN_BING,GAN_DING,GAN_WU,GAN_JI,GAN_GENG,GAN_XIN,GAN_REN,GAN_GUI};
    Tiangan* Tiangan::_tiangans[10] = {};
    Tiangan::Tiangan(TIANGAN_ID gan)
    {
        _tiangan = gan;
    }
    TIANGAN_ID Tiangan::id()const
    {
        return _tiangan;
    }
    Tiangan:: operator TIANGAN_ID ()const
    {
        return _tiangan;
    }
    Tiangan & Tiangan::from(TIANGAN_ID gan)
    {
        init();
        if(gan<0)
            throw Error(ERROR_INVALID_ID);

        if(gan>=sizeof(_names)/sizeof(_names[0]))
            throw Error(ERROR_INVALID_ID);

        return *_tiangans[gan];
    }
    void Tiangan::init()
    {
        if(_init)
            return;   
        for(size_t i=0;i<sizeof(_tiangans)/sizeof(_tiangans[0]);i++)
        {
            _tiangans[i] = new Tiangan(tianganInit[i]);
        }
        _init = true;
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
        return Wuxing::from(Wuxings[_tiangan]);
    }

}