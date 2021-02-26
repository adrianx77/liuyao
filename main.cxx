#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "src/base/Wuxing.hxx"
#include "src/najia/TianganDizhi.hxx"
#include "src/liuyao/liuyaodef.hxx"
#include "src/liuyao/Gua.hxx"
#include "src/liuyao/Chonggua.hxx"

using namespace Zhouyi;


void test_xuntable()
{
    Xun ** xun = Xun::get_xun_table();
   for (size_t j = 0; j < 6; j++)
   {
       //printf("%s:",xun[j]->get_name());
       xun[j]->dump_xun();
       printf(" (旬空)%s\n",xun[j]->get_xunkong().get_name());
   }
}

void test_60jiazi()
{
   for (size_t i = 0; i < 10; i++)
   {
       for (size_t j = 0; j < 12; j++)
       {
           if(i%2 != j%2)
                continue;
            TianganDizhi &gz= TianganDizhi::from(Tiangan::from((TIANGAN_ID)i),Dizhi::from((DIZHI_ID)j));
            
            Xun & xun = gz.get_xun();
            printf("%s->%s 旬空:%s\n",gz.get_name(),xun.get_name(),xun.get_xunkong().get_name());
       }
   }
}


void test_gua()
{
    for(size_t i = 0; i < 8; i++)
    {
        for(size_t j = 0; j < 8; j++)
        {
            Chonggua & g =Chonggua::from((BAGUA_ID)i,(BAGUA_ID)j); 
            printf("%s %s\n",g.get_name(),g.get_guaxing_name());
            for(int k=5;k>=0;k--)
            {
                printf("%s %s\n",g.get_yao(k)->get_name(),g.get_yao(k)->get_ganzhi().get_name());

            }
        }
    }
}

int main(int argc, char *argv[])
{
#if (defined _WIN32 || defined _WIN64)
    setlocale (LC_ALL,"zh-CN");
#else    
    setlocale(LC_COLLATE, "zh_CN");     
#endif    

    test_60jiazi();
    test_xuntable();
    test_gua();

    return 0;
}
