#include "AnalystJixiong.hxx"
#include "../base/WuxingShengkeGuanxi.hxx"
namespace Zhouyi{
YaoWangshuai* AnalystJixiong::get_YaoWangshuai(int yaoPos)
{
    return _wangshuaiList[yaoPos];
}

void  AnalystJixiong::analyse(int yaoPos)
{
    if(!_wangshuaiList[yaoPos])
        _wangshuaiList[yaoPos] = new YaoWangshuai();   
    //1.分析动变
    _wangshuaiList[yaoPos]->level = ANLVL_JIXIONG;
    _wangshuaiList[yaoPos]->wo    = _jieguo->yao_zhi(yaoPos)->id();
    if(_jieguo->yao_bian(yaoPos))
    {
        
        //是否为无用爻
        if(!_youyong[yaoPos])
        {
            MonthDayFactor factor(FLVL_DONG,-1,_yyreason[yaoPos]);
            _wangshuaiList[yaoPos]->factors.push_back(factor);
        }
        else
        {
            MonthDayFactor factor(FLVL_DONG,1,_yyreason[yaoPos]);
            _wangshuaiList[yaoPos]->factors.push_back(factor);
        }
            
    }
    DIZHI_ID mid = _jieguo->month()->get_dizhi().id();
    DIZHI_ID did = _jieguo->day()->get_dizhi().id();
    WUXING_ID ywx = _jieguo->yao_zhi(yaoPos)->get_wuxing();
    WUXING_ID mwx = _jieguo->month()->get_dizhi().get_wuxing();
    WUXING_ID dwx = _jieguo->day()->get_dizhi().get_wuxing();
    if(_wangshuaiList[yaoPos]->wo == mid)
    {
        MonthDayFactor factor(FLVL_RY_HIGH,1,"月建");
        _wangshuaiList[yaoPos]->factors.push_back(factor);
    }
    else if(_jieguo->yao_zhi(yaoPos)->get_liuhe().id() == mid) //月合
    {
        MonthDayFactor factor(FLVL_RY_HIGH,1,"月合");
        _wangshuaiList[yaoPos]->factors.push_back(factor);
    }
    else if(_jieguo->yao_zhi(yaoPos)->get_chong().id()== mid) //月冲(破)
    {
        MonthDayFactor factor(FLVL_RY_HIGH,-1,"月破");
        _wangshuaiList[yaoPos]->factors.push_back(factor);
    }
    else
    {
        MonthDayFactor factor(FLVL_RY_NORMAL);
        WUXING_SHENGKE skgx = WuxingShengkeGuanxi::get_shengke(ywx,mwx);
        switch (skgx)
        {
        case WXSK_GENERATED:    factor.score = 1; factor.reason = "月生";break;
        case WXSK_SAME:         factor.score = 1; factor.reason = "月扶";break;
        case WXSK_RESTRICTED:   factor.score = -1; factor.reason = "月克";break;
        case WXSK_RESTRICT:     factor.score = -1; factor.reason = "克月(囚)";break;
        case WXSK_GENERATE:     factor.score = -1; factor.reason = "生月(休)";break;
        default:break;
        }
        _wangshuaiList[yaoPos]->factors.push_back(factor);
    }
    //日
    if(_wangshuaiList[yaoPos]->wo == did)
    {
        MonthDayFactor factor(FLVL_RY_HIGH,1,"日建");
        _wangshuaiList[yaoPos]->factors.push_back(factor);        
    }
    else if((!_jieguo->yao_bian(yaoPos)) && _jieguo->yao_zhi(yaoPos)->get_liuhe().id() == did) //静爻日合
    {
        MonthDayFactor factor(FLVL_RY_HIGH,1,"静爻日合");
        _wangshuaiList[yaoPos]->factors.push_back(factor);    
    }
    else
    {
        MonthDayFactor factor(FLVL_RY_NORMAL);
        WUXING_SHENGKE skgx = WuxingShengkeGuanxi::get_shengke(ywx,dwx);
        if(skgx == WXSK_GENERATED)
        {
            factor.score = 1;
            factor.reason = "日生";
        }
        else if(skgx == WXSK_SAME)
        {
            factor.score = 1;
            factor.reason = "日扶";
        }
            
        else if(_jieguo->yao_zhi(yaoPos)->get_zhangsheng().id() == did)//长生
        {
            factor.score = 1;
            factor.reason = "长生";
        }
        else if(_jieguo->yao_zhi(yaoPos)->get_diwang().id() == did)//帝旺
        {
            factor.score = 1;
            factor.reason = "帝旺";
        }
            
        else if(skgx == WXSK_RESTRICTED)    //被日克
        {
            factor.score = -1;
            factor.reason = "日克";
        }
        else if(_jieguo->yao_zhi(yaoPos)->get_jue().id() == did) //绝
        {
            factor.score = -1;
            factor.reason = "日绝";
        }
        _wangshuaiList[yaoPos]->factors.push_back(factor);  
    }

    //初步组合
    //1、

}

AnalystJixiong::~AnalystJixiong()
{
    free();
}

void AnalystJixiong::free()
{
    for(int i=0;i<6;i++)
    {
        if(_wangshuaiList[i])
            delete _wangshuaiList[i];
        _wangshuaiList[i] = NULL;
    }
}

AnalystJixiong::AnalystJixiong()
{
    for(int i=0;i<6;i++)
    {
        _wangshuaiList[i] = NULL;
        _youyong[i] = false;
    }
}

void AnalystJixiong::init(ZhuangguaJieguo * jieguo)
{
    _jieguo = jieguo;
    for(int i=0;i<6;i++)
    {
    if(!_wangshuaiList[i])
        _wangshuaiList[i] = new YaoWangshuai();   
        //分析是否有用
        _youyong[i] = youyong(i,_yyreason[i]);
    }
    for(int i=0;i<6;i++)
    {
        analyse(i);
    }
    
}

bool AnalystJixiong::youyong(int yaoPos,std::string& reason)
{
    //1、回头克
    Dizhi & dz = _jieguo->bengua()->chonggua().yao(yaoPos)->get_ganzhi().get_dizhi();
    Dizhi & bz = _jieguo->zhigua()->chonggua().yao(yaoPos)->get_ganzhi().get_dizhi();
    WUXING_SHENGKE gx = WuxingShengkeGuanxi::get_shengke(dz.get_wuxing(),bz.get_wuxing());
    if(gx == WXSK_RESTRICTED) //被克
    {
        reason = "回头克";
        return false;
    }
    //2、化退
    if(Dizhi::jintui(dz,bz) == JTSI_TUI)
    {
        reason = "化退神";
        return false;
    }
    //3、化月破
    Dizhi& chongzhi = bz.get_chong();
    if(chongzhi.id() == _jieguo->month()->get_dizhi().id())
    {
        reason = "化月破";
        return false;
    }
    //4、化日破
    if(chongzhi.id() == _jieguo->day()->get_dizhi().id())
    {
        reason = "化日破";
        return false;
    }
    //5、化绝
    Dizhi& jue = dz.get_jue();
    if(jue.id() == bz.id())
    {
        if(WuxingShengkeGuanxi::get_shengke(dz.get_wuxing(),bz.get_wuxing())==WXSK_GENERATED)
        { 
            reason = "化绝：回头生";
            return true;
        }

        //无回头生
        reason = "化绝:无回头生";
        return false;
   }
   reason = "有用动爻";
   return true;
}
}