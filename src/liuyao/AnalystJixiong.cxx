#include "AnalystJixiong.hxx"
#include "../base/WuxingShengkeGuanxi.hxx"
namespace Zhouyi{
YaoWangshuai* AnalystJixiong::get_YaoWangshuai(int yaoPos)
{
    return _wangshuaiList[yaoPos];
}

void  AnalystJixiong::yao_analyse(int yaoPos)
{
    if(!_wangshuaiList[yaoPos])
        _wangshuaiList[yaoPos] = new YaoWangshuai();   

    YaoWangshuai * curWangshuai = _wangshuaiList[yaoPos];
    //1.分析动变
    curWangshuai->level = ANLVL_JIXIONG;
    curWangshuai->wo    = _jieguo->yao_zhi(yaoPos)->id();
    if(_jieguo->yao_bian(yaoPos))
    {
        
        //是否为无用爻
        if(curWangshuai->youyong == YYDY_WUYONG)
        {
            MonthDayFactor factor(FLVL_DONG,-1,curWangshuai->yyreason);
            curWangshuai->factors.push_back(factor);
        }
        else
        {
            MonthDayFactor factor(FLVL_DONG,1,curWangshuai->yyreason);
            curWangshuai->factors.push_back(factor);
        }
            
    }
    DIZHI_ID mid = _jieguo->month()->get_dizhi().id();
    DIZHI_ID did = _jieguo->day()->get_dizhi().id();
    WUXING_ID ywx = _jieguo->yao_zhi(yaoPos)->get_wuxing();
    WUXING_ID mwx = _jieguo->month()->get_dizhi().get_wuxing();
    WUXING_ID dwx = _jieguo->day()->get_dizhi().get_wuxing();
    if(curWangshuai->wo == mid)
    {
        MonthDayFactor factor(FLVL_RY_HIGH,1,"月建");
        curWangshuai->factors.push_back(factor);
    }
    else if(_jieguo->yao_zhi(yaoPos)->get_liuhe().id() == mid) //月合
    {
        MonthDayFactor factor(FLVL_RY_HIGH,1,"月合");
        curWangshuai->factors.push_back(factor);
    }
    else if(_jieguo->yao_zhi(yaoPos)->get_chong().id()== mid) //月冲(破)
    {
        MonthDayFactor factor(FLVL_RY_HIGH,-1,"月破");
        curWangshuai->factors.push_back(factor);
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
        curWangshuai->factors.push_back(factor);
    }
    //日
    if(curWangshuai->wo == did)
    {
        MonthDayFactor factor(FLVL_RY_HIGH,1,"日建");
        curWangshuai->factors.push_back(factor);        
    }
    else if((!_jieguo->yao_bian(yaoPos)) && _jieguo->yao_zhi(yaoPos)->get_liuhe().id() == did) //静爻日合
    {
        MonthDayFactor factor(FLVL_RY_HIGH,1,"静爻日合");
        curWangshuai->factors.push_back(factor);    
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
        else if(skgx == WXSK_GENERATE)
        {
            factor.score = 0;
            factor.reason = "生日";
        }
        else if(skgx == WXSK_RESTRICT)
        {
            factor.score = 0;
            factor.reason = "克日";
        }
        curWangshuai->factors.push_back(factor);
    }

    
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
        yaoyong(i);
    }
    for(int i=0;i<6;i++)
    {
        yao_analyse(i);
    }
}

bool MonthWang(Dizhi & yao, Dizhi & month)
{
    //月建
    if(yao.id() == month.id())
        return true;
    //月合
    if(yao.get_liuhe().id() == month.id())
        return true;
    //月生
    WUXING_SHENGKE sk = WuxingShengkeGuanxi::get_shengke(yao.get_wuxing().id(),month.get_wuxing().id());
    if(sk == WXSK_GENERATED)
        return true;
    //月扶
    if(sk == WXSK_SAME)
        return true;

    return false;
}

bool MonthQi(Dizhi & yao, Dizhi & month)
{
    if(month.id() == DZID_CHOU && yao.id() == DZID_ZI)
        return true;
    if(month.id() == DZID_CHEN && yao.id() == DZID_MAO)
        return true;
    if(month.id() == DZID_WEI && yao.id() == DZID_WU)
        return true;
    if(month.id() == DZID_XU && yao.id() == DZID_YOU)
        return true;
    return false;
}


