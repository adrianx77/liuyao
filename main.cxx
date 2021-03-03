#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <time.h>
#include "src/base/Wuxing.hxx"
#include "src/najia/TianganDizhi.hxx"
#include "src/liuyao/liushen.hxx"
#include "src/liuyao/Gua.hxx"
#include "src/liuyao/Chonggua.hxx"
#include "src/liuyao/LiuqinChonggua.hxx"
#include "src/najia/Lunar.hxx"
#include "src/base/Error.hxx"
#include "src/liuyao/Zhuanggua.hxx"

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
            printf("(%d %d)\n%s %s\n",i,j,g.name(),g.guaxing_name());
            for(int k=5;k>=0;k--)
            {
                printf("%s %s\n",g.yao(k)->get_name(),g.yao(k)->get_ganzhi().get_name());

            }
        }
    }
}

void test_zhuanggua0()
{
    for(size_t i = 0; i < 8; i++)
    {
        for(size_t j = 0; j < 8; j++)
        {
            Chonggua & g =Chonggua::from((BAGUA_ID)i,(BAGUA_ID)j); 
            LiuqinChonggua lqg(g);
            LiuqinChonggua lqgonggua(lqg.gonggua());
            printf("\n%s宫: %s (%s)\n",lqg.gonggua().gonggua().name(),g.name(),g.guaxing_name());
            for(int k=5;k>=0;k--)
            {
                Dizhi & dz = g.yao(k)->get_ganzhi().get_dizhi();
                Liuqin * fs = lqg.fushen(k);
                if(fs)
                {
                    Dizhi & dzfs = lqg.gonggua().yao(k)->get_ganzhi().get_dizhi();
                    printf("%s%s%s%s %s [%s%s%s]\n",g.yao(k)->get_name(),lqg.liuqin(k)->get_name(),dz.get_name(),dz.get_wuxing().get_name() , 
                                               lqg.gonggua().shiyao()==k?"世":(lqg.gonggua().yingyao()==k?"应":" "),
                                               fs->get_name(),dzfs.get_name(),dzfs.get_wuxing().get_name() );
                }
                else
                {
                    printf("%s%s%s%s %s\n",g.yao(k)->get_name(),lqg.liuqin(k)->get_name(),dz.get_name(),dz.get_wuxing().get_name(),
                                                lqg.gonggua().shiyao()==k?"世":(lqg.gonggua().yingyao()==k?"应":" "));
                }
            }
        }
    }
}


void test_zhuanggua()
{
    YAO_ID yao[6] = {YID_YANG,YID_YANG,YID_YING,YID_YANG,YID_LAO_YANG,YID_YING};
    for(int i=0;i<6;i++)
    {
        yao[i] = (YAO_ID)(rand() % 4);
    }
    ZhuangguaJieguo * guo = Zhuanggua::zhuanggua(yao,Lunar::now());
    
    std::string str;
    guo->dum(str);
    std::cout << str.c_str() << '\n';
}


int main(int argc, char *argv[])
{
    srand((unsigned int)time(0));
    try
    {
        // //Zhouyi::Lunar * l = Zhouyi::Lunar::now();
        // for(int i=0;i<24;i++)
        // {
        //     for(int i=0;i<24;i++)
        //     {
        //         Zhouyi::Lunar * l = Zhouyi::Lunar::create(2021,3,2,i);
        //         printf("%s年 %s月 %s日 %s时\n",l->year()->get_name(),l->month()->get_name(),l->day()->get_name(),l->hour()->get_name());
        //     }
        // }
        // for(int i=0;i<24;i++)
        // {
        //     Zhouyi::Lunar * l = Zhouyi::Lunar::create(2021,3,3,i);
        //     printf("%s年 %s月 %s日 %s时\n",l->year()->get_name(),l->month()->get_name(),l->day()->get_name(),l->hour()->get_name());
        // }
#if (defined _WIN32 || defined _WIN64)
    setlocale (LC_ALL,"zh-CN");
#else    
    setlocale(LC_COLLATE, "zh_CN");     
#endif    

    // test_60jiazi();
    // test_xuntable();
    // test_gua();
     test_zhuanggua();
    }
    catch(Zhouyi::Error& e)
    {
        std::cout << e.error() << '\n';
    }
        
    return 0;
}
