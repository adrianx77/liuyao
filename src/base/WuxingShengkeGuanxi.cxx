#include <stdlib.h>
#include "WuxingShengkeGuanxi.hxx"

namespace Zhouyi{
    WuxingShengkeGuanxi WuxingShengkeGuanxi::_guanxi[]=
    {
        {
            WXID_JIN,
            WXID_SHUI,
            WXID_MU,
            WXID_HUO,
            WXID_TU
        },
        {
            WXID_SHUI,
            WXID_MU,
            WXID_HUO,
            WXID_TU,
            WXID_JIN
        },
        {
            WXID_MU,
            WXID_HUO,
            WXID_TU,
            WXID_JIN,
            WXID_SHUI
        },
        {
            WXID_HUO,
            WXID_TU,
            WXID_JIN,
            WXID_SHUI,
            WXID_MU
        },
        {
            WXID_TU,
            WXID_JIN,
            WXID_SHUI,
            WXID_MU,
            WXID_HUO
        }
    };
    
    const char *  WuxingShengkeGuanxi::_guanxi_format[] = {RELATION_RESTRICT,RELATION_RESTRICTED,RELATION_SAME,RELATION_GENERATE,RELATION_GENERATED,RELATION_INVALID};

    WUXING_SHENGKE WuxingShengkeGuanxi::get_shengke(WUXING_ID e1,WUXING_ID e2)
    {
        if(e1<0)
            return WXSK_INVALID;
        size_t count = sizeof(_guanxi)/sizeof(_guanxi[0]);
        if(e1>count || e2> count)
            return WXSK_INVALID;
        
        if(e1==e2)
            return WXSK_SAME;
        
        if(_guanxi[e1].generate == e2)
            return WXSK_GENERATE;
        
        if(_guanxi[e1].restrict == e2)
            return WXSK_RESTRICT;

        if(_guanxi[e1].generated == e2)
            return WXSK_GENERATED;

        if(_guanxi[e1].restricted == e2)
            return WXSK_RESTRICTED;
        
        return WXSK_INVALID;
    }
    const char * WuxingShengkeGuanxi::get_skgx_format(WUXING_SHENGKE r)
    {
        if(r<0)
            return NULL;
        if(r>=WXSK_INVALID)
            return NULL;

        return _guanxi_format[r];
    }
}