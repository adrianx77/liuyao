#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dizhi.hxx"
#include "../base/Error.hxx"

namespace Zhouyi{
const char * Dizhi::_names[]   = {ZHI_ZI,ZHI_CHOU,ZHI_YIN,ZHI_MAO,ZHI_CHEN,ZHI_SI,ZHI_WU, ZHI_WEI, ZHI_SHEN,ZHI_YOU,ZHI_XU,ZHI_HAI};
Dizhi Dizhi::_dizhis[] = {

};

Dizhi::Dizhi(DIZHI_ID z)
{
    if(z<0 || z>DZID_HAI)
        throw Error(ERROR_INVALID_ID);
    _dizhi = z;
}
DIZHI_ID Dizhi::id()
{
    return _dizhi;
}
Dizhi::operator DIZHI_ID()
{
    return _dizhi;
}
Dizhi& Dizhi::from(DIZHI_ID z)
{
    if(z<0 || z>DZID_HAI)
        throw Error(ERROR_INVALID_ID);
    return _dizhis[z];
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


