#include "Error.hxx"

namespace Zhouyi{

const char* Error::_Strings[] ={
    "ERROR_OK",
    "ERROR_GENERAL",
    "错误的ID",
    "不匹配的干支",
};

Error::Error(const Error& e)
{
    _code = e._code;
    _error = e._error;
}
Error::Error(ERROR_ID e)
{
    _code = e;
    if(e<ERROR_OK || e>=ERROR_MAXID)
        _error = "Error Id is wrong";
    else
        _error = _Strings[e];
}
Error::Error(const char * error)
{
    _code = ERROR_INVALID;
    _error = error;
}

const char * Error::error()
{
    return _error.c_str();
}

ERROR_ID Error::code()
{
    return _code;
}

}