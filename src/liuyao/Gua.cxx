#include <stdlib.h>
#include <stdio.h>
#include "Gua.hxx"
#include "../base/Error.hxx"
namespace Zhouyi{

bool Gua::_init = false;
Gua * Gua::_guas[8] = {};

static WUXING_ID wuxing[8] = {WXID_JIN,WXID_JIN,WXID_HUO,WXID_MU,WXID_MU,WXID_SHUI,WXID_TU,WXID_TU};
static const char * Names[8] ={GUANAME_QIAN,GUANAME_DUI,GUANAME_LI,GUANAME_ZHEN,GUANAME_XUN,GUANAME_KAN,GUANAME_GEN,GUANAME_KUN};
static YAO_ID yaoIds[8][3] = {
    {YID_YANG,YID_YANG,YID_YANG},//乾
    {YID_YANG,YID_YANG,YID_YING},//兑
    {YID_YANG,YID_YING,YID_YANG},//离
	{YID_YANG,YID_YING,YID_YING},//震
	{YID_YING,YID_YANG,YID_YANG},//巽
	{YID_YING,YID_YANG,YID_YING},//坎
	{YID_YING,YID_YING,YID_YANG},//艮
	{YID_YING,YID_YING,YID_YING},//坤
};  

Gua::Gua(BAGUA_ID id):_id(id),
    _wuxing(Wuxing::from(wuxing[id]))
{
    for(int i=0;i<3;i++)
    {
        _yao[i] = new Yao(yaoIds[id][i]);
    }
}

void Gua::init()
{
    if(_init)
        return;

    for(size_t i=0;i<sizeof(_guas)/sizeof(_guas[0]);i++)
    {
        _guas[i] = new Gua((BAGUA_ID)i);
    }

    _init = true;
}

Yao & Gua::yao(YAOWEI_ID yaowei)
{
    return *_yao[yaowei];
}

Gua & Gua::from(BAGUA_ID id)
{
    init();
    return * _guas[id];
}
Gua & Gua::from(YAO_ID _1,YAO_ID _2,YAO_ID _3)
{
    init();
    for(int i=0;i<8;i++)
    {
        if(_1 == yaoIds[i][0] && _2 == yaoIds[i][1] && _3 == yaoIds[i][2])
        {
            return from((BAGUA_ID)i);
        }
    }
    throw Error(ERROR_INVALID_ID);
}
BAGUA_ID Gua::id()
{
    return _id;
}

const char * Gua::name()
{
    return Names[_id];
}


}