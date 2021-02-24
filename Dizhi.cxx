#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dizhi.hxx"

namespace Zhouyi{
    const char * Dizhi::_names[]   = {ZHI_ZI,ZHI_CHOU,ZHI_YIN,ZHI_MAO,ZHI_CHEN,ZHI_SI,ZHI_WU, ZHI_WEI, ZHI_SHEN,ZHI_YOU,ZHI_XU,ZHI_HAI};


    bool Dizhi::get_name(DIZHIID zhi,char * name)
    {
        if(zhi<0)
            return false;
        if(zhi>=sizeof(_names)/sizeof(_names[0]))
            return false;  
        strcpy(name,_names[zhi]);
        return true;    
    }

    DIZHIID Dizhi::get_next(DIZHIID branch)
    {
        int b = branch;
        b++;
        if(b >DZID_HAI)
            b = 0;
        return (DIZHIID)b;
    }
    DIZHIID Dizhi::get_prev(DIZHIID branch)
    {
        int b = branch;
        b--;
        if(b <0)        
            b = DZID_HAI;
        return (DIZHIID)b;
    }
}


