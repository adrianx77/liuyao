#ifndef _WUXING_SHENGKE_GUANXI_HXX_
#define _WUXING_SHENGKE_GUANXI_HXX_
#include "Wuxing.hxx"

#define RELATION_SAME       "【%s】≡≡【%s】"
#define RELATION_RESTRICT   "【%s】->【%s】"
#define RELATION_RESTRICTED "【%s】<-【%s】"
#define RELATION_GENERATE   "【%s】=>【%s】"
#define RELATION_GENERATED  "【%s】<=【%s】"
#define RELATION_INVALID    "错误"

namespace Zhouyi{

class WuxingShengkeGuanxi 
{
    static WuxingShengkeGuanxi _guanxi[];
    static const char * _guanxi_format[];
public:
    WUXING_ID self;
    WUXING_ID generate;
    WUXING_ID restrict;
    WUXING_ID restricted;
    WUXING_ID generated;

    static const char * get_skgx_format(WUXING_SHENGKE r);
    static WUXING_SHENGKE get_shengke(WUXING_ID e1,WUXING_ID e2);
};

}
#endif //_WUXING_SHENGKE_GUANXI_HXX_    