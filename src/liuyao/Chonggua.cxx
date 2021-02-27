#include <stdlib.h>
#include <stdio.h>
#include "Chonggua.hxx"
namespace Zhouyi{
bool Chonggua::_init = false;
const char* guaxing[] = {
    "",GUAXING_LIUCHONG,GUAXING_LIUCHE,GUAXING_YOUHUN,GUAXING_GUIHUN
};

typedef struct 
{
    BAGUA_ID sgid;
    BAGUA_ID xgid;
    WUXING_ID wuxing;
    struct 
    {
        YAO_ID     yao;
        TIANGAN_ID gan;
        DIZHI_ID   zhi;
    }ganzhi[6];
}PURECHONGGUAINFO;
static PURECHONGGUAINFO PureChonggua[8] = 
{
    {BGID_QIAN,BGID_QIAN,WXID_JIN,{{YID_YANG,TGID_JIA,DZID_ZI},{YID_YANG,TGID_JIA,DZID_YIN},{YID_YANG,TGID_JIA,DZID_CHEN},{YID_YANG,TGID_REN,DZID_WU},{YID_YANG,TGID_REN,DZID_SHEN},{YID_YANG,TGID_REN,DZID_XU}}},
    {BGID_DUI,BGID_DUI,WXID_JIN,{{YID_YANG,TGID_DING,DZID_SI},{YID_YANG,TGID_DING,DZID_MAO},{YID_YING,TGID_DING,DZID_CHOU},{YID_YANG,TGID_DING,DZID_HAI},{YID_YANG,TGID_DING,DZID_YOU},{YID_YING,TGID_DING,DZID_WEI}}},
    {BGID_LI,BGID_LI,WXID_HUO,{{YID_YANG,TGID_JI,DZID_MAO},{YID_YING,TGID_JI,DZID_CHOU},{YID_YANG,TGID_JI,DZID_HAI},{YID_YANG,TGID_JI,DZID_YOU},{YID_YING,TGID_JI,DZID_WEI},{YID_YANG,TGID_JI,DZID_SI}}},
    {BGID_ZHEN,BGID_ZHEN,WXID_MU,{{YID_YANG,TGID_GEN,DZID_ZI},{YID_YING,TGID_GEN,DZID_YIN},{YID_YING,TGID_GEN,DZID_CHEN},{YID_YANG,TGID_GEN,DZID_WU},{YID_YANG,TGID_GEN,DZID_SHEN},{YID_YING,TGID_GEN,DZID_XU}}},
    {BGID_XUN,BGID_XUN,WXID_MU,{{YID_YING,TGID_XIN,DZID_CHOU},{YID_YANG,TGID_XIN,DZID_HAI},{YID_YANG,TGID_XIN,DZID_YOU},{YID_YING,TGID_XIN,DZID_WEI},{YID_YANG,TGID_XIN,DZID_SI},{YID_YANG,TGID_XIN,DZID_MAO}}},
    {BGID_KAN,BGID_KAN,WXID_SHUI,{{YID_YING,TGID_WU,DZID_YIN},{YID_YANG,TGID_WU,DZID_CHEN},{YID_YING,TGID_WU,DZID_WU},{YID_YING,TGID_WU,DZID_SHEN},{YID_YANG,TGID_WU,DZID_XU},{YID_YING,TGID_WU,DZID_ZI}}},
    {BGID_GEN,BGID_GEN,WXID_TU,{{YID_YING,TGID_BING,DZID_CHEN},{YID_YING,TGID_BING,DZID_WU},{YID_YANG,TGID_BING,DZID_SHEN},{YID_YING,TGID_BING,DZID_XU},{YID_YING,TGID_BING,DZID_ZI},{YID_YANG,TGID_BING,DZID_YIN}}},
    {BGID_KUN,BGID_KUN,WXID_TU,{{YID_YING,TGID_YI,DZID_WEI},{YID_YING,TGID_YI,DZID_SI},{YID_YING,TGID_YI,DZID_MAO},{YID_YING,TGID_GUI,DZID_CHOU},{YID_YING,TGID_GUI,DZID_HAI},{YID_YING,TGID_GUI,DZID_YOU}}}
};

typedef struct 
{
    BAGUA_ID gonggua;
    BAGUA_ID sgid;
    BAGUA_ID xgid;
    int  shiwei;
    int  yingwei;
    WUXING_ID wuxing;
    const char * name;
    GUAXING_ID   guaxing;
}CHONGGUAINFO;
static CHONGGUAINFO chonggua[8][8] = 
{
    {
        {BGID_QIAN,BGID_QIAN,BGID_QIAN,5,2,WXID_JIN,"乾为天",GXID_LIUCHONG},
        {BGID_QIAN,BGID_QIAN,BGID_XUN,0,3,WXID_JIN,"天风姤",GXID_KONG},
        {BGID_QIAN,BGID_QIAN,BGID_GEN,1,4,WXID_JIN,"天山遁",GXID_KONG},
        {BGID_QIAN,BGID_QIAN,BGID_KUN,2,5,WXID_JIN,"天地否",GXID_LIUHE},
        {BGID_QIAN,BGID_XUN,BGID_KUN,3,0,WXID_JIN,"风地观",GXID_KONG},
        {BGID_QIAN,BGID_GEN,BGID_KUN,4,1,WXID_JIN,"山地剥",GXID_KONG},
        {BGID_QIAN,BGID_LI,BGID_KUN,3,0,WXID_JIN,"火地晋",GXID_YOUHUN},
        {BGID_QIAN,BGID_LI,BGID_QIAN,2,5,WXID_JIN,"火天大有",GXID_GUIHUN},
    },
    {
        {BGID_DUI,BGID_DUI,BGID_DUI,5,2,WXID_JIN,"兑为泽",GXID_LIUCHONG},
        {BGID_DUI,BGID_DUI,BGID_KAN,0,3,WXID_JIN,"泽水困",GXID_LIUHE},
        {BGID_DUI,BGID_DUI,BGID_KUN,1,4,WXID_JIN,"泽地萃",GXID_KONG},
        {BGID_DUI,BGID_DUI,BGID_GEN,2,5,WXID_JIN,"泽山咸",GXID_KONG},
        {BGID_DUI,BGID_KAN,BGID_GEN,3,0,WXID_JIN,"水山蹇",GXID_KONG},
        {BGID_DUI,BGID_KUN,BGID_GEN,4,1,WXID_JIN,"地山谦",GXID_KONG},
        {BGID_DUI,BGID_ZHEN,BGID_GEN,3,0,WXID_JIN,"雷山小过",GXID_YOUHUN},
        {BGID_DUI,BGID_ZHEN,BGID_DUI,2,5,WXID_JIN,"雷泽归妹",GXID_GUIHUN},
    },
    {
        {BGID_LI,BGID_LI,BGID_LI,5,2,WXID_HUO,"离为火",GXID_LIUCHONG},
        {BGID_LI,BGID_LI,BGID_GEN,0,3,WXID_HUO,"火山旅",GXID_LIUHE},
        {BGID_LI,BGID_LI,BGID_XUN,1,4,WXID_HUO,"火风鼎",GXID_KONG},
        {BGID_LI,BGID_LI,BGID_KAN,2,5,WXID_HUO,"火水未既",GXID_KONG},
        {BGID_LI,BGID_GEN,BGID_KAN,3,0,WXID_HUO,"山水蒙",GXID_KONG},
        {BGID_LI,BGID_XUN,BGID_KAN,4,1,WXID_HUO,"风水涣",GXID_KONG},
        {BGID_LI,BGID_QIAN,BGID_KAN,3,0,WXID_HUO,"天水讼",GXID_YOUHUN},
        {BGID_LI,BGID_QIAN,BGID_LI,2,5,WXID_HUO,"火天大有",GXID_GUIHUN},
    },
    {
        {BGID_ZHEN,BGID_ZHEN,BGID_ZHEN,5,2,WXID_MU,"震为雷",GXID_LIUCHONG},
        {BGID_ZHEN,BGID_ZHEN,BGID_KUN,0,3,WXID_MU,"雷地豫",GXID_LIUHE},
        {BGID_ZHEN,BGID_ZHEN,BGID_KAN,1,4,WXID_MU,"雷水解",GXID_KONG},
        {BGID_ZHEN,BGID_ZHEN,BGID_XUN,2,5,WXID_MU,"雷风恒",GXID_KONG},
        {BGID_ZHEN,BGID_KUN,BGID_XUN,3,0,WXID_MU,"地风升",GXID_KONG},
        {BGID_ZHEN,BGID_KAN,BGID_XUN,4,1,WXID_MU,"水风井",GXID_KONG},
        {BGID_ZHEN,BGID_DUI,BGID_XUN,3,0,WXID_MU,"泽风大过",GXID_YOUHUN},
        {BGID_ZHEN,BGID_DUI,BGID_ZHEN,2,5,WXID_MU,"泽雷随",GXID_GUIHUN},
    },
    {
        {BGID_XUN,BGID_XUN,BGID_XUN,5,2,WXID_MU,"巽为风",GXID_LIUCHONG},
        {BGID_XUN,BGID_XUN,BGID_QIAN,0,3,WXID_MU,"风天小畜",GXID_KONG},
        {BGID_XUN,BGID_XUN,BGID_LI,1,4,WXID_MU,"风火家人",GXID_KONG},
        {BGID_XUN,BGID_XUN,BGID_ZHEN,2,5,WXID_MU,"风雷益",GXID_KONG},
        {BGID_XUN,BGID_QIAN,BGID_ZHEN,3,0,WXID_MU,"天雷无妄",GXID_LIUCHONG},
        {BGID_XUN,BGID_LI,BGID_ZHEN,4,1,WXID_MU,"火雷噬嗑",GXID_KONG},
        {BGID_XUN,BGID_GEN,BGID_ZHEN,3,0,WXID_MU,"山雷颐",GXID_YOUHUN},
        {BGID_XUN,BGID_GEN,BGID_XUN,2,5,WXID_MU,"山风蛊",GXID_GUIHUN},
    },
    {
        {BGID_KAN,BGID_KAN,BGID_KAN,5,2,WXID_SHUI,"坎为水",GXID_LIUCHONG},
        {BGID_KAN,BGID_KAN,BGID_DUI,0,3,WXID_SHUI,"水泽节",GXID_LIUHE},
        {BGID_KAN,BGID_KAN,BGID_ZHEN,1,4,WXID_SHUI,"水雷屯",GXID_KONG},
        {BGID_KAN,BGID_KAN,BGID_LI,2,5,WXID_SHUI,"水火既济",GXID_KONG},
        {BGID_KAN,BGID_DUI,BGID_LI,3,0,WXID_SHUI,"泽火革",GXID_KONG},
        {BGID_KAN,BGID_ZHEN,BGID_LI,4,1,WXID_SHUI,"雷火丰",GXID_KONG},
        {BGID_KAN,BGID_KUN,BGID_LI,3,0,WXID_SHUI,"地火明夷",GXID_YOUHUN},
        {BGID_KAN,BGID_KUN,BGID_KAN,2,5,WXID_SHUI,"地水师",GXID_GUIHUN},
    },
    {
        {BGID_GEN,BGID_GEN,BGID_GEN,5,2,WXID_TU,"艮为山",GXID_LIUCHONG},
        {BGID_GEN,BGID_GEN,BGID_LI,0,3,WXID_TU,"山火贲",GXID_LIUHE},
        {BGID_GEN,BGID_GEN,BGID_QIAN,1,4,WXID_TU,"山天大畜",GXID_KONG},
        {BGID_GEN,BGID_GEN,BGID_DUI,2,5,WXID_TU,"山泽损",GXID_KONG},
        {BGID_GEN,BGID_LI,BGID_DUI,3,0,WXID_TU,"火泽睽",GXID_KONG},
        {BGID_GEN,BGID_QIAN,BGID_DUI,4,1,WXID_TU,"天泽履",GXID_KONG},
        {BGID_GEN,BGID_XUN,BGID_DUI,3,0,WXID_TU,"风泽中孚",GXID_YOUHUN},
        {BGID_GEN,BGID_XUN,BGID_GEN,2,5,WXID_TU,"风山渐",GXID_GUIHUN},
    },
    {
        {BGID_KUN,BGID_KUN,BGID_KUN,5,2,WXID_TU,"坤为地",GXID_LIUCHONG},
        {BGID_KUN,BGID_KUN,BGID_ZHEN,0,3,WXID_TU,"地雷复",GXID_LIUHE},
        {BGID_KUN,BGID_KUN,BGID_DUI,1,4,WXID_TU,"地泽临",GXID_KONG},
        {BGID_KUN,BGID_KUN,BGID_QIAN,2,5,WXID_TU,"地天泰",GXID_LIUHE},
        {BGID_KUN,BGID_ZHEN,BGID_QIAN,3,0,WXID_TU,"雷天大壮",GXID_LIUCHONG},
        {BGID_KUN,BGID_DUI,BGID_QIAN,4,1,WXID_TU,"泽天夬",GXID_KONG},
        {BGID_KUN,BGID_KAN,BGID_QIAN,3,0,WXID_TU,"水天需",GXID_YOUHUN},
        {BGID_KUN,BGID_KAN,BGID_KUN,2,5,WXID_TU,"水地比",GXID_GUIHUN},
    }
};

Chonggua * Chonggua::_chonggua[8][8]={};

void Chonggua::init()
{
    if(_init)
        return;
    for(size_t i=0;i<8;i++)
    {
        for(size_t j=0;j<8;j++)
        {
            CHONGGUAINFO info = chonggua[i][j];
            PURECHONGGUAINFO xiaPureGua = PureChonggua[info.xgid];
            PURECHONGGUAINFO shangPureGua = PureChonggua[info.sgid];

            Chonggua * gua = new Chonggua(info.gonggua,
                                           info.sgid,
                                           info.xgid,
                                           info.shiwei,
                                           info.yingwei,
                                           info.wuxing,
                                           info.guaxing,
                                           info.name);

            for(int x=0;x<3;x++)
            {
                gua->_guayao[x] = new Guayao(xiaPureGua.ganzhi[x].yao,xiaPureGua.ganzhi[x].gan,xiaPureGua.ganzhi[x].zhi,x);
            }
            for(int s=3;s<6;++s)
            {
                gua->_guayao[s] = new Guayao(shangPureGua.ganzhi[s].yao,shangPureGua.ganzhi[s].gan,shangPureGua.ganzhi[s].zhi,s);
            }
            if(_chonggua[info.sgid][info.xgid]==NULL)
                _chonggua[info.sgid][info.xgid] = gua;
            else
            {
                printf("!!!!!!!!!!!");
            }
        }
    }

    _init = true;
}


Chonggua::Chonggua(BAGUA_ID gong,BAGUA_ID sgid,BAGUA_ID xgid,int s,int y,WUXING_ID wx,GUAXING_ID gx,const char * name)
            :_gonggua(Gua::from(gong))
            ,_shanggua(Gua::from(sgid))
            ,_xiagua(Gua::from(xgid)),
            _wuxing(Wuxing::from(wx)),
            _name(name),_guaxing(gx)
{
    _shiwei = s;
    _yingwei = y;
}

Chonggua & Chonggua::from(Gua& sgid,Gua& xgid)
{
    return Chonggua::from(sgid.get_id(),xgid.get_id());
}


Chonggua & Chonggua::from(BAGUA_ID sgid,BAGUA_ID xgid)
{
    Chonggua::init();
    return *_chonggua[sgid][xgid];
}

const char* Chonggua::get_guaxing_name()
{
    return guaxing[_guaxing];
}

const char* Chonggua::get_name()
{
    return _name;
}
Guayao * Chonggua::get_yao(int i)
{
    return _guayao[i];
}

Wuxing & Chonggua::get_wuxing()
{
    return _wuxing;
}
Gua & Chonggua::get_gonggua()
{
    return _gonggua;
}

int Chonggua::get_shiwei()
{
    return _shiwei;
}
int Chonggua::get_yingwei()
{
    return _yingwei;
}


}