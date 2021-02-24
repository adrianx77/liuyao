#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "najia.hxx"
#include "element.hxx"




namespace Zhouyi{
    
const char * XunKong ::_names[] =   
{
    ZHI_XU ZHI_HAI,
    ZHI_ZI ZHI_CHOU,
    ZHI_YIN ZHI_MAO,
    ZHI_CHEN ZHI_SI,
    ZHI_WU ZHI_WEI,
    ZHI_SHEN ZHI_YOU
};
XunKong XunKong :: _xunkong[] = 
{
    {DZID_XU,DZID_HAI,0},
    {DZID_ZI,DZID_CHOU,1},
    {DZID_YIN,DZID_MAO,2},
    {DZID_CHEN,DZID_SI,3},
    {DZID_WU,DZID_WEI,4},
    {DZID_SHEN,DZID_YOU,5}
};
XunKong * XunKong ::from(DIZHIID x)
{
    return &_xunkong[x/2];
}
const char * XunKong::get_name()
{
    return _names[_index];
}

Xun * Xun::_xun[6] = {};
const char * Xun::_names[] = {
    GAN_JIA ZHI_ZI,   GAN_JIA ZHI_YIN,  GAN_JIA ZHI_CHEN, GAN_JIA ZHI_WU,  GAN_JIA ZHI_SHEN, GAN_JIA ZHI_XU 
};

bool Xun::_inited = false;
Xun::Xun(TIANGANID xg,DIZHIID xz)
{
    _gan = xg;
    _zhi   = xz;
    _xunkong = XunKong::from(xz);
}

void Xun::init()
{
    if(_inited)
        return;

    _xun[0] = new Xun(TGID_JIA ,DZID_ZI);   //戌 亥
    _xun[1] = new Xun(TGID_JIA ,DZID_YIN);  //子 丑
    _xun[2] = new Xun(TGID_JIA ,DZID_CHEN); //寅 卯
    _xun[3] = new Xun(TGID_JIA ,DZID_WU);   //辰 巳
    _xun[4] = new Xun(TGID_JIA ,DZID_SHEN); //午 未
    _xun[5] = new Xun(TGID_JIA ,DZID_XU);   //申 酉
    _inited = true;
}
 Xun* Xun::from(TIANGANID xg,DIZHIID xz)
 {
     for (size_t i = 0; i < sizeof(_xun)/sizeof(_xun[0]); i++)
     {
         if(_xun[i]->_gan == xg && _xun[i]->_zhi == xz)
         {
             return _xun[i];
         }
     }
     return NULL;
 }

XunKong * Xun::get_xunkong()
{
    return _xunkong;
}

const char * Xun::get_name()
{
    return _names[_zhi/2];
}
const char * TianganDizhi::_ganzi_name [][6] = {
    { GAN_JIA ZHI_ZI,   GAN_JIA ZHI_YIN,  GAN_JIA ZHI_CHEN, GAN_JIA ZHI_WU,  GAN_JIA ZHI_SHEN, GAN_JIA ZHI_XU  },
    { GAN_YI ZHI_CHOU,  GAN_YI ZHI_MAO,   GAN_YI ZHI_SI,    GAN_YI ZHI_WEI,  GAN_YI ZHI_YOU,   GAN_YI ZHI_HAI  },
    { GAN_BING ZHI_ZI,  GAN_BING ZHI_YIN, GAN_BING ZHI_CHEN,GAN_BING ZHI_WU, GAN_BING ZHI_SHEN,GAN_BING ZHI_XU },
    { GAN_DING ZHI_CHOU,GAN_DING ZHI_MAO, GAN_DING ZHI_SI,  GAN_DING ZHI_WEI,GAN_DING ZHI_YOU, GAN_DING ZHI_HAI},
    { GAN_WU ZHI_ZI,    GAN_WU ZHI_YIN,   GAN_WU ZHI_CHEN,  GAN_WU ZHI_WU,   GAN_WU ZHI_SHEN,  GAN_WU ZHI_XU   },
    { GAN_JI ZHI_CHOU,  GAN_JI ZHI_MAO,   GAN_JI ZHI_SI,    GAN_JI ZHI_WEI,  GAN_JI ZHI_YOU,   GAN_JI ZHI_HAI  },    
    { GAN_GENG ZHI_ZI,  GAN_GENG ZHI_YIN, GAN_GENG ZHI_CHEN,GAN_GENG ZHI_WU, GAN_GENG ZHI_SHEN,GAN_GENG ZHI_XU  },
    { GAN_XIN ZHI_CHOU, GAN_XIN ZHI_MAO,  GAN_XIN ZHI_SI,   GAN_XIN ZHI_WEI, GAN_XIN ZHI_YOU,  GAN_XIN ZHI_HAI },    
    { GAN_REN ZHI_ZI,   GAN_REN ZHI_YIN,  GAN_REN ZHI_CHEN, GAN_REN ZHI_WU,  GAN_REN ZHI_SHEN, GAN_REN ZHI_XU  },
    { GAN_GUI ZHI_CHOU, GAN_GUI ZHI_MAO,  GAN_GUI ZHI_SI,   GAN_GUI ZHI_WEI, GAN_GUI ZHI_YOU,  GAN_GUI ZHI_HAI }
};
// 甲子---乙丑---丙寅---丁卯---戊辰---己巳---庚午---辛未---壬申---癸酉 (遇)戌 亥
// 甲戌---乙亥---丙子---丁丑---戊寅---己卯---庚辰---辛巳---壬午---癸未 (遇)申 酉
// 甲申---乙酉---丙戌---丁亥---戊子---己丑---庚寅---辛卯---壬辰---癸巳 (遇)午 未
// 甲午---乙未---丙申---丁酉---戊戌---己亥---庚子---辛丑---壬寅---癸卯 (遇)辰 巳
// 甲辰---乙巳---丙午---丁未---戊申---己酉---庚戌---辛亥---壬子---癸丑 (遇)寅 卯
// 甲寅---乙卯---丙辰---丁巳---戊午---己未---庚申---辛酉---壬戌---癸亥 (遇)子 丑
TianganDizhi TianganDizhi::_ganzhi[][6] =
{
    { 
        {TGID_JIA ,DZID_ZI , TGID_JIA ,DZID_ZI}, 
        {TGID_JIA ,DZID_YIN, TGID_JIA ,DZID_YIN},
        {TGID_JIA ,DZID_CHEN,TGID_JIA ,DZID_CHEN},
        {TGID_JIA ,DZID_WU,  TGID_JIA ,DZID_WU},  
        {TGID_JIA ,DZID_SHEN,TGID_JIA ,DZID_SHEN}, 
        {TGID_JIA ,DZID_XU,  TGID_JIA ,DZID_XU}
    },
    {
        {TGID_YI  ,DZID_CHOU,TGID_JIA ,DZID_ZI},
        {TGID_YI  ,DZID_MAO, TGID_JIA ,DZID_YIN},
        {TGID_YI  ,DZID_SI,  TGID_JIA ,DZID_CHEN},
        {TGID_YI  ,DZID_WEI, TGID_JIA ,DZID_WU},
        {TGID_YI  ,DZID_YOU, TGID_JIA ,DZID_SHEN}, 
        {TGID_YI  ,DZID_HAI, TGID_JIA ,DZID_XU}
    },
    { 

        {TGID_BING,DZID_ZI,  TGID_JIA ,DZID_XU},  
        {TGID_BING,DZID_YIN, TGID_JIA ,DZID_ZI},
        {TGID_BING,DZID_CHEN,TGID_JIA ,DZID_YIN},
        {TGID_BING,DZID_WU,  TGID_JIA ,DZID_CHEN},
        {TGID_BING,DZID_SHEN,TGID_JIA ,DZID_WU},
        {TGID_BING,DZID_XU,  TGID_JIA ,DZID_SHEN}
    },
    {
        {TGID_DING,DZID_CHOU,TGID_JIA ,DZID_XU},  
        {TGID_DING,DZID_MAO, TGID_JIA ,DZID_ZI},
        {TGID_DING,DZID_SI,  TGID_JIA ,DZID_YIN}, 
        {TGID_DING,DZID_WEI, TGID_JIA ,DZID_CHEN},
        {TGID_DING,DZID_YOU, TGID_JIA ,DZID_WU},  
        {TGID_DING,DZID_HAI, TGID_JIA ,DZID_SHEN}
    },
    {
        {TGID_WU  ,DZID_ZI,  TGID_JIA ,DZID_SHEN},  
        {TGID_WU  ,DZID_YIN, TGID_JIA ,DZID_XU}, 
        {TGID_WU  ,DZID_CHEN,TGID_JIA ,DZID_ZI}, 
        {TGID_WU  ,DZID_WU,  TGID_JIA ,DZID_YIN},  
        {TGID_WU  ,DZID_SHEN,TGID_JIA ,DZID_CHEN}, 
        {TGID_WU  ,DZID_XU,  TGID_JIA ,DZID_WU}
    },
    {
        {TGID_JI  ,DZID_CHOU,TGID_JIA ,DZID_SHEN},
        {TGID_JI  ,DZID_MAO, TGID_JIA ,DZID_XU}, 
        {TGID_JI  ,DZID_SI,  TGID_JIA ,DZID_ZI},   
        {TGID_JI  ,DZID_WEI, TGID_JIA ,DZID_YIN}, 
        {TGID_JI  ,DZID_YOU, TGID_JIA ,DZID_CHEN}, 
        {TGID_JI  ,DZID_HAI, TGID_JIA ,DZID_WU}
    },
    {

        {TGID_GEN ,DZID_ZI,  TGID_JIA ,DZID_WU},  
        {TGID_GEN ,DZID_YIN, TGID_JIA ,DZID_SHEN}, 
        {TGID_GEN ,DZID_CHEN,TGID_JIA ,DZID_XU}, 
        {TGID_GEN ,DZID_WU,  TGID_JIA ,DZID_ZI},  
        {TGID_GEN ,DZID_SHEN,TGID_JIA ,DZID_YIN}, 
        {TGID_GEN ,DZID_XU,  TGID_JIA ,DZID_CHEN}
    },
    {
        {TGID_XIN ,DZID_CHOU,TGID_JIA ,DZID_WU},  
        {TGID_XIN ,DZID_MAO, TGID_JIA ,DZID_SHEN},
        {TGID_XIN ,DZID_SI,  TGID_JIA ,DZID_XU},    
        {TGID_XIN ,DZID_WEI, TGID_JIA ,DZID_ZI},  
        {TGID_XIN ,DZID_YOU, TGID_JIA ,DZID_YIN},   
        {TGID_XIN ,DZID_HAI, TGID_JIA ,DZID_CHEN}
    },
    {
        {TGID_REN ,DZID_ZI,  TGID_JIA ,DZID_CHEN},  
        {TGID_REN ,DZID_YIN, TGID_JIA ,DZID_WU}, 
        {TGID_REN ,DZID_CHEN,TGID_JIA ,DZID_SHEN}, 
        {TGID_REN ,DZID_WU,  TGID_JIA ,DZID_XU},  
        {TGID_REN ,DZID_SHEN,TGID_JIA ,DZID_ZI}, 
        {TGID_REN ,DZID_XU,  TGID_JIA ,DZID_YIN}
    },
    {
        {TGID_GUI ,DZID_CHOU,TGID_JIA ,DZID_CHEN}, 
        {TGID_GUI ,DZID_MAO, TGID_JIA ,DZID_WU}, 
        {TGID_GUI ,DZID_SI,  TGID_JIA ,DZID_SHEN},  
        {TGID_GUI ,DZID_WEI, TGID_JIA ,DZID_XU},  
        {TGID_GUI ,DZID_YOU, TGID_JIA ,DZID_ZI}, 
        {TGID_GUI ,DZID_HAI, TGID_JIA ,DZID_YIN}
    }
};

class DizhiXinxi                //地支信息  
{
public:
    DIZHIID     self;
    WUXING_ID   element;      //五行
    DIZHIID     impact;           //冲
    DIZHIID     sixcombine;       //六合
    DIZHIID     tricombine[2];    //三合
    DIZHIID     forward;          //进
    DIZHIID     backward;         //退
};

TianganDizhi::TianganDizhi(TIANGANID gan,DIZHIID zhi,TIANGANID xg,DIZHIID xz){
    Xun::init();
    _tiangan = gan;
    _dizhi   = zhi;
    _xun = Xun::from(xg,xz);
}

const char* TianganDizhi::get_name()
{
    if(_tiangan<0 || _tiangan<0)
        return NULL;

    if(_tiangan % 2 != _dizhi%2)
        return NULL;

    if(_tiangan>=10 || _tiangan>=12)
        return NULL;

    return _ganzi_name[_tiangan][_dizhi/2];        
}

TianganDizhi * TianganDizhi::from(TIANGANID gan,DIZHIID zhi)
{
    if(gan<0 || gan<0)
        return NULL;    

    if(gan % 2 != zhi%2)
        return NULL;

    if(gan>=10 || gan>=12)
        return NULL;
    return &_ganzhi[gan][zhi/2];
}

TianganDizhi* TianganDizhi::get_next()
{
    return from(Tiangan::get_next(_tiangan),Dizhi::get_next(_dizhi));
}


TianganDizhi* TianganDizhi::get_prev()
{
    return from(Tiangan::get_prev(_tiangan),Dizhi::get_prev(_dizhi));
}

 Xun* TianganDizhi::get_xun()
 {
    return _xun;
 }




}
