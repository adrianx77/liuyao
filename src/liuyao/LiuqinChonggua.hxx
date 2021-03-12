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
    Chonggua & _gong;
    Liuqin   * _liuqin[6];
    Liuqin   * _fushen[6];
    LiuqinChonggua();
    void checkFushen();
    void init();
public:
    LiuqinChonggua(Chonggua & chonggua);
    LiuqinChonggua(Chonggua & chonggua,Chonggua& gonggua);
    Chonggua & gonggua();
    Chonggua & gong();
    Chonggua & chonggua();
    Liuqin * liuqin(int pos);
    Liuqin * fushen(int pos);
    bool     hasFushen();

};






}
#endif//_LIUQIN_CHONGGIA_HXX_