void AnalystJixiong::zhonghe_analyse(int yongPos) //配合用爻分析暗动
{
    Dizhi & mdz = _jieguo->month()->get_dizhi();
    Dizhi & ddz = _jieguo->day()->get_dizhi();
    XunKong &xk = _jieguo->day()->get_xun().get_xunkong();
    //暗动
    //1、静爻得月令，日冲
    for(int i=0;i<6;i++)
    {
        if(!_jieguo->yao_bian(i))
        {
             Dizhi * yz = _jieguo->yao_zhi(i);
             if(yz->id() == xk.kong_id1() || yz->id() == xk.kong_id2())
             {
                if(ddz.get_chong() == yz->id())
                {
                    YaoWangshuai * curWangshuai = _wangshuaiList[i];
                    MonthDayFactor factor(FLVL_ANDONG,1,"旬空得冲暗动");
                    curWangshuai->push_factor(factor);
                }             
            }
             else if(MonthWang(*yz,mdz))
             {
                if(ddz.get_chong() == yz->id())
                {
                    YaoWangshuai * curWangshuai = _wangshuaiList[i];
                    MonthDayFactor factor(FLVL_ANDONG,1,"得月令旺暗动");
                    curWangshuai->push_factor(factor);
                }
             }
             else if(MonthQi(*yz,mdz))
             {
                if(ddz.get_chong() == yz->id())
                {
                    YaoWangshuai * curWangshuai = _wangshuaiList[i];
                    MonthDayFactor factor(FLVL_ANDONG,1,"得月气而暗动");
                    curWangshuai->push_factor(factor);
                }
             }
        }
    }
    //2、得

}


void AnalystJixiong::setYongyao(int yongPos)
{
    zhonghe_analyse(yongPos);
}

void AnalystJixiong::yaoyong(int yaoPos)
{
    YaoWangshuai * curWangshuai = _wangshuaiList[yaoPos];
    if(!_jieguo->zhigua()  ||!_jieguo->yao_bian(yaoPos) )
    {
        curWangshuai->youyong = YYDY_JINGYAO;
        return;
    }
    
    //1、回头克
    Dizhi & dz = _jieguo->bengua()->chonggua().yao(yaoPos)->get_ganzhi().get_dizhi();
    Dizhi & bz = _jieguo->zhigua()->chonggua().yao(yaoPos)->get_ganzhi().get_dizhi();
    WUXING_SHENGKE gx = WuxingShengkeGuanxi::get_shengke(dz.get_wuxing(),bz.get_wuxing());
    if(gx == WXSK_RESTRICTED) //被克
    {
        curWangshuai->yyreason = "回头克";
        curWangshuai->youyong = YYDY_WUYONG;
        return;
    }

    JINTUISHENG_INDEX jintui = Dizhi::jintui(dz,bz);
    //2、化退
    if(jintui == JTSI_TUI)
    {
        curWangshuai->yyreason = "化退神";
        curWangshuai->youyong = YYDY_WUYONG;
        return;

    }

    //3、化月破
    Dizhi& chongzhi = bz.get_chong();
    if(chongzhi.id() == _jieguo->month()->get_dizhi().id())
    {
        curWangshuai->yyreason = "化月破";
        curWangshuai->youyong = YYDY_WUYONG;
        return;

    }
    //4、化日破
    if(chongzhi.id() == _jieguo->day()->get_dizhi().id())
    {
        curWangshuai->yyreason = "化日破";
        curWangshuai->youyong = YYDY_WUYONG;
        return;

    }
    //5、化绝
    Dizhi& jue = dz.get_jue();
    if(jue.id() == bz.id())
    {
        if(WuxingShengkeGuanxi::get_shengke(dz.get_wuxing(),bz.get_wuxing())==WXSK_GENERATED)
        { 
            curWangshuai->yyreason = "化绝：回头生";
            curWangshuai->youyong = YYDY_YOUYONG;
            return;
        }

        //无回头生
        curWangshuai->yyreason = "化绝:无回头生";
        curWangshuai->youyong = YYDY_WUYONG;
        return;

    }

    //6、化进
    if(jintui == JTSI_JIN)
    {
        curWangshuai->yyreason = "化进神";
    }
    else if(_jieguo->yao_zhi(yaoPos)->get_liuhe().id() == bz.id())
    {
        curWangshuai->yyreason = "化六合";
    }
    else if(_jieguo->yao_zhi(yaoPos)->get_zhangsheng().id() == bz.id())
    {
        curWangshuai->yyreason = "化长生";
    }
    else if(gx == WXSK_GENERATED) //被生
    {
        curWangshuai->yyreason = "回头生";
    }
    else if(gx == WXSK_GENERATE)
    {
        curWangshuai->yyreason = "生变";
    }
    else if(gx == WXSK_RESTRICT)
    {
        curWangshuai->yyreason = "克变";
    }

    curWangshuai->youyong = YYDY_YOUYONG;
    return;
}
}
