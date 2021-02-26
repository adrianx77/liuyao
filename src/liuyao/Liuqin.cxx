#include <stdlib.h>
#include "Liuqin.hxx"
namespace Zhouyi{

const char * Liuqin::_names[] ={ LIUQIN_XIONGDI,LIUQIN_FUMU,LIUQIN_GUANGUI,LIUQIN_QICAI,LIUQIN_ZISUN};

Liuqin::Liuqin(LIUQIN_ID lq)
{
    _liuqin = lq;
}

LIUQIN_ID  Liuqin::get_Id()const
{
    return _liuqin;
}

const char * Liuqin::get_name()
{
    return _names[_liuqin];
}

}
