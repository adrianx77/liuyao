#ifndef _YUCE_BASIC_HXX_
#define _YUCE_BASIC_HXX_
namespace Zhouyi{
template<typename T> inline  size_t countof(T arrays)
{
    return sizeof(arrays)/sizeof((arrays)[0]);
}

}
#endif// _YUCE_BASIC_HXX_
