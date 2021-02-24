#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "element.hxx"
namespace Zhouyi{
   class WuxingShengkeGuanxi {
    public:
        WUXING_ID self;
        WUXING_ID generate;
        WUXING_ID restrict;
        WUXING_ID restricted;
        WUXING_ID generated;
        static WuxingShengkeGuanxi _guanxi[];
        WUXING_SHENGKE get_shengke(WUXING_ID e1,WUXING_ID e2);
    };

    WuxingShengkeGuanxi WuxingShengkeGuanxi::_guanxi[]={
        {
            WUXING_JIN,
            WUXING_SHUI,
            WUXING_MU,
            WUXING_HUO,
            WUXING_TU
        },
        {
            WUXING_SHUI,
            WUXING_MU,
            WUXING_HUO,
            WUXING_TU,
            WUXING_JIN
        },
        {
            WUXING_MU,
            WUXING_HUO,
            WUXING_TU,
            WUXING_JIN,
            WUXING_SHUI
        },
        {
            WUXING_HUO,
            WUXING_TU,
            WUXING_JIN,
            WUXING_SHUI,
            WUXING_MU
        },
        {
            WUXING_TU,
            WUXING_JIN,
            WUXING_SHUI,
            WUXING_MU,
            WUXING_HUO
        }
    };

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


    const char * BaseElement::_names[] = {ELEMENT_JIN,ELEMENT_SHUI,ELEMENT_MU,ELEMENT_HUO,ELEMENT_TU};
    const char *  BaseElement::_guanxi_format[] = {RELATION_RESTRICT,RELATION_RESTRICTED,RELATION_SAME,RELATION_GENERATE,RELATION_GENERATED,RELATION_INVALID};
    BaseElement * BaseElement::_instance = new BaseElement();

    BaseElement::BaseElement()
    {
        if(_instance==NULL)
        {
            Init();
        }
    }

    void BaseElement::Init()
    {
            
    }
    bool BaseElement::get_name(WUXING_ID element,char * name)
    {
        if(element<0)
            return false;
        size_t count = sizeof(_names)/sizeof(_names[0]);
        if(element>=count)
            return false;
        strcpy(name,_names[element]);
        return true;
    }
    

    bool BaseElement::get_skgx_format(WUXING_SHENGKE r,char * name)
    {
        if(r<0)
            return false;
        if(r>=WXSK_INVALID)
            return false;
        strcpy(name,_guanxi_format[r]);
        return true;
    }
}
