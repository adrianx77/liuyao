#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Wuxing.hxx"
#include "Error.hxx"
#include "WuxingShengkeGuanxi.hxx"

namespace Zhouyi{

    const char * Wuxing::_names[] = {WUXING_JIN,WUXING_SHUI,WUXING_MU,WUXING_HUO,WUXING_TU};
    bool Wuxing::_init = false;
    static WUXING_ID WuxingIds[] = {
        WXID_JIN,WXID_SHUI,WXID_MU,WXID_HUO,WXID_TU
    };
    Wuxing* Wuxing::_wuxing[5] = {};
    
    void Wuxing::init()
    {
        if(_init)
            return ;

        for(size_t i=0;i<sizeof(WuxingIds)/sizeof(WuxingIds[0]);i++)
        {
            _wuxing[i] = new Wuxing(WuxingIds[i]);
        }

        _init = true;
    }
    Wuxing::Wuxing(WUXING_ID wx)
    {
        _baseWuxing = wx;
    }
    
    Wuxing & Wuxing::from(WUXING_ID wx)
    {
        init();
        if(wx<0 || wx> WXID_TU)
            throw Error(ERROR_INVALID_ID);
        return *_wuxing[wx];
    }

    const char* Wuxing::name() const
    {
        return _names[_baseWuxing];
    }
    WUXING_ID Wuxing::id() const
    {
        return _baseWuxing;
    }
    Wuxing::operator WUXING_ID()const
    {
        return _baseWuxing;
    }
    WUXING_SHENGKE Wuxing::get_shengke(Wuxing * wx)
    {
        return WuxingShengkeGuanxi::get_shengke(_baseWuxing,wx->_baseWuxing);
    }
    Wuxing * Wuxing::clone()
    {
        return new Wuxing(_baseWuxing);
    }
}
