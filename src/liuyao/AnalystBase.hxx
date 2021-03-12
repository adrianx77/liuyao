#ifndef _ANALYST_BASE_HXX
#define _ANALYST_BASE_HXX
#include "ZhuangguaJieguo.hxx"
namespace Zhouyi
{
    typedef enum {
        ANLVL_JIXIONG,  //吉凶层面
        ANLVL_XIJIE     //细节层面
    } ANALYSIS_LEVEL;

    typedef enum{
        WSF_DONGBIAN,
        WSF_RIYUE
    }WANGSHUAI_FACTOR;

    class AnalystBase{
    protected:
        ZhuangguaJieguo * _jieguo;
    public:
        virtual void init(ZhuangguaJieguo * jieguo){}
        virtual ~AnalystBase(){}
    };




} // namespace Zhouyi



#endif//_ANALYST_BASE_HXX

