#include "ZhuangguaJieguo.hxx"
// #define COUNTOF(X) (sizeof(X)/sizeof((X)[0]))
#include "../base/basic.hxx"



namespace Zhouyi{

ZhuangguaJieguo::ZhuangguaJieguo(LiuqinChonggua * ben, LiuqinChonggua *bian,TianganDizhi * gz[GZI_MAX],Liushen * startLiushen)
{
    _bengua = ben;
    _zhigua = bian;
    for(int i=GZI_YEAR;i<GZI_MAX;i++)
    {
        _ganzhi[i] = gz[i];
    }
    for(int i=LSID_QINGLONG;i<LSID_MAX;i++)
    {
        _liushen[i] = startLiushen;
        startLiushen = startLiushen->next();
    }


    for(int i=SSID_GUIREN;i<=SSID_MAX;++i)
    {
        _shengsha[i] = ShenshaFactory::create((SHENSHA_ID)i,_ganzhi[GZI_MONTH],_ganzhi[GZI_DAY]);
    }


}
ZhuangguaJieguo * ZhuangguaJieguo::from(LiuqinChonggua * ben, LiuqinChonggua *bian,Lunar * lunar)
{
    TianganDizhi * gz[GZI_MAX] ={};
    gz[GZI_YEAR] = lunar->year();
    gz[GZI_MONTH] = lunar->month();
    gz[GZI_DAY] = lunar->day();
    gz[GZI_HOUR] = lunar->hour();

    return new ZhuangguaJieguo(ben,bian,gz,Liushen::from(lunar)); 
}

ZhuangguaJieguo * ZhuangguaJieguo::from(LiuqinChonggua * ben, LiuqinChonggua *bian,TianganDizhi * gz[GZI_MAX])
{
    TIANGAN_ID gan = gz[GZI_DAY]->get_tiangan();
    return new ZhuangguaJieguo(ben,bian,gz,Liushen::from(gan)); 
}



Liushen * ZhuangguaJieguo::liushen(int pos)
{
    return _liushen[pos];
}

LiuqinChonggua * ZhuangguaJieguo::bengua()
{
    return _bengua;
}

LiuqinChonggua * ZhuangguaJieguo::zhigua()
{
    return _zhigua;
}


TianganDizhi * ZhuangguaJieguo::year()
{
    return _ganzhi[GZI_YEAR];
}
TianganDizhi * ZhuangguaJieguo::month()
{
    return _ganzhi[GZI_MONTH];
}
TianganDizhi * ZhuangguaJieguo::day()
{
    return _ganzhi[GZI_DAY];
}

TianganDizhi * ZhuangguaJieguo::hour()
{
    return _ganzhi[GZI_HOUR];
}


Dizhi * ZhuangguaJieguo::yao_zhi(int pos)
{
    return &_bengua->chonggua().yao(pos)->get_ganzhi().get_dizhi();
}
bool   ZhuangguaJieguo:: yao_bian(int pos)  //是否为变
{
    if(_zhigua == NULL)
        return false;
    Guayao* zgy = _zhigua->chonggua().yao(pos);
    Guayao* bgy = _bengua->chonggua().yao(pos);
    if(bgy->id() != zgy->id())
        return true;
    return false;
}
Dizhi * ZhuangguaJieguo::bian_zhi(int pos)
{
    return &_zhigua->chonggua().yao(pos)->get_ganzhi().get_dizhi();
}


void ZhuangguaJieguo::dum(std::string &str)
{
    char s[500];
    //DUMP 干支
    sprintf(s,"干支: %s月 %s日 (旬空：%s)\n", _ganzhi[GZI_MONTH]->get_dizhi().name(), _ganzhi[GZI_DAY]->name(),_ganzhi[GZI_DAY]->get_xun().get_xunkong().name());
    str = s;
    //DUMP 神煞
    str+= "神煞:";
    for(int i=SSID_GUIREN;i<SSID_MAX;++i)
    {
        if(_shengsha[i])
        {
            str+= _shengsha[i]->name();
            str+="-";
            str+=_shengsha[i]->zhiname();
            str+="　";
        }
        if(i%6==0 && i!=0) //第七个换行
           str+="\n";    
    }
    str+="\n";
    //宫卦名

    sprintf(s,"%s宫:　%s　",_bengua->gong().gonggua().name(),_bengua->chonggua().name());
    str+=s;
    if(strlen(_bengua->chonggua().guaxing_name()))
    {
        str+= "(";
        str+= _bengua->chonggua().guaxing_name();
        str+= ")";
    }
    else
    {
        str+="　　";
    }
    if(_zhigua!=NULL)
    {
        if(_bengua->hasFushen())
        {
            str +="　　　　　　　　　　　　";
        }
        else
        {
            str +="　　　　　　";
        }
        sprintf(s,"%s宫:　%s　",_zhigua->gong().gonggua().name(),_zhigua->chonggua().name());
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
    str +="　";

    if(_bengua->hasFushen())
    {
        str += "伏　　神";
    }
    str +="　";
    str +="【本　卦】";
    if(_zhigua)
    {
        str +="　　　　　　　　";
        str +="【变　卦】";
    }
    str+="\n";
    //DUMP 爻
    int shi= _bengua->chonggua().shiyao();
    int ying= _bengua->chonggua().yingyao();

    for(int i=LSID_MAX-1;i>=0;i--)
    {
        //六神
        str+=_liushen[i]->name();
        str += "　";
        //伏神
        if(_bengua->hasFushen())
        {
            Liuqin * fs = _bengua->fushen(i);
            if(fs)
            {
                str += fs->name();
                Dizhi &z = _bengua->gonggua().yao(i)->get_ganzhi().get_dizhi(); 
                str += z.name();
                str += z.get_wuxing().name();
            }
            else
                str += "　　　　";
         }
        str += "　";

        //爻
        Guayao* bgy = _bengua->chonggua().yao(i);
        const char * yao = bgy->name();
        str += yao;        
        str += "　";
        //六亲
        const char * lq = _bengua->liuqin(i)->name();
        str += lq;    
        str += _bengua->chonggua().yao(i)->get_ganzhi().get_dizhi().name();
        str += _bengua->chonggua().yao(i)->get_ganzhi().get_dizhi().get_wuxing().name();


        str += "　";
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
                    str+="○→";
                }
                else
                {
                    str+="×→";
                }
            }
            else
            {
                str+="　 　";
            }
            //爻
            str+="　";  
            str += zgy->name();

            //六亲
            str+="　";  
            const char * lq = _zhigua->liuqin(i)->name();
            str += lq;    
            str += _zhigua->chonggua().yao(i)->get_ganzhi().get_dizhi().name();
            str += _zhigua->chonggua().yao(i)->get_ganzhi().get_dizhi().get_wuxing().name();


        }





        str+="\n";


    }
    
}

}
