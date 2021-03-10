#include "../base/Wuxing.hxx"
#include "../base/Error.hxx"
#include "liushen.hxx"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



namespace Zhouyi{
    
static bool _init = false;

static const char * Names[] = {
    LIUSHEN_QINGLONG,LIUSHEN_ZHUQUE,LIUSHEN_GOUCHEN,LIUSHEN_TENGSHE,LIUSHEN_BAIHU,LIUSHEN_XUANWU
};

static Liushen * LiushenTable[6] = {};


Liushen::Liushen(LIUSHEN_ID id)
{
    _id = id;
}

void Liushen::init()
{
    if(_init)
        return ;
    for(int i=0;i<6;++i)
    {
        LiushenTable[i] = new Liushen(LIUSHEN_ID(i));
    }
    _init = true;
}

Liushen * Liushen::from(TIANGAN_ID gan)
{
    init();    
    switch(gan)
    {
    case TGID_JIA:
    case TGID_YI:return LiushenTable[0];
    case TGID_BING:
    case TGID_DING:return LiushenTable[1];
    case TGID_WU:return LiushenTable[2];
    case TGID_JI:return LiushenTable[3];
    case TGID_GEN:
    case TGID_XIN:return LiushenTable[4];
    case TGID_REN:
    case TGID_GUI:return LiushenTable[5];
    default:
        throw Error(ERROR_INVALID_ID);
    }
}
Liushen * Liushen::from(Lunar *lunar)
{
    TIANGAN_ID gan = lunar->day()->get_tiangan().id();
    return Liushen::from(gan);
}
LIUSHEN_ID Liushen::id()
{
    return _id;
}
const char * Liushen::name()
{
    return Names[_id];
}

Liushen * Liushen::next()
{
    switch (_id)
    {
    case LSID_QINGLONG:return LiushenTable[1];
    case LSID_ZHUQUE:return LiushenTable[2];
    case LSID_GOUCHEN:return LiushenTable[3];
    case LSID_TENGSHE:return LiushenTable[4];
    case LSID_BAIHU:return LiushenTable[5];
    case LSID_XUANWU:return LiushenTable[0];
    default:
        throw Error(ERROR_INVALID_ID);
    }
}

}

