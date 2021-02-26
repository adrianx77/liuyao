#include "Guayao.hxx"
#include "../najia/Dizhi.hxx"
#include "../najia/Tiangan.hxx"

namespace Zhouyi{

Guayao::Guayao(YAO_ID yao,TIANGAN_ID gan,DIZHI_ID zhi,int yaowei)
    :_gz(TianganDizhi::from(Tiangan::from(gan),Dizhi::from(zhi)))
    ,Yao(yao)
    ,_yaowei(yaowei)
{
    
}
TianganDizhi& Guayao::get_ganzhi()
{
    return _gz;
}
}