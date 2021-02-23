#include "liuyaodef.hxx"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * CREATURE_TABLE[] = {
    CREATURE_QINGLONG,
    CREATURE_ZHUQUE,
    CREATURE_GOUCHEN,
    CREATURE_TENGSHE,
    CREATURE_BAIHU,
    CREATURE_XUANWU
};

const char * YaoWeiTable[] ={
    YAOWEI_KONG
    YAOWEI_SHI,
    YAOWEI_YING,
};

const PUREGUA PureGuaTable[] = {
    {GUAINDEX_QIAN,GUANAME_QIAN,{YAO_YANG,YAO_YANG,YAO_YANG},ELEMENT_JIN},
    {GUAINDEX_DUI,GUANAME_DUI,{YAO_YANG,YAO_YANG,YAO_YIN},ELEMENT_JIN},
    {GUAINDEX_LI,GUANAME_LI,{YAO_YANG,YAO_YIN,YAO_YANG},ELEMENT_HUO},
    {GUAINDEX_ZHEN,GUANAME_ZHEN,{YAO_YIN,YAO_YIN,YAO_YANG},ELEMENT_MU},
    {GUAINDEX_XUN,GUANAME_XUN,{YAO_YIN,YAO_YANG,YAO_YANG},ELEMENT_MU},
    {GUAINDEX_KAN,GUANAME_KAN,{YAO_YIN,YAO_YANG,YAO_YIN},ELEMENT_SHUI},
    {GUAINDEX_GEN,GUANAME_GEN,{YAO_YIN,YAO_YIN,YAO_YANG},ELEMENT_TU},    
    {GUAINDEX_KUN,GUANAME_KUN,{YAO_YIN,YAO_YIN,YAO_YIN},ELEMENT_TU}
};

bool get_gua_name(GUA_INDEX gua,char * name)
{
    if(gua<0)return false;
    size_t count = sizeof(PureGuaTable)/sizeof(PureGuaTable[0]);
    if(gua>=count)return false;
    
    for (size_t i = 0; i < count; i++)
    {
        if(gua==PureGuaTable[i].Index)
        {
            strcpy(name,PureGuaTable[i].Name);
            return true;
        }
    }
    return false;
}

void dump_gua( const PUREGUA * gua){

    printf("%s:%s\n",gua->Name,gua->element);
    printf("%s\n",gua->Yao[2]);
    printf("%s\n",gua->Yao[1]);
    printf("%s\n",gua->Yao[0]);
}
