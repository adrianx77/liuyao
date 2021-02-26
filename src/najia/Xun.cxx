#include <stdio.h>
#include <stdlib.h>
#include "Xun.hxx"
#include "TianganDizhi.hxx"
#include "../base/Error.hxx"
namespace Zhouyi{
    
const char * XunKong ::_names[] =   
{
    ZHI_XU " " ZHI_HAI,
    ZHI_ZI " " ZHI_CHOU,
    ZHI_YIN " " ZHI_MAO,
    ZHI_CHEN " " ZHI_SI,
    ZHI_WU " " ZHI_WEI,
    ZHI_SHEN " " ZHI_YOU
};
XunKong XunKong :: _xunkong[] = 
{
    {DZID_XU,DZID_HAI,0},
    {DZID_ZI,DZID_CHOU,1},
    {DZID_YIN,DZID_MAO,2},
    {DZID_CHEN,DZID_SI,3},
    {DZID_WU,DZID_WEI,4},
    {DZID_SHEN,DZID_YOU,5}
};
XunKong::XunKong(DIZHI_ID dz1,DIZHI_ID dz2,int index)
{
    _dizhi1 = dz1;
    _dizhi2 = dz2;
    _index  = index;
}
XunKong& XunKong ::from(DIZHI_ID x)
{
    return _xunkong[x/2];
}
const char * XunKong::get_name()
{
    return _names[_index];
}

Xun * Xun::_xun[6] = {};
const char * Xun::_names[] = {
    GAN_JIA ZHI_ZI,   GAN_JIA ZHI_YIN,  GAN_JIA ZHI_CHEN, GAN_JIA ZHI_WU,  GAN_JIA ZHI_SHEN, GAN_JIA ZHI_XU 
};

bool Xun::_inited = false;
Xun::Xun(TIANGAN_ID xg,DIZHI_ID xz):_xunkong(XunKong::from(xz))
{
    _gan = xg;
    _zhi   = xz;
}

void Xun::init()
{
    if(_inited)
        return;

    _xun[0] = new Xun(TGID_JIA ,DZID_ZI);   //戌 亥
    _xun[1] = new Xun(TGID_JIA ,DZID_YIN);  //子 丑
    _xun[2] = new Xun(TGID_JIA ,DZID_CHEN); //寅 卯
    _xun[3] = new Xun(TGID_JIA ,DZID_WU);   //辰 巳
    _xun[4] = new Xun(TGID_JIA ,DZID_SHEN); //午 未
    _xun[5] = new Xun(TGID_JIA ,DZID_XU);   //申 酉
    _inited = true;
}
Xun& Xun::from(Tiangan& xg,Dizhi& xz)
{
    for (size_t i = 0; i < sizeof(_xun)/sizeof(_xun[0]); i++)
    {
        if(_xun[i]->_gan == xg.id() && _xun[i]->_zhi == xz.id())
        {
            return *_xun[i];
        }
    }
    throw Error(ERROR_INVALID_ID);
}
XunKong& Xun::get_xunkong()
{
    return _xunkong;
}
const char * Xun::get_name()
{
    return _names[_zhi/2];
}

void Xun::dump_xun()
{
    auto it = _ganzhi.begin();
    printf("%s",(*it)->get_name());
    ++it;
    for(;it!= _ganzhi.end();++it)
    {
        printf("---%s",(*it)->get_name());
    }
}
void Xun::push_ganzhi(TianganDizhi *gz)
{
    for(auto it = _ganzhi.begin();it != _ganzhi.end();++it)
    {
        if(gz->get_tiangan() < (*it)->get_tiangan())
        {
            _ganzhi.insert(it,gz);
            return ;
        }
        else if(gz->get_tiangan() == (*it)->get_tiangan())
        {
            return;
        }
    }
    _ganzhi.push_back(gz);
}        
}