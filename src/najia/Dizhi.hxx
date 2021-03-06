#ifndef _DIZHI_HXX_
#define _DIZHI_HXX_
#include "../base/Wuxing.hxx"

#define  ZHI_ZI       "子"
#define  ZHI_CHOU     "丑"
#define  ZHI_YIN      "寅"
#define  ZHI_MAO      "卯"
#define  ZHI_CHEN     "辰"
#define  ZHI_SI       "巳"
#define  ZHI_WU       "午"
#define  ZHI_WEI      "未"
#define  ZHI_SHEN     "申"
#define  ZHI_YOU      "酉"
#define  ZHI_XU       "戌"
#define  ZHI_HAI      "亥"

namespace Zhouyi{

typedef enum {
    DZID_INVALIDE = -1,
    DZID_ZI = 0,
    DZID_CHOU,
    DZID_YIN,
    DZID_MAO,
    DZID_CHEN,
    DZID_SI,
    DZID_WU,
    DZID_WEI,
    DZID_SHEN,
    DZID_YOU,
    DZID_XU,
    DZID_HAI,
    DZID_MAX
}DIZHI_ID;


typedef enum{
    JTSI_INVALID = -1,
    JTSI_JIN = 0,
    JTSI_TUI,
    JTSI_MAX
}JINTUISHENG_INDEX;



//地支
class Dizhi{
protected:
    Dizhi(DIZHI_ID zhi);
    DIZHI_ID _dizhi;
//初始化
    static void init();
public:
    DIZHI_ID id()const;
    operator DIZHI_ID()const;
    static Dizhi& from(DIZHI_ID zhi);
    const char * name();
    Dizhi& get_next();
    Dizhi& get_prev();    
    Wuxing& get_wuxing();

    Dizhi&  get_zhangsheng();
    Dizhi&  get_diwang();
    Dizhi&  get_mu();
    Dizhi&  get_jue();
    Dizhi&  get_chong();
    Dizhi&  get_liuhe();

    static JINTUISHENG_INDEX jintui(Dizhi & z1,Dizhi & z2);
};

}
#endif//_DIZHI_HXX_