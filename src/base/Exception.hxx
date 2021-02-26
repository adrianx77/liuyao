#ifndef _LIUYAO_EXCEPTION_HXX_
#define _LIUYAO_EXCEPTION_HXX_
#include <string>
#include "ErrorCode.hxx"
namespace Zhouyi{
    class Exception{
        std::string _error;
    public:
        Exception(ERROR_ID error);
        Exception(const char * error);
        const char * error();
    };

}


#endif//_LIUYAO_EXCEPTION_HXX_
