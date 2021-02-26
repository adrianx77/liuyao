#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dizhi.hxx"
#include "../base/Error.hxx"

namespace Zhouyi{
bool Dizhi::_init = false;
static DIZHI_ID dizhiInit [] = {DZID_ZI,DZID_CHOU,DZID_YIN,DZID_MAO,DZID_CHEN,DZID_SI,DZID_WU,DZID_WEI,DZID_SHEN,DZID_YOU,DZID_XU,DZID_HAI};
const char * Dizhi::_names[]   = {ZHI_ZI,ZHI_CHOU,ZHI_YIN,ZHI_MAO,ZHI_CHEN,ZHI_SI,ZHI_WU, ZHI_WEI, ZHI_SHEN,ZHI_YOU,ZHI_XU,ZHI_HAI};
Dizhi* Dizhi::_dizhis[12];

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
    if(_init)
        return;
    for(size_t i=0;i<sizeof(dizhiInit)/sizeof(dizhiInit[0]);i++)
    {
        _dizhis[i] = new Dizhi(dizhiInit[i]);
    }
    _init = true;        
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
    return *_dizhis[z];
}

const char * Dizhi::get_name()
{
    if(_dizhi<0)
        return NULL;
    if(_dizhi>=sizeof(_names)/sizeof(_names[0]))
        return NULL;  
    return _names[_dizhi];
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


}


