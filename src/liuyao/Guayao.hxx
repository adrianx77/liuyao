#ifndef _GUA_YAO_HXX_
#define _GUA_YAO_HXX_

#include "Yao.hxx"
#include "Liuqin.hxx"
#include "../najia/TianganDizhi.hxx"
namespace Zhouyi{

class Guayao :public Yao{
protected:
    int             _yaowei;
    TianganDizhi&   _gz;
public:
    Guayao(YAO_ID yao,TIANGAN_ID gan,DIZHI_ID zhi,int yaowei);
    TianganDizhi& get_ganzhi();

};

}


#endif//_GUA_YAO_HXX_