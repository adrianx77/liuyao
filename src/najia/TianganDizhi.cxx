#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TianganDizhi.hxx"
#include "Xun.hxx"
#include "../base/Wuxing.hxx"
#include "../base/Error.hxx"

namespace Zhouyi{
 
TianganDizhi* TianganDizhi::_ganzhi[10][6] ={};
const char * TianganDizhi::_ganzi_name [10][6] = {
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

bool TianganDizhi::_init =false;

typedef struct{
    TIANGAN_ID  tiangan;
    DIZHI_ID    dizhi;
    TIANGAN_ID  xungan;
    DIZHI_ID    xunzhi;
}TIANGGANDIZHIINFO;

TIANGGANDIZHIINFO GanzhiInfo[][6] =
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

class DizhiXinxi                  //地支信息  
{
public:
    DIZHI_ID     self;
    WUXING_ID   element;          //五行
    DIZHI_ID     impact;           //冲
    DIZHI_ID     sixcombine;       //六合
    DIZHI_ID     tricombine[2];    //三合
    DIZHI_ID     forward;          //进
    DIZHI_ID     backward;         //退
};

void TianganDizhi::init()
{
    if(_init)
        return;
    for(size_t i=0;i<10;i++)
    {
        for(size_t j=0;j<6;j++)
        {
            TIANGGANDIZHIINFO info = GanzhiInfo[i][j];
            TianganDizhi * gz = new TianganDizhi(info.tiangan,info.dizhi,info.xungan,info.xunzhi);
            _ganzhi[i][j] = gz;
        }
    }
    _init = true;        
}


TianganDizhi::TianganDizhi(TIANGAN_ID gan,DIZHI_ID zhi,TIANGAN_ID xg,DIZHI_ID xz)
    :_tiangan(Tiangan::from(gan)),_dizhi(Dizhi::from(zhi)),_xun(Xun::from(Tiangan::from(xg),Dizhi::from(xz)))
{
    _xun.push_ganzhi(this);
}

TianganDizhi::TianganDizhi(Tiangan& gan,Dizhi& zhi,Tiangan& xg,Dizhi& xz):_tiangan(gan),_dizhi(zhi),_xun(Xun::from(xg,xz))
{
    Xun::init();
    _xun.push_ganzhi(this);
}
const char* TianganDizhi::name()const
{
    if(_tiangan.id()<0 || _tiangan.id()<0)
        return NULL;

    if(_tiangan.id() % 2 != _dizhi.id()%2)
        return NULL;

    if(_tiangan.id()>=10 || _tiangan.id()>=12)
        return NULL;

    return _ganzi_name[_tiangan.id()][_dizhi.id()/2];        
}

TianganDizhi& TianganDizhi::from(Tiangan& gan,Dizhi& zhi)
{
    TianganDizhi::init();

    if(gan.id() % 2 != zhi.id()%2)
        throw Error(ERROR_GANZHI_NOT_MATCH);

    return *_ganzhi[gan.id()][zhi.id()/2];
}

TianganDizhi& TianganDizhi::get_next()
{
    return from(_tiangan.get_next(),_dizhi.get_next());
}


TianganDizhi& TianganDizhi::get_prev()
{
    return from(_tiangan.get_prev(),_dizhi.get_prev());
}

Xun& TianganDizhi::get_xun()
{
    return _xun;
}


}
