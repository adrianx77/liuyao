#ifndef __BASE_DEFINE_H_XX_
#define __BASE_DEFINE_H_XX_
#include "element.hxx"
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
typedef enum {
    ELEMENTINDEX_JIN,
    ELEMENTINDEX_SHUI,
    ELEMENTINDEX_MU,
    ELEMENTINDEX_HUO,
    ELEMENTINDEX_TU
}ELEMENT_INDEX;

typedef enum{
    ER_RESTRICT,    //克
    ER_RESTRICTED,  //被克
    ER_SAME,        //同
    ER_GENERATE,    //生
    ER_GENERATED,    //被生
    ER_INVALID       //错误
}ELEMENT_RELATION;

extern bool get_element_name(ELEMENT_INDEX element,char * name);
extern ELEMENT_RELATION get_relation(ELEMENT_INDEX e1,ELEMENT_INDEX e2);
extern bool get_relation_name(ELEMENT_RELATION r,char * name);
#endif//__BASE_DEFINE_H_XX_