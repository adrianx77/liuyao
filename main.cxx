#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liuyaodef.hxx"
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
    return 0;
}