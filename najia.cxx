#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "najia.hxx"
#include "element.hxx"
namespace Zhouyi{

const char * StemTable[] ={
    GAN_JIA,
    GAN_YI,
    GAN_BING,
    GAN_DING,
    GAN_WU,
    GAN_JI,
    GAN_GEN,
    GAN_XIN,
    GAN_REN,
    GAN_GUI
};
const char * BranchTable[] ={
    ZHI_ZI,
    ZHI_CHOU,
    ZHI_YIN,
    ZHI_MAO,
    ZHI_CHEN,
    ZHI_SI,
    ZHI_WU, 
    ZHI_WEI, 
    ZHI_SHEN,
    ZHI_YOU,
    ZHI_XU,
    ZHI_HAI
};

const char * StemBranchTable [][6] = {
    {
        GAN_JIA ZHI_ZI,
        GAN_JIA ZHI_YIN,
        GAN_JIA ZHI_CHEN,
        GAN_JIA ZHI_WU,
        GAN_JIA ZHI_SHEN,
        GAN_JIA ZHI_XU,
    },
    {
        GAN_YI ZHI_CHOU,
        GAN_YI ZHI_MAO,
        GAN_YI ZHI_SI,
        GAN_YI ZHI_WEI,
        GAN_YI ZHI_YOU,
        GAN_YI ZHI_HAI,
    },
    {
        GAN_BING ZHI_ZI,
        GAN_BING ZHI_YIN,
        GAN_BING ZHI_CHEN,
        GAN_BING ZHI_WU,
        GAN_BING ZHI_SHEN,
        GAN_BING ZHI_XU,
    },
    {
        GAN_DING ZHI_CHOU,
        GAN_DING ZHI_MAO,
        GAN_DING ZHI_SI,
        GAN_DING ZHI_WEI,
        GAN_DING ZHI_YOU,
        GAN_DING ZHI_HAI,
    },    
    {
        GAN_WU ZHI_ZI,
        GAN_WU ZHI_YIN,
        GAN_WU ZHI_CHEN,
        GAN_WU ZHI_WU,
        GAN_WU ZHI_SHEN,
        GAN_WU ZHI_XU,
    },
    {
        GAN_YI ZHI_CHOU,
        GAN_YI ZHI_MAO,
        GAN_YI ZHI_SI,
        GAN_YI ZHI_WEI,
        GAN_YI ZHI_YOU,
        GAN_YI ZHI_HAI,
    },    
    {
        GAN_JIA ZHI_ZI,
        GAN_JIA ZHI_YIN,
        GAN_JIA ZHI_CHEN,
        GAN_JIA ZHI_WU,
        GAN_JIA ZHI_SHEN,
        GAN_JIA ZHI_XU,
    },
    {
        GAN_JI ZHI_CHOU,
        GAN_JI ZHI_MAO,
        GAN_JI ZHI_SI,
        GAN_JI ZHI_WEI,
        GAN_JI ZHI_YOU,
        GAN_JI ZHI_HAI,
    },    
    {
        GAN_GEN ZHI_ZI,
        GAN_GEN ZHI_YIN,
        GAN_GEN ZHI_CHEN,
        GAN_GEN ZHI_WU,
        GAN_GEN ZHI_SHEN,
        GAN_GEN ZHI_XU,
    },
    {
        GAN_XIN ZHI_CHOU,
        GAN_XIN ZHI_MAO,
        GAN_XIN ZHI_SI,
        GAN_XIN ZHI_WEI,
        GAN_XIN ZHI_YOU,
        GAN_XIN ZHI_HAI,
    },    
    {
        GAN_REN ZHI_ZI,
        GAN_REN ZHI_YIN,
        GAN_REN ZHI_CHEN,
        GAN_REN ZHI_WU,
        GAN_REN ZHI_SHEN,
        GAN_REN ZHI_XU,
    },
    {
        GAN_GUI ZHI_CHOU,
        GAN_GUI ZHI_MAO,
        GAN_GUI ZHI_SI,
        GAN_GUI ZHI_WEI,
        GAN_GUI ZHI_YOU,
        GAN_GUI ZHI_HAI,
    }
};



typedef struct 
{
    ZHI_INDEX self;
    WUXING_ID element;          //五行
    ZHI_INDEX  impact;           //冲
    ZHI_INDEX  sixcombine;       //六合
    ZHI_INDEX  tricombine[2];    //三合
    ZHI_INDEX  forward;          //进
    ZHI_INDEX  backward;         //退
}BRANCHINFO;



bool get_gan_name(GAN_INDEX stem,char * name)
{
    if(stem<0)
        return false;
    if(stem>=sizeof(StemTable)/sizeof(StemTable[0]))
        return false;  
    strcpy(name,StemTable[stem]);
    return true;
}
bool get_zhi_name(ZHI_INDEX branch,char * name)
{
    if(branch<0)
        return false;
    if(branch>=sizeof(BranchTable)/sizeof(BranchTable[0]))
        return false;  
    strcpy(name,BranchTable[branch]);
    return true;    
}
bool get_ganzhi_name(GANZHI sb,char * sbName)
{
    if(sb.Stem<0 || sb.Stem<0)
        return false;    

    if(sb.Stem % 2 != sb.Branch%2)
        return false;

    if(sb.Stem>=10 || sb.Stem>=12)
        return false;

    strcpy(sbName,StemBranchTable[sb.Stem][sb.Branch/2]);


    return true;        
}

ZHI_INDEX get_next_branch(ZHI_INDEX branch)
{
    int b = branch;
    b++;
    if(b >BRANCHINDEX_HAI)        
        b = 0;
    return (ZHI_INDEX)b;
}

GAN_INDEX get_next_stem(GAN_INDEX stem)
{
    int s = stem;
    s++;
    if(s>STEMINDEX_GUI)
        s = 0;
    return (GAN_INDEX)s;  
}


ZHI_INDEX get_prev_branch(ZHI_INDEX branch)
{
    int b = branch;
    b--;
    if(b <0)        
        b = BRANCHINDEX_HAI;
    return (ZHI_INDEX)b;
}

GAN_INDEX get_prev_stem(GAN_INDEX stem)
{
    int s = stem;
    s--;
    if(s<0)
        s = STEMINDEX_GUI;
    return (GAN_INDEX)s;  
}



GANZHI get_next_stembranch(GANZHI sb)
{
    sb.Stem = get_next_stem(sb.Stem);
    sb.Branch = get_next_branch(sb.Branch);
    return sb;
}


GANZHI get_prev_stembranch(GANZHI sb)
{
    sb.Stem = get_prev_stem(sb.Stem);
    sb.Branch = get_prev_branch(sb.Branch);
    return sb;
}

 XUNKONG get_ganzhi_kong(GANZHI sb)
 {
     do{
        sb = get_next_stembranch(sb);
     }while(sb.Stem!=STEMINDEX_GUI);
    XUNKONG kong;
    kong.Branch[0] = get_next_branch(sb.Branch);
    kong.Branch[1] = get_next_branch(kong.Branch[0]);
    return kong;
 }

bool get_xunkong_name(XUNKONG xk,char * name)
{
    char xkName1[5];
    if(!get_zhi_name(xk.Branch[0],name))
        return false;
    if(!get_zhi_name(xk.Branch[1],xkName1))
        return false;
    strcat(name,xkName1);
    return true;
}

bool get_gan_element(){

}
}
