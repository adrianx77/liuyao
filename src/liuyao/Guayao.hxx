#ifndef _GUA_YAO_HXX_
#define _GUA_YAO_HXX_

#include "Yao.hxx"
#include "Liuqin.hxx"
#include "../najia/TianganDizhi.hxx"
namespace Zhouyi{

class GuaYao :public Yao{
protected:
    int             _yaowei;
    TianganDizhi&   _gz;
public:
    GuaYao(YAO_ID yao,TIANGAN_ID gan,DIZHI_ID zhi,int yaowei);
};

}


#endif//_GUA_YAO_HXX_