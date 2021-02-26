#ifndef _GUA_YAO_HXX_
#define _GUA_YAO_HXX_

#include "Yao.hxx"
#include "Liuqin.hxx"
#include "../najia/TianganDizhi.hxx"
namespace Zhouyi{

class GuaYao :public Yao{
    protected:
    int             _yaowei;
    TianganDizhi *  _gz;
    Liuqin *        _liuqin;
    public:
    GuaYao(TIANGAN_ID gan,DIZHI_ID zhi,LIUQIN_ID liuqin)
    {
        _gz = TianganDizhi::from(gan,zhi);
        _liuqin = new Liuqin(liuqin);
    }
}

}


#endif//_GUA_YAO_HXX_