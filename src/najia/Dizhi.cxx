#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Dizhi.hxx"
#include "../base/Error.hxx"
#include "../base/basic.hxx"

namespace Zhouyi{
typedef enum{
    YZSID_INVALID       = -1,
    YZSID_ZHANGSHENG,
    YZSID_MUYU,
    YZSID_GUANDAI,
    YZSID_LINGUAN,
    YZSID_DIWANG,
    YZSID_SHUAI,
    YZSID_BING,
    YZSID_SI,
    YZSID_MU,        
    YZSID_JUE,
    YZSID_TAI,
    YZSID_YANG,
    YZSID_MAX
}YAOZHANGSHENG_ID;

typedef struct 
{
    WUXING_ID yao;
    DIZHI_ID  zsList[YZSID_MAX];
}ZHANGHENGINFO;

static ZHANGHENGINFO ZhangshengInfo[WXID_MAX] = {
    {WXID_JIN,  {DZID_SI,DZID_WU,DZID_WEI,DZID_SHEN,DZID_YOU,DZID_XU,DZID_HAI,DZID_ZI,DZID_CHOU,DZID_YIN,DZID_MAO,DZID_CHEN}},
    {WXID_SHUI, {DZID_SHEN,DZID_YOU,DZID_XU,DZID_HAI,DZID_ZI,DZID_CHOU,DZID_YIN,DZID_MAO,DZID_CHEN,DZID_SI,DZID_WU,DZID_WEI}},
    {WXID_MU,   {DZID_HAI,DZID_ZI,DZID_CHOU,DZID_YIN,DZID_MAO,DZID_CHEN,DZID_SI,DZID_WU,DZID_WEI,DZID_SHEN,DZID_YOU,DZID_XU}},
    {WXID_HUO,  {DZID_YIN,DZID_MAO,DZID_CHEN,DZID_SI,DZID_WU,DZID_WEI,DZID_SHEN,DZID_YOU,DZID_XU,DZID_HAI,DZID_ZI,DZID_CHOU}},
    {WXID_TU,   {DZID_SHEN,DZID_YOU,DZID_XU,DZID_HAI,DZID_ZI,DZID_CHOU,DZID_YIN,DZID_MAO,DZID_CHEN,DZID_SI,DZID_WU,DZID_WEI}}
};

//寅化卯、巳化午、申化酉、亥化子、丑化辰、辰化未、未化戌、戌化丑 【进】
typedef struct 
{
    DIZHI_ID beng;     //我
    DIZHI_ID jintui;   //进退
}JINTUISHEN;

static JINTUISHEN JinTuishengInfo[JTSI_MAX][8] = {
    {{DZID_YIN,DZID_MAO},{DZID_SI,DZID_WU},{DZID_SHEN,DZID_YOU},{DZID_HAI,DZID_ZI},{DZID_CHOU,DZID_CHEN},{DZID_CHEN,DZID_WEI},{DZID_WEI,DZID_XU},{DZID_XU,DZID_CHOU}},
    {{DZID_MAO,DZID_YIN},{DZID_WU,DZID_SI},{DZID_YOU,DZID_SHEN},{DZID_ZI,DZID_HAI},{DZID_CHEN,DZID_CHOU},{DZID_WEI,DZID_CHEN},{DZID_XU,DZID_WEI},{DZID_CHOU,DZID_XU}}
};

static DIZHI_ID ChongList[DZID_MAX] ={
    DZID_WU,    //子<->午
    DZID_WEI,   //丑<->未
    DZID_SHEN,  //寅<->申
    DZID_YOU,   //卯<->酉
    DZID_XU,    //戌<->辰
    DZID_HAI,   //亥<->巳
    DZID_ZI,    //子<->午
    DZID_CHOU,  //丑<->未
    DZID_YIN,   //寅<->申
    DZID_MAO,   //卯<->酉
    DZID_CHEN,  //戌<->辰
    DZID_SI     //亥<->巳
};


static DIZHI_ID LiuheList[DZID_MAX] ={
    DZID_CHOU,  //子 <-> 丑
    DZID_ZI,    //丑 <-> 子
    DZID_HAI,   //寅 <-> 亥
    DZID_XU,    //卯 <-> 戌
    DZID_YOU,   //辰 <-> 酉
    DZID_SHEN,  //巳 <-> 申
    DZID_WEI,   //午 <-> 未
    DZID_WU,    //未 <-> 午
    DZID_SI,    //申 <-> 巳
    DZID_CHOU,  //酉 <-> 辰
    DZID_MAO,   //戌 <-> 卯
    DZID_YIN    //亥 <-> 寅
};


static bool Init = false;
static DIZHI_ID DizhiInit [DZID_MAX] = {DZID_ZI,DZID_CHOU,DZID_YIN,DZID_MAO,DZID_CHEN,DZID_SI,DZID_WU,DZID_WEI,DZID_SHEN,DZID_YOU,DZID_XU,DZID_HAI};
static WUXING_ID Wuxings[DZID_MAX] = {WXID_SHUI,WXID_TU,WXID_MU,WXID_MU,WXID_TU,WXID_HUO,WXID_HUO,WXID_TU,WXID_JIN,WXID_JIN,WXID_TU,WXID_SHUI};
static const char * Names[DZID_MAX]   = {ZHI_ZI,ZHI_CHOU,ZHI_YIN,ZHI_MAO,ZHI_CHEN,ZHI_SI,ZHI_WU, ZHI_WEI, ZHI_SHEN,ZHI_YOU,ZHI_XU,ZHI_HAI};
static Dizhi* Dizhis[DZID_MAX];

Dizhi::Dizhi(DIZHI_ID z)
{
    if(z<0 || z>DZID_HAI)
        throw Error(ERROR_INVALID_ID);
    _dizhi = z;
}
DIZHI_ID Dizhi::id()const
{
    return _dizhi;
}

void Dizhi::init()
{
    if(Init)
        return;
    for(size_t i=0;i<countof(DizhiInit);i++)
    {
        Dizhis[i] = new Dizhi(DizhiInit[i]);
    }
    Init = true;        
}

Dizhi::operator DIZHI_ID()const
{
    return _dizhi;
}
Dizhi& Dizhi::from(DIZHI_ID z)
{
    Dizhi::init();
    if(z<0 || z>DZID_HAI)
        throw Error(ERROR_INVALID_ID);
    return *Dizhis[z];
}

const char * Dizhi::name()
{
    if(_dizhi<0)
        return NULL;
    if(_dizhi>=countof(Names))
        return NULL;  
    return Names[_dizhi];
}

Dizhi& Dizhi::get_next()
{
    int b = _dizhi;
    b++;
    if(b >DZID_HAI)
        b = 0;
    return Dizhi::from((DIZHI_ID)b);
}
Dizhi& Dizhi::get_prev()
{
    int b = _dizhi;
    b--;
    if(b <0)        
        b = DZID_HAI;
    return Dizhi::from((DIZHI_ID)b);
}

Wuxing& Dizhi::get_wuxing()
{
    return Wuxing::from(Wuxings[_dizhi]);
}

Dizhi&  Dizhi::get_zhangsheng()
{
    WUXING_ID wxid = get_wuxing().id();
    return Dizhi::from(ZhangshengInfo[wxid].zsList[YZSID_ZHANGSHENG]);
}
Dizhi&  Dizhi::get_diwang()
{
    WUXING_ID wxid = get_wuxing().id();
    return Dizhi::from(ZhangshengInfo[wxid].zsList[YZSID_DIWANG]);
}
Dizhi&  Dizhi::get_mu()
{
    WUXING_ID wxid = get_wuxing().id();
    return Dizhi::from(ZhangshengInfo[wxid].zsList[YZSID_MU]);
}
Dizhi&  Dizhi::get_jue()
{
    WUXING_ID wxid = get_wuxing().id();
    return Dizhi::from(ZhangshengInfo[wxid].zsList[YZSID_JUE]);
}
Dizhi&  Dizhi::get_chong()
{
    return Dizhi::from(ChongList[_dizhi]);
}
Dizhi&  Dizhi::get_liuhe()
{
    return Dizhi::from(LiuheList[_dizhi]);
}
JINTUISHENG_INDEX Dizhi::jintui(Dizhi & z1,Dizhi & z2)
{
    DIZHI_ID i1 = z1.id();
    DIZHI_ID i2 = z2.id();
    for(int i=0;i<JTSI_MAX;i++)
    {
        for(int j =0;j<countof(JinTuishengInfo[JTSI_JIN]);j++)
        {
            if(JinTuishengInfo[i]->beng == i1 && JinTuishengInfo[i]->jintui == i2)
            {
                return (JINTUISHENG_INDEX)i;
            }
        }
    }
    return JTSI_INVALID;

}





}


