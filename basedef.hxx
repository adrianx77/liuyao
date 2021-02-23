#ifndef __BASE_DEFINE_H_XX_
#define __BASE_DEFINE_H_XX_

#define  ELEMENT_JIN     "金"
#define  ELEMENT_SHUI    "水"
#define  ELEMENT_MU      "木"
#define  ELEMENT_HUO     "火"
#define  ELEMENT_TU      "土"

typedef enum {
    ELEMENTINDEX_JIN,
    ELEMENTINDEX_SHUI,
    ELEMENTINDEX_MU,
    ELEMENTINDEX_HUO,
    ELEMENTINDEX_TU
}ELEMENT_INDEX;

extern bool get_element_name(ELEMENT_INDEX element,char * name);
#endif//__BASE_DEFINE_H_XX_