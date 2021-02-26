#ifndef _YAO_H_XX_
#define _YAO_H_XX_

#define YAONAME_YIN         "▆▆　▆▆"
#define YAONAME_YANG        "▆▆▆▆▆"
#define YAONAME_LAOYIN      "▆▆　▆▆x"
#define YAONAME_LAOYANG     "▆▆▆▆▆o"

namespace Zhouyi{


typedef enum{
    YID_YING,
    YID_YANG,
    YID_LAO_YING,
    YID_LAO_YANG
}YAO_ID;

class Yao{
protected:    
    YAO_ID _yao;
    static const char * _names[];
public:
    static void dump(); 

    YAO_ID get_id(){return _yao;}
    const char * get_name()const;
};
}
#endif//_YAO_H_XX_