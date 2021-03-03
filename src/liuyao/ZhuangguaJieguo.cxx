#include "ZhuangguaJieguo.hxx"
namespace Zhouyi{
ZhuangguaJieguo::ZhuangguaJieguo(LiuqinChonggua * ben, LiuqinChonggua *bian,TianganDizhi * gz[4],Liushen * startLiushen)
{
    _bengua = ben;
    _zhigua = bian;
    for(int i=0;i<4;i++)
    {
        _ganzhi[i] = gz[i];
    }
    for(int i=0;i<6;i++)
    {
        _liushen[i] = startLiushen;
        startLiushen = startLiushen->next();
    }
}
ZhuangguaJieguo * ZhuangguaJieguo::from(LiuqinChonggua * ben, LiuqinChonggua *bian,Lunar * lunar)
{
    TianganDizhi * gz[4] ={};
    gz[0] = lunar->year();
    gz[1] = lunar->month();
    gz[2] = lunar->day();
    gz[3] = lunar->hour();

    return new ZhuangguaJieguo(ben,bian,gz,Liushen::from(lunar)); 
}

Liushen * ZhuangguaJieguo::liushen(int pos)
{
    return _liushen[pos];
}

void ZhuangguaJieguo::dum(std::string &str)
{
    char s[500];
    //DUMP 干支
    sprintf(s,"干支: %s月 %s日 (旬空：%s)\n", _ganzhi[1]->get_dizhi().get_name(), _ganzhi[2]->get_name(),_ganzhi[2]->get_xun().get_xunkong().get_name());
    str = s;
    //DUMP 神煞

    //宫卦名

    sprintf(s,"%s宫: %s ",_bengua->gong().gonggua().name(),_bengua->chonggua().name());
    str+=s;
    if(strlen(_bengua->chonggua().guaxing_name()))
    {
        str+= "(";
        str+= _bengua->chonggua().guaxing_name();
        str+= ")";
    }
    else
    {
        str+="    ";
    }
    if(_zhigua!=NULL)
    {
        if(_bengua->hasFushen())
        {
            str +="                     ";
        }
        else
        {
            str +="           ";
        }
        sprintf(s,"%s宫: %s ",_zhigua->gong().gonggua().name(),_zhigua->chonggua().name());
        str += s;
        if(strlen(_zhigua->chonggua().guaxing_name()))
        {
            str+= "(";
            str+= _zhigua->chonggua().guaxing_name();
            str+= ")";
        }
    }

    str+="\n";
    

    //标题
    str +="六神";
    str +=" ";

    if(_bengua->hasFushen())
    {
        str += "伏　　神";
    }
    str +=" ";
    str +="【本　卦】";
    if(_zhigua)
    {
        str +="              ";
        str +="【变　卦】\n";
    }
    //DUMP 爻
    int shi= _bengua->chonggua().shiyao();
    int ying= _bengua->chonggua().yingyao();

    for(int i=5;i>=0;i--)
    {
        //六神
        str+=_liushen[i]->name();
        str += "  ";
        //伏神
        if(_bengua->hasFushen())
        {
            Liuqin * fs = _bengua->fushen(i);
            if(fs)
            {
                str += fs->get_name();
                Dizhi &z = _bengua->gonggua().yao(i)->get_ganzhi().get_dizhi(); 
                str += z.get_name();
                str += z.get_wuxing().get_name();
            }
            else
                str += "        ";
         }
        str += " ";

        //爻
        Guayao* bgy = _bengua->chonggua().yao(i);
        const char * yao = bgy->get_name();
        str += yao;        
        str += " ";
        //六亲
        const char * lq = _bengua->liuqin(i)->get_name();
        str += lq;    
        str += _bengua->chonggua().yao(i)->get_ganzhi().get_dizhi().get_name();
        str += _bengua->chonggua().yao(i)->get_ganzhi().get_dizhi().get_wuxing().get_name();


        str += " ";
        //世应
        if(shi==i)
        {
            str += "世";
        }
        else if(ying==i)
        {
            str += "应";
        }
        else
        {
            str+="　";
        }
        str+="　";    

        //变卦
        if(_zhigua != NULL)
        {
            //变
            Guayao* zgy = _zhigua->chonggua().yao(i);
            YAO_ID bgyid = bgy->id();
            if(zgy->id() != bgyid)
            {
                if(bgyid & YID_YANG)
                {
                    str+="o->";
                }
                else
                {
                    str+="x->";
                }
            }
            else
            {
                str+="   ";
            }
            //爻
            str+="　";  
            str += zgy->get_name();

            //六亲
            str+="　";  
            const char * lq = _zhigua->liuqin(i)->get_name();
            str += lq;    
            str += _zhigua->chonggua().yao(i)->get_ganzhi().get_dizhi().get_name();
            str += _zhigua->chonggua().yao(i)->get_ganzhi().get_dizhi().get_wuxing().get_name();


        }





        str+="\n";


    }
    
}

}
