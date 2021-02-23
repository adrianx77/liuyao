#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "najia.hxx"
const char * StemTable[] ={
    STEM_JIA,
    STEM_YI,
    STEM_BING,
    STEM_DING,
    STEM_WU,
    STEM_JI,
    STEM_GEN,
    STEM_XIN,
    STEM_REN,
    STEM_GUI
};
const char * BranchTable[] ={
    BRANCH_ZI,
    BRANCH_CHOU,
    BRANCH_YIN,
    BRANCH_MAO,
    BRANCH_CHEN,
    BRANCH_SI,
    BRANCH_WU, 
    BRANCH_WEI, 
    BRANCH_SHEN,
    BRANCH_YOU,
    BRANCH_XU,
    BRANCH_HAI
};

const char * StemBranchTable [][6] = {
    {
        STEM_JIA BRANCH_ZI,
        STEM_JIA BRANCH_YIN,
        STEM_JIA BRANCH_CHEN,
        STEM_JIA BRANCH_WU,
        STEM_JIA BRANCH_SHEN,
        STEM_JIA BRANCH_XU,
    },
    {
        STEM_YI BRANCH_CHOU,
        STEM_YI BRANCH_MAO,
        STEM_YI BRANCH_SI,
        STEM_YI BRANCH_WEI,
        STEM_YI BRANCH_YOU,
        STEM_YI BRANCH_HAI,
    },
    {
        STEM_BING BRANCH_ZI,
        STEM_BING BRANCH_YIN,
        STEM_BING BRANCH_CHEN,
        STEM_BING BRANCH_WU,
        STEM_BING BRANCH_SHEN,
        STEM_BING BRANCH_XU,
    },
    {
        STEM_DING BRANCH_CHOU,
        STEM_DING BRANCH_MAO,
        STEM_DING BRANCH_SI,
        STEM_DING BRANCH_WEI,
        STEM_DING BRANCH_YOU,
        STEM_DING BRANCH_HAI,
    },    
    {
        STEM_WU BRANCH_ZI,
        STEM_WU BRANCH_YIN,
        STEM_WU BRANCH_CHEN,
        STEM_WU BRANCH_WU,
        STEM_WU BRANCH_SHEN,
        STEM_WU BRANCH_XU,
    },
    {
        STEM_YI BRANCH_CHOU,
        STEM_YI BRANCH_MAO,
        STEM_YI BRANCH_SI,
        STEM_YI BRANCH_WEI,
        STEM_YI BRANCH_YOU,
        STEM_YI BRANCH_HAI,
    },    
    {
        STEM_JIA BRANCH_ZI,
        STEM_JIA BRANCH_YIN,
        STEM_JIA BRANCH_CHEN,
        STEM_JIA BRANCH_WU,
        STEM_JIA BRANCH_SHEN,
        STEM_JIA BRANCH_XU,
    },
    {
        STEM_JI BRANCH_CHOU,
        STEM_JI BRANCH_MAO,
        STEM_JI BRANCH_SI,
        STEM_JI BRANCH_WEI,
        STEM_JI BRANCH_YOU,
        STEM_JI BRANCH_HAI,
    },    
    {
        STEM_GEN BRANCH_ZI,
        STEM_GEN BRANCH_YIN,
        STEM_GEN BRANCH_CHEN,
        STEM_GEN BRANCH_WU,
        STEM_GEN BRANCH_SHEN,
        STEM_GEN BRANCH_XU,
    },
    {
        STEM_XIN BRANCH_CHOU,
        STEM_XIN BRANCH_MAO,
        STEM_XIN BRANCH_SI,
        STEM_XIN BRANCH_WEI,
        STEM_XIN BRANCH_YOU,
        STEM_XIN BRANCH_HAI,
    },    
    {
        STEM_REN BRANCH_ZI,
        STEM_REN BRANCH_YIN,
        STEM_REN BRANCH_CHEN,
        STEM_REN BRANCH_WU,
        STEM_REN BRANCH_SHEN,
        STEM_REN BRANCH_XU,
    },
    {
        STEM_GUI BRANCH_CHOU,
        STEM_GUI BRANCH_MAO,
        STEM_GUI BRANCH_SI,
        STEM_GUI BRANCH_WEI,
        STEM_GUI BRANCH_YOU,
        STEM_GUI BRANCH_HAI,
    }
};



bool get_stem_name(STEM_INDEX stem,char * name)
{
    if(stem<0)
        return false;
    if(stem>=sizeof(StemTable)/sizeof(StemTable[0]))
        return false;  
    strcpy(name,StemTable[stem]);
    return true;
}
bool get_branch_name(BRANCH_INDEX branch,char * name)
{
    if(branch<0)
        return false;
    if(branch>=sizeof(BranchTable)/sizeof(BranchTable[0]))
        return false;  
    strcpy(name,BranchTable[branch]);
    return true;    
}
bool get_stembranch_name(STEAMBRANCH sb,char * sbName)
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

BRANCH_INDEX get_next_branch(BRANCH_INDEX branch)
{
    int b = branch;
    b++;
    if(b >BRANCHINDEX_HAI)        
        b = 0;
    return (BRANCH_INDEX)b;
}

STEM_INDEX get_next_stem(STEM_INDEX stem)
{
    int s = stem;
    s++;
    if(s>STEMINDEX_GUI)
        s = 0;
    return (STEM_INDEX)s;  
}


BRANCH_INDEX get_prev_branch(BRANCH_INDEX branch)
{
    int b = branch;
    b--;
    if(b <0)        
        b = BRANCHINDEX_HAI;
    return (BRANCH_INDEX)b;
}

STEM_INDEX get_prev_stem(STEM_INDEX stem)
{
    int s = stem;
    s--;
    if(s<0)
        s = STEMINDEX_GUI;
    return (STEM_INDEX)s;  
}



STEAMBRANCH get_next_stembranch(STEAMBRANCH sb)
{
    sb.Stem = get_next_stem(sb.Stem);
    sb.Branch = get_next_branch(sb.Branch);
    return sb;
}


STEAMBRANCH get_prev_stembranch(STEAMBRANCH sb)
{
    sb.Stem = get_prev_stem(sb.Stem);
    sb.Branch = get_prev_branch(sb.Branch);
    return sb;
}

 XUNKONG get_stembranch_kong(STEAMBRANCH sb)
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
    if(!get_branch_name(xk.Branch[0],name))
        return false;
    if(!get_branch_name(xk.Branch[1],xkName1))
        return false;
    strcat(name,xkName1);
    return true;
}