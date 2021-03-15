#ifndef _ANALYST_JIXIONG_HXX_
#define _ANALYST_JIXIONG_HXX_
#include "YaoWangshuai.hxx"

#include <map>
namespace Zhouyi
{
// typedef enum{
//     DZGX_BEIKE,         //被克
//     DZGX_KE,            //克
//     DZGX_BEISHENG,      //被生
//     DZGX_SHENG,         //生
//     DZGX_FU,            //扶
//     DZGX_CHONG,         //冲
//     DZGX_LIUHE,         //六合
//     DZGX_SANHE,         //三合局
//     DZGX_ZHANGSHENG,    //长生
//     DZGX_DIWANG,        //帝旺
//     DZGX_MU,            //墓
//     DZGX_JUE            //绝
// }DIZHI_GUANXI;

// typedef struct
// {
//     DIZHI_ID other;
// }DZGX_BEIKE_INFO;

// typedef struct
// {
//     DIZHI_ID other;
// }DZGX_KE_INFO;

// typedef struct 
// {
//     DIZHI_ID other;
// }DZGX_BEISHENG_INFO;

// typedef struct 
// {
//     DIZHI_ID other;
// }DZGX_SHENG_INFO;

// typedef struct 
// {
//     DIZHI_ID other;
// }DZGX_FU_INFO;

// typedef struct 
// {
//     DIZHI_ID other;
// }DZGX_LIUHE_INFO;

// typedef struct 
// {
//     DIZHI_ID other1;
//     DIZHI_ID other2;
//     DIZHI_ID other3;
//     DIZHI_ID pattern;    
// }DZGX_SANHE_INFO;

// typedef struct
// {
//     DIZHI_ID other;
// }DZGX_ZHANGSHENG_INFO;

// typedef struct
// {
//     DIZHI_ID other;
// }DZGX_DIWANG_INFO;

// typedef struct
// {
//     DIZHI_ID other;
// }DZGX_MU_INFO;

// typedef struct
// {
//     DIZHI_ID other;
// }DZGX_JUE_INFO;

// typedef struct
// {
//     DIZHI_GUANXI guanxi;
//     union
//     {
//         DZGX_BEIKE_INFO         beike;
//         DZGX_KE_INFO            ke;
//         DZGX_BEISHENG_INFO      beisheng;
//         DZGX_SHENG_INFO         sheng;
//         DZGX_FU_INFO            fu;
//         DZGX_LIUHE_INFO         liuhe;
//         DZGX_SANHE_INFO         sanhe;
//         DZGX_ZHANGSHENG_INFO    zhangsheng;
//         DZGX_DIWANG_INFO        diwang;
//         DZGX_MU_INFO            mu;
//         DZGX_JUE_INFO           jue;
//     }guanxiInfo;
    
// }YAOGUANXI_INFO;
// typedef enum{
//     WSID_WANG,
//     WSID_PING,
//     WSID_SHUAI
// }WANGSHUAI_ID;



class AnalystJixiong{
protected:
    ZhuangguaJieguo * _jieguo;
    //是否有用
    void yaoyong(int yaoPos);

    //爻旺衰表
    YaoWangshuai* _wangshuaiList[6];
    void free();
    void yao_analyse(int yaoPos);
    void zhonghe_analyse(int yongPos);
public:
    AnalystJixiong();

    YaoWangshuai* get_YaoWangshuai(int yaoPos);
    virtual void init(ZhuangguaJieguo * jieguo);
    virtual ~AnalystJixiong();
    void setYongyao(int yongPos);
};


}

#endif//_ANALYST_JIXIONG_HXX_
