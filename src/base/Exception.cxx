#include <stdlib.h>
#include "Exception.hxx"

namespace Zhouyi{
    Exception::Exception(ERROR_ID e)
    {
        _error = Error::Strings[e];
    }
    Exception::Exception(const char * e)
    {
        _error = e;        
    }
    const char * Exception::error()
    {
        return _error.c_str();
    }
}