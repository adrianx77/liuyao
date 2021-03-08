#include <stdlib.h>
#include "Yao.hxx"
namespace Zhouyi{

const char * Yao::_names[] = {YAO_YIN,YAO_YANG,YAO_LAOYIN,YAO_LAOYANG};

const char * Yao::name()const
{
    return _names[_id];
}

Yao::operator YAO_ID ()
{
    return _id;
}

YAO_ID Yao::id()
{
    return _id;
}
Yao::Yao(YAO_ID id)
{
    _id = id;
}
}


