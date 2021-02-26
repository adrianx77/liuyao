#ifndef _ERROR_CODE_HXX_
#define _ERROR_CODE_HXX_
#include <string>

namespace Zhouyi{



typedef enum{
    ERROR_INVALID   = -1,
    ERROR_OK        = 0,
    ERROR_GENERAL   = 1,
    ERROR_INVALID_ID,
    ERROR_GANZHI_NOT_MATCH,
    ERROR_MAXID
}ERROR_ID;

class Error{
    static const char* _Strings[];
    ERROR_ID    _code;
    std::string _error;
public:
    Error(const Error& e);
    Error(ERROR_ID error);
    Error(const char * error);
    const char * error();
    ERROR_ID code();
};

}
#endif//_ERROR_CODE_HXX_