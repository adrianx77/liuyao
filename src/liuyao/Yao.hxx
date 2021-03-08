#ifndef _YAO_H_XX_
#define _YAO_H_XX_

#define YAO_YIN         "▆▆　▆▆"
#define YAO_YANG        "▆▆▆▆▆"
#define YAO_LAOYIN      "▆▆　▆▆x"
#define YAO_LAOYANG     "▆▆▆▆▆o"

namespace Zhouyi{


typedef enum{
    YID_YING,
    YID_YANG,
    YID_LAO_YING,
    YID_LAO_YANG
}YAO_ID;

class Yao{
    Yao();
    Yao(Yao&);
protected:    
    YAO_ID _id;
    static const char * _names[];
public:
    operator YAO_ID ();
    YAO_ID id();
    Yao(YAO_ID id);
    const char * name()const;
};


}
#endif//_YAO_H_XX_