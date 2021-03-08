#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dizhi.hxx"
#include "../base/Error.hxx"

namespace Zhouyi{
static bool Init = false;
static DIZHI_ID DizhiInit [12] = {DZID_ZI,DZID_CHOU,DZID_YIN,DZID_MAO,DZID_CHEN,DZID_SI,DZID_WU,DZID_WEI,DZID_SHEN,DZID_YOU,DZID_XU,DZID_HAI};
static WUXING_ID Wuxings[12] = {WXID_SHUI,WXID_TU,WXID_MU,WXID_MU,WXID_TU,WXID_HUO,WXID_HUO,WXID_TU,WXID_JIN,WXID_JIN,WXID_TU,WXID_SHUI};
static const char * Names[12]   = {ZHI_ZI,ZHI_CHOU,ZHI_YIN,ZHI_MAO,ZHI_CHEN,ZHI_SI,ZHI_WU, ZHI_WEI, ZHI_SHEN,ZHI_YOU,ZHI_XU,ZHI_HAI};
static Dizhi* Dizhis[12];

Dizhi::Dizhi(DIZHI_ID z)
{
    if(z<0 || z>DZID_HAI)
        throw Error(ERROR_INVALID_ID);
    _dizhi = z;
}
DIZHI_ID Dizhi::id()const
{
    return _dizhi;
}

void Dizhi::init()
{
    if(Init)
        return;
    for(size_t i=0;i<sizeof(DizhiInit)/sizeof(DizhiInit[0]);i++)
    {
        Dizhis[i] = new Dizhi(DizhiInit[i]);
    }
    Init = true;        
}

Dizhi::operator DIZHI_ID()const
{
    return _dizhi;
}
Dizhi& Dizhi::from(DIZHI_ID z)
{
    Dizhi::init();
    if(z<0 || z>DZID_HAI)
        throw Error(ERROR_INVALID_ID);
    return *Dizhis[z];
}

const char * Dizhi::name()
{
    if(_dizhi<0)
        return NULL;
    if(_dizhi>=sizeof(Names)/sizeof(Names[0]))
        return NULL;  
    return Names[_dizhi];
}

Dizhi& Dizhi::get_next()
{
    int b = _dizhi;
    b++;
    if(b >DZID_HAI)
        b = 0;
    return Dizhi::from((DIZHI_ID)b);
}
Dizhi& Dizhi::get_prev()
{
    int b = _dizhi;
    b--;
    if(b <0)        
        b = DZID_HAI;
    return Dizhi::from((DIZHI_ID)b);
}

Wuxing& Dizhi::get_wuxing()
{
    return Wuxing::from(Wuxings[_dizhi]);
}

}


