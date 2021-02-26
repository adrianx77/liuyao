#include <stdlib.h>
#include "Yao.hxx"
namespace Zhouyi{

const char * Yao::_names[] = {YAONAME_YIN,YAONAME_YANG,YAONAME_LAOYIN,YAONAME_LAOYANG};

const char * Yao::get_name()const
{
    return _names[_yao];
}

void Yao::dump()
{
    
}


}


