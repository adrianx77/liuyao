#include <stdlib.h>
#include "Liuqin.hxx"
namespace Zhouyi{
bool Liuqin::_init = false;

const char * Liuqin::_names[] ={ LIUQIN_XIONGDI,LIUQIN_FUMU,LIUQIN_GUANGUI,LIUQIN_QICAI,LIUQIN_ZISUN};
static LIUQIN_ID liuqinInit[]= {LQID_XIONGDI,LQID_FUMU,LQID_GUANGUI,LQID_QICAI,LQID_ZISUN};
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
LIUQIN_ID  Liuqin::id()const
{
    return _liuqin;
}

const char * Liuqin::get_name()
{
    return _names[_liuqin];
}

Liuqin::operator LIUQIN_ID() const
{
    return _liuqin;
}



}
