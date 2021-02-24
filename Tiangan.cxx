#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tiangan.hxx"

namespace Zhouyi{
    const char * Tiangan::_names[] = {GAN_JIA, GAN_YI,GAN_BING,GAN_DING,GAN_WU,GAN_JI,GAN_GENG,GAN_XIN,GAN_REN,GAN_GUI};

    bool Tiangan::get_name(TIANGANID gan,char * name)
    {
        if(gan<0)
            return false;
        if(gan>=sizeof(_names)/sizeof(_names[0]))
            return false;  
        strcpy(name,_names[gan]);
        return true;
    }



    TIANGANID Tiangan::get_next(TIANGANID stem)
    {
        int s = stem;
        s++;
        if(s>TGID_GUI)
            s = 0;
        return (TIANGANID)s;  
    }

    TIANGANID Tiangan::get_prev(TIANGANID stem)
    {
        int s = stem;
        s--;
        if(s<0)
            s = TGID_GUI;
        return (TIANGANID)s;  
    }

    WUXING_ID Tiangan::get_element(TIANGANID gan)
    {
        return WUXING_INVALID;
    }

}