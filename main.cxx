#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "element.hxx"
#include "najia.hxx"
int main(int argc, char *argv[])
{
    STEAMBRANCH sb = {STEMINDEX_DING,BRANCHINDEX_WEI};
    char sbName[10];
    char Xuankong[10];
    if(get_stembranch_name(sb,sbName))
    {
        printf("%s\n",sbName);
        XUNKONG xk = get_stembranch_kong(sb);
        get_xunkong_name(xk,Xuankong);
        printf("旬空:%s\n",Xuankong);    }
    else
        printf("error get sb\n");

    char re[10];

    for(size_t i=0;i<=ELEMENTINDEX_TU;i++)
    {
        for(size_t j=0;j<=ELEMENTINDEX_TU;j++)
        {
            ELEMENT_RELATION r =get_relation((ELEMENT_INDEX)i,(ELEMENT_INDEX)j);
            if(get_relation_name(r,re))
            {
                char e1[10],e2[10];
                get_element_name((ELEMENT_INDEX)i,e1);
                get_element_name((ELEMENT_INDEX)j,e2);
                printf("%s %s %s\n",e1,re,e2);
            }
        }
    }


    return 0;
}