#ifndef _LIUQIN_HXX_
#define _LIUQIN_HXX_

#define LIUQIN_XIONGDI   "兄弟"
#define LIUQIN_FUMU      "父母"
#define LIUQIN_GUANGUI   "官鬼"
#define LIUQIN_QICAI     "妻财"
#define LIUQIN_ZISUN     "子孙"

namespace Zhouyi{

typedef enum{
    LQID_XIONGDI,
    LQID_FUMU,
    LQID_GUANGUI,
    LQID_QICAI,
    LQID_ZISUN
}LIUQIN_ID;

class Liuqin{
protected:
    LIUQIN_ID    _liuqin;
    static const char * _names[];
public:
    Liuqin(LIUQIN_ID lq);
    LIUQIN_ID  get_Id()const;
    const char * get_name();
};


}


#endif//_LIUQIN_HXX_