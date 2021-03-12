#ifndef _ANALYST_JIXIONG_HXX_
#define _ANALYST_JIXIONG_HXX_
#include "AnalystBase.hxx"
#include <map>
namespace Zhouyi
{
typedef enum{
    DZGX_BEIKE,         //被克
    DZGX_KE,            //克
    DZGX_BEISHENG,      //被生
    DZGX_SHENG,         //生
    DZGX_FU,            //扶
    DZGX_CHONG,         //冲
    DZGX_LIUHE,         //六合
    DZGX_SANHE,         //三合局
    DZGX_ZHANGSHENG,    //长生
    DZGX_DIWANG,        //帝旺
    DZGX_MU,            //墓
    DZGX_JUE            //绝
}DIZHI_GUANXI;

typedef struct
{
    DIZHI_ID other;
}DZGX_BEIKE_INFO;

typedef struct
{
    DIZHI_ID other;
}DZGX_KE_INFO;

typedef struct 
{
    DIZHI_ID other;
}DZGX_BEISHENG_INFO;

typedef struct 
{
    DIZHI_ID other;
}DZGX_SHENG_INFO;

typedef struct 
{
    DIZHI_ID other;
}DZGX_FU_INFO;

typedef struct 
{
    DIZHI_ID other;
}DZGX_LIUHE_INFO;

typedef struct 
{
    DIZHI_ID other1;
    DIZHI_ID other2;
    DIZHI_ID other3;
    DIZHI_ID pattern;    
}DZGX_SANHE_INFO;

typedef struct
{
    DIZHI_ID other;
}DZGX_ZHANGSHENG_INFO;

typedef struct
{
    DIZHI_ID other;
}DZGX_DIWANG_INFO;

typedef struct
{
    DIZHI_ID other;
}DZGX_MU_INFO;

typedef struct
{
    DIZHI_ID other;
}DZGX_JUE_INFO;

typedef struct
{
    DIZHI_GUANXI guanxi;
    union
    {
        DZGX_BEIKE_INFO         beike;
        DZGX_KE_INFO            ke;
        DZGX_BEISHENG_INFO      beisheng;
        DZGX_SHENG_INFO         sheng;
        DZGX_FU_INFO            fu;
        DZGX_LIUHE_INFO         liuhe;
        DZGX_SANHE_INFO         sanhe;
        DZGX_ZHANGSHENG_INFO    zhangsheng;
        DZGX_DIWANG_INFO        diwang;
        DZGX_MU_INFO            mu;
        DZGX_JUE_INFO           jue;
    }guanxiInfo;
    
}YAOGUANXI_INFO;
typedef enum{
    WSID_WANG,
    WSID_PING,
    WSID_SHUAI
}WANGSHUAI_ID;


typedef enum
{
    FLVL_DONG,
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


class YaoWangshuai
{
public:
    ANALYSIS_LEVEL      level;
    DIZHI_ID            wo;
    std::vector<MonthDayFactor>  factors;
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
            reason += " ";
        }
        reason += " 总体:";
        if(dongscroe>0)
        {
            reason += "旺相";
        }
        else if(dongscroe<0)
        {
             reason += "衰败";
        }
        else if(hiscore>0)
        {
            reason += "旺相";
        }
        else if(hiscore<0)
        {
            reason += "衰败";
        }
        else if(lowscore>0)
        {
            reason += "旺相";
        }
        else if(lowscore<0)
        {
            reason += "衰败";
        }
        else
        {
            reason += "平相";
        }
    }
};

class AnalystJixiong:public AnalystBase{
protected:
    bool youyong(int yaoPos,std::string & reason);
    //是否有用
    bool        _youyong[6];
    std::string _yyreason[6];

    YaoWangshuai* _wangshuaiList[6];
    void free();
    void analyse(int yaoPos);
public:
    AnalystJixiong();
    YaoWangshuai* get_YaoWangshuai(int yaoPos);
    virtual void init(ZhuangguaJieguo * jieguo);
    virtual ~AnalystJixiong();
};


}

#endif//_ANALYST_JIXIONG_HXX_
