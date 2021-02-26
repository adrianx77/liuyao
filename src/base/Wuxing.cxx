#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Wuxing.hxx"
#include "Error.hxx"
#include "WuxingShengkeGuanxi.hxx"

namespace Zhouyi{

    const char * Wuxing::_names[] = {WUXING_JIN,WUXING_SHUI,WUXING_MU,WUXING_HUO,WUXING_TU};

    Wuxing Wuxing::_wuxing[] =
    {
        {WXID_JIN},{WXID_SHUI},{WXID_MU},{WXID_HUO},{WXID_TU}
    };

    Wuxing::Wuxing(WUXING_ID wx)
    {
        _baseWuxing = wx;
    }
    
    Wuxing & Wuxing::from(WUXING_ID wx)
    {
        if(wx<0 || wx> WXID_TU)
            throw Error(ERROR_INVALID_ID);
        return _wuxing[wx];
    }

    const char* Wuxing::get_name() const
    {
        return _names[_baseWuxing];
    }
    WUXING_ID Wuxing::get_wuxing() const
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
