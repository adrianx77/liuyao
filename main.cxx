#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "element.hxx"
#include "najia.hxx"
using Zhouyi;
int main(int argc, char *argv[])
{
    GANZHI sb = {STEMINDEX_DING,BRANCHINDEX_WEI};
    char sbName[10];
    char Xuankong[10];
    if(get_ganzhi_name(sb,sbName))
    {
        printf("%s\n",sbName);
        XUNKONG xk = get_ganzhi_kong(sb);
        get_xunkong_name(xk,Xuankong);
        printf("旬空:%s\n",Xuankong);    }
    else
        printf("error get sb\n");

    char re[10];

    for(size_t i=0;i<=WUXING_TU;i++)
    {
        for(size_t j=0;j<=WUXING_TU;j++)
        {
            WUXING_SHENGKE r =get_relation((WUXING_ID)i,(WUXING_ID)j);
            if(get_relation_name(r,re))
            {
                char e1[10],e2[10];
                get_element_name((WUXING_ID)i,e1);
                get_element_name((WUXING_ID)j,e2);
                printf(re,e1,e2);
                printf("\n");
            }
        }
    }

    return 0;
}