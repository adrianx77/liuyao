#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "element.hxx"
namespace Zhouyi{
const char * BaseElement::Names[] = {ELEMENT_JIN,ELEMENT_SHUI,ELEMENT_MU,ELEMENT_HUO,ELEMENT_TU};
    const char * ElementNames[] ={
        ELEMENT_JIN,
        ELEMENT_SHUI,
        ELEMENT_MU,
        ELEMENT_HUO,
        ELEMENT_TU
    };

    const char * ShengkeGuanxiMing[] = {
        RELATION_RESTRICT,
        RELATION_RESTRICTED,
        RELATION_SAME,
        RELATION_GENERATE,
        RELATION_GENERATED,
        RELATION_INVALID
    };


    class WuxingShengkeGuanxi {
    public:
        WUXING_ID self;
        WUXING_ID generate;
        WUXING_ID restrict;
        WUXING_ID restricted;
        WUXING_ID generated;
    };

    WuxingShengkeGuanxi WuXinShengKeGuanxi[]={
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
        size_t count = sizeof(ElementNames)/sizeof(ElementNames[0]);
        if(element>=count)
            return false;
        strcpy(name,ElementNames[element]);
        return true;
    }
    WUXING_SHENGKE BaseElement::get_shengke(WUXING_ID e1,WUXING_ID e2)
    {
        if(e1<0)
            return WXSK_INVALID;
        size_t count = sizeof(WuXinShengKeGuanxi)/sizeof(WuXinShengKeGuanxi[0]);
        if(e1>count || e2> count)
            return WXSK_INVALID;
        
        if(e1==e2)
            return WXSK_SAME;
        
        if(WuXinShengKeGuanxi[e1].generate == e2)
            return WXSK_GENERATE;
        
        if(WuXinShengKeGuanxi[e1].restrict == e2)
            return WXSK_RESTRICT;

        if(WuXinShengKeGuanxi[e1].generated == e2)
            return WXSK_GENERATED;

        if(WuXinShengKeGuanxi[e1].restricted == e2)
            return WXSK_RESTRICTED;
        
        return WXSK_INVALID;
    }

    bool BaseElement::get_relation_name(WUXING_SHENGKE r,char * name)
    {
        if(r<0)
            return false;
        if(r>=WXSK_INVALID)
            return false;
        strcpy(name,ShengkeGuanxiMing[r]);
        return true;
    }
}
