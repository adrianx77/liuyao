#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "element.hxx"
#include "najia.hxx"

using namespace Zhouyi;


int main(int argc, char *argv[])
{
#ifdef  _WINDOWS || _WIN32
    setlocale (LC_ALL,"zh-CN");
#else    
    setlocale(LC_COLLATE, "zh_CN");     
#endif    

   for (size_t i = 0; i < 10; i++)
   {
       TianganDizhi * gz = NULL;
       for (size_t j = 0; j < 12; j++)
       {
           if(i%2 != j%2)
                continue;
            gz= TianganDizhi::from((TIANGANID)i,(DIZHIID)j);
            
            Xun * xun = gz->get_xun();
            printf("%s->%s 旬空:%s\n",gz->get_name(),xun->get_name(),xun->get_xunkong()->get_name());
       }
   }
   

    return 0;
}
