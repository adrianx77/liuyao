#ifndef __BASE_DEFINE_H_XX_
#define __BASE_DEFINE_H_XX_
#define  ELEMENT_JIN     "金"
#define  ELEMENT_SHUI    "水"
#define  ELEMENT_MU      "木"
#define  ELEMENT_HUO     "火"
#define  ELEMENT_TU      "土"

#define RELATION_SAME       "【%s】≡≡【%s】"
#define RELATION_RESTRICT   "【%s】->【%s】"
#define RELATION_RESTRICTED "【%s】<-【%s】"
#define RELATION_GENERATE   "【%s】=>【%s】"
#define RELATION_GENERATED  "【%s】<=【%s】"
#define RELATION_INVALID    "错误"

namespace Zhouyi{
    typedef enum {
        WUXING_INVALID  = -1,
        WUXING_JIN      = 0,    //金
        WUXING_SHUI,            //水
        WUXING_MU,              //木
        WUXING_HUO,             //火
        WUXING_TU               //土
    }WUXING_ID;

    typedef enum{
        WXSK_INVALID = -1, //错误
        WXSK_RESTRICT = 0, //克
        WXSK_RESTRICTED,   //被克
        WXSK_SAME,         //同
        WXSK_GENERATE,     //生
        WXSK_GENERATED     //被生
    }WUXING_SHENGKE;

    class BaseElement{
        public:

        

        static bool get_name(WUXING_ID element,char * name);
        static WUXING_SHENGKE get_shengke(WUXING_ID e1,WUXING_ID e2);
        static bool get_skgx_format(WUXING_SHENGKE r,char * name);

        static BaseElement * from(WUXING_ID element);
        BaseElement * clone();
        protected:
        BaseElement();
        
        static const char * _names[];
        static const char * _guanxi_format[];
        static BaseElement * _instance;
        
    private:
        void Init();
    };

}


#endif//__BASE_DEFINE_H_XX_
