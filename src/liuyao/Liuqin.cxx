#include <stdlib.h>
#include "Liuqin.hxx"
#include "../base/Error.hxx"
namespace Zhouyi{
bool Liuqin::_init = false;

const char * Liuqin::_names[] ={ LIUQIN_XIONGDI,LIUQIN_FUMU,LIUQIN_GUANGUI,LIUQIN_QICAI,LIUQIN_ZISUN};
static LIUQIN_ID liuqinInit[]= {LQID_XIONGDI,LQID_FUMU,LQID_GUANGUI,LQID_QICAI,LQID_ZISUN};

struct 
{
    WUXING_ID wo;
    WUXING_ID ta;
    LIUQIN_ID liuqin;
}liuqinInfo[25] = {
    {WXID_JIN,WXID_JIN, LQID_XIONGDI},
    {WXID_JIN,WXID_SHUI,LQID_ZISUN},
    {WXID_JIN,WXID_MU,  LQID_QICAI},
    {WXID_JIN,WXID_HUO, LQID_GUANGUI},
    {WXID_JIN,WXID_TU,  LQID_FUMU},

    {WXID_SHUI,WXID_JIN,LQID_FUMU},
    {WXID_SHUI,WXID_SHUI,LQID_XIONGDI},
    {WXID_SHUI,WXID_MU ,LQID_ZISUN},
    {WXID_SHUI,WXID_HUO,LQID_QICAI},
    {WXID_SHUI,WXID_TU ,LQID_GUANGUI},

    {WXID_MU,WXID_JIN,LQID_GUANGUI},
    {WXID_MU,WXID_SHUI,LQID_FUMU},
    {WXID_MU,WXID_MU ,LQID_XIONGDI},
    {WXID_MU,WXID_HUO,LQID_ZISUN},
    {WXID_MU,WXID_TU ,LQID_QICAI},

    {WXID_HUO,WXID_JIN,LQID_QICAI},
    {WXID_HUO,WXID_SHUI,LQID_GUANGUI},
    {WXID_HUO,WXID_MU ,LQID_FUMU},
    {WXID_HUO,WXID_HUO,LQID_XIONGDI},
    {WXID_HUO,WXID_TU ,LQID_ZISUN},

    {WXID_TU,WXID_JIN,LQID_ZISUN},
    {WXID_TU,WXID_SHUI,LQID_QICAI},
    {WXID_TU,WXID_MU ,LQID_GUANGUI},
    {WXID_TU,WXID_HUO,LQID_FUMU},
    {WXID_TU,WXID_TU ,LQID_XIONGDI}
};


Liuqin * Liuqin::_liuqins[5] ={};

void Liuqin::init()
{
    if(_init)
        return;
    for(size_t i=0;i<sizeof(_liuqins)/sizeof(_liuqins[0]);++i)
    {
        _liuqins[i] = new Liuqin(liuqinInit[i]);
    }

    _init = true;
}

Liuqin::Liuqin(LIUQIN_ID lq)
{
    _liuqin = lq;
}
Liuqin & Liuqin::from(LIUQIN_ID lq)
{
    Liuqin::init();
    return *_liuqins[lq];
}

Liuqin & Liuqin::from(WUXING_ID wo,WUXING_ID ta)
{
    for(int i=0;i<sizeof(liuqinInfo)/sizeof(liuqinInfo[0]);i++)
    {
        if(liuqinInfo[i].wo == wo && liuqinInfo[i].ta == ta)
        {
            return Liuqin::from(liuqinInfo[i].liuqin);
        }
    }

    throw Error(ERROR_INVALID_ID);    
}

Liuqin & Liuqin::from(Dizhi& wo, Dizhi & ta)
{
    Wuxing& wow = wo.get_wuxing();
    Wuxing& taw = ta.get_wuxing();

    for(int i=0;i<sizeof(liuqinInfo)/sizeof(liuqinInfo[0]);i++)
    {
        if(liuqinInfo[i].wo == wow.id() && liuqinInfo[i].ta == taw.id())
        {
            return Liuqin::from(liuqinInfo[i].liuqin);
        }
    }

    throw Error(ERROR_INVALID_ID);
}

LIUQIN_ID  Liuqin::id()const
{
    return _liuqin;
}

const char * Liuqin::name()
{
    return _names[_liuqin];
}

Liuqin::operator LIUQIN_ID() const
{
    return _liuqin;
}



}
