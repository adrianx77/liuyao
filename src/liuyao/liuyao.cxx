#include "../base/Wuxing.hxx"
#include "liuyaodef.hxx"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * LIUSHEN_TABLE[] = {
    LIUSHEN_QINGLONG,
    LIUSHEN_ZHUQUE,
    LIUSHEN_GOUCHEN,
    LIUSHEN_TENGSHE,
    LIUSHEN_BAIHU,
    LIUSHEN_XUANWU
};

const char * YaoWeiTable[] ={
    YAOWEI_KONG
    YAOWEI_SHI,
    YAOWEI_YING,
};

// const PUREGUA PureGuaTable[] = {
//     {BGID_QIAN,GUANAME_QIAN,{YAO_YANG,YAO_YANG,YAO_YANG},WUXINGMING_JIN},
//     {BGID_DUI,GUANAME_DUI,{YAO_YANG,YAO_YANG,YAO_YIN},WUXINGMING_JIN},
//     {BGID_LI,GUANAME_LI,{YAO_YANG,YAO_YIN,YAO_YANG},WUXINGMING_HUO},
//     {BGID_ZHEN,GUANAME_ZHEN,{YAO_YIN,YAO_YIN,YAO_YANG},WUXINGMING_MU},
//     {BGID_XUN,GUANAME_XUN,{YAO_YIN,YAO_YANG,YAO_YANG},WUXINGMING_MU},
//     {BGID_KAN,GUANAME_KAN,{YAO_YIN,YAO_YANG,YAO_YIN},WUXINGMING_SHUI},
//     {BGID_GEN,GUANAME_GEN,{YAO_YIN,YAO_YIN,YAO_YANG},WUXINGMING_TU},    
//     {BGID_KUN,GUANAME_KUN,{YAO_YIN,YAO_YIN,YAO_YIN},WUXINGMING_TU}
// };

// bool get_gua_name(BAGUA_ID gua,char * name)
// {
//     if(gua<0)return false;
//     size_t count = sizeof(PureGuaTable)/sizeof(PureGuaTable[0]);
//     if(gua>=count)return false;
    
//     for (size_t i = 0; i < count; i++)
//     {
//         if(gua==PureGuaTable[i].Index)
//         {
//             strcpy(name,PureGuaTable[i].Name);
//             return true;
//         }
//     }
//     return false;
// }

// void dump_gua( const PUREGUA * gua)
// {
//     printf("%s:%s\n",gua->Name,gua->element);
//     printf("%s\n",gua->Yao[2]);
//     printf("%s\n",gua->Yao[1]);
//     printf("%s\n",gua->Yao[0]);
// }
