#ifndef _YAOWANGSHUAI_HXX_
#define _YAOWANGSHUAI_HXX_
#include "ZhuangguaJieguo.hxx"
namespace Zhouyi{

typedef enum {
    ANLVL_JIXIONG,  //吉凶层面
    ANLVL_XIJIE     //细节层面
} ANALYSIS_LEVEL;

    // typedef enum{
    //     WSF_DONGBIAN,
    //     WSF_RIYUE
    // }WANGSHUAI_FACTOR;


typedef enum
{
    FLVL_DONG,
    FLVL_ANDONG,
    FLVL_RY_HIGH,
    FLVL_RY_NORMAL
}FACTOR_LEVEL;

class MonthDayFactor
{
public:    
    MonthDayFactor(FACTOR_LEVEL l)
    {
        level = l;
        score = 0;
    }
    MonthDayFactor(FACTOR_LEVEL l,int s,const char * r)
    {
        level = l;
        score = s;
        reason = r;
    }
    MonthDayFactor(FACTOR_LEVEL l,int s,std::string & r)
    {
        level = l;
        score = s;
        reason = r;
    }
    MonthDayFactor(const MonthDayFactor& rh)
    {
        level = rh.level;
        score = rh.score;
        reason = rh.reason;        
    }

    FACTOR_LEVEL level;
    int score;
    std::string reason;
};

typedef enum
{
    YYDY_JINGYAO,
    YYDY_YOUYONG,
    YYDY_WUYONG
}YOUYONGDONGYAO;

class YaoWangshuai
{
public:
    ANALYSIS_LEVEL      level;
    DIZHI_ID            wo;
    YOUYONGDONGYAO      youyong;
    std::string         yyreason;
    std::vector<MonthDayFactor>  factors;
    void push_factor(MonthDayFactor factor)
    {
        factors.push_back(factor);
    }
    void dum(std::string& reason)
    {
        //计算
        int dongscroe = 0;
        int hiscore = 0;
        int lowscore = 0;
        for(auto it = factors.begin();it!= factors.end();it++)
        {
            char sz[200];
            sprintf(sz,"%d",(*it).score);
            reason += (*it).reason;
            if((*it).level == FLVL_RY_HIGH)
            {
                reason +="H:";
                hiscore += (*it).score;
            }
            else if((*it).level == FLVL_RY_NORMAL)
            {
                reason +="N:";
                lowscore += (*it).score;
            }
            else
            {
                dongscroe +=  (*it).score;
                reason +="D:";
            }
            reason += sz;
            reason += "\t";
        }

        switch (youyong)
        {
            case YYDY_JINGYAO:
            break;
            case YYDY_WUYONG:
            reason += "变爻:";
            reason += yyreason;
            break;
            case YYDY_YOUYONG:
            reason += "变爻:";
            reason += yyreason;
            break;
        }

        std::string h =" 总体:";
        if(dongscroe>0)
        {
            h += "旺相";
        }
        else if(dongscroe<0)
        {
             h += "衰败";
        }
        else if(hiscore>0)
        {
            h += "旺相";
        }
        else if(hiscore<0)
        {
            h += "衰败";
        }
        else if(lowscore>0)
        {
            h += "旺相";
        }
        else if(lowscore<0)
        {
            h += "衰败";
        }
        else
        {
            h += "平相";
        }
        h += "\t";
        reason = h+reason;
    }
};
}

#endif //_YAOWANGSHUAI_HXX_