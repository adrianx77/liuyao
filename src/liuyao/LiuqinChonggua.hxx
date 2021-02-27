#ifndef _LIUQIN_CHONGGIA_HXX_
#define _LIUQIN_CHONGGIA_HXX_
#include "Chonggua.hxx"
namespace Zhouyi{


class LiuqinChonggua
{
private:
    /* data */
    Chonggua & _chonggua;
    Chonggua & _gonggua;
    Liuqin   * _liuqin[6];
    Liuqin    *_fushen[6];
    LiuqinChonggua();
    void checkFushen();
    void init();
public:
    LiuqinChonggua(Chonggua & chonggua);
    LiuqinChonggua(Chonggua & chonggua,Chonggua& gonggua);
    Chonggua & get_gonggua();
    Liuqin * get_liuqin(int y);
    Liuqin * get_fushen(int y);

};






}
#endif//_LIUQIN_CHONGGIA_HXX_