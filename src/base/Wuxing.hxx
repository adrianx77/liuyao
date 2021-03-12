#ifndef __BASE_DEFINE_H_XX_
#define __BASE_DEFINE_H_XX_

#define  WUXING_JIN     "金"
#define  WUXING_SHUI    "水"
#define  WUXING_MU      "木"
#define  WUXING_HUO     "火"
#define  WUXING_TU      "土"

namespace Zhouyi{
typedef enum {
    WXID_INVALID  = -1,
    WXID_JIN      = 0,    //金
    WXID_SHUI,            //水
    WXID_MU,              //木
    WXID_HUO,             //火
    WXID_TU,               //土
    WXID_MAX
}WUXING_ID;

typedef enum{
    WXSK_INVALID = -1, //错误
    WXSK_RESTRICT = 0, //克
    WXSK_RESTRICTED,   //被克
    WXSK_SAME,         //同
    WXSK_GENERATE,     //生
    WXSK_GENERATED     //被生
}WUXING_SHENGKE;

class Wuxing{
public:
    static Wuxing &from(WUXING_ID wx);
    Wuxing * clone();
    const char* name() const;
    WUXING_ID   id() const;
    operator WUXING_ID()const;
    WUXING_SHENGKE get_shengke(Wuxing * wx);
// 初始化
    static bool _init;
    static void init();    
protected:
    WUXING_ID   _baseWuxing;
    Wuxing(WUXING_ID wx);
    static Wuxing* _wuxing[];
    static const char * _names[];
};

}


#endif//__BASE_DEFINE_H_XX_

