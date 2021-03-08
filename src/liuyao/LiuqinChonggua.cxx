#include "LiuqinChonggua.hxx"
#include <map>
#include <set>

namespace Zhouyi{

void LiuqinChonggua::init()
{
    Wuxing & Wo = _gonggua.wuxing();
    for(size_t i =0;i<6;i++)
    {
        TianganDizhi &z = _chonggua.yao(i)->get_ganzhi();
        _liuqin[i] = &Liuqin::from(Wo,z.get_dizhi().get_wuxing());
        _fushen[i] = NULL;
    }
    
    checkFushen();
}

LiuqinChonggua::LiuqinChonggua(Chonggua & chonggua,Chonggua& gonggua)
                :_chonggua(chonggua),
                _gonggua(gonggua),
                _gong(Chonggua::from(_chonggua.gonggua(),_chonggua.gonggua()))
{
    init();
}
LiuqinChonggua::LiuqinChonggua(Chonggua & chonggua)
                :_chonggua(chonggua),
                _gonggua(Chonggua::from(_chonggua.gonggua(),_chonggua.gonggua())),
                _gong(_gonggua)
{
    init();
}

void LiuqinChonggua::checkFushen()
{
    std::map<LIUQIN_ID,bool> liuqins;
    for(size_t i =0;i<5;i++)
    {
        liuqins[(LIUQIN_ID)i] = false;
    }
    for(size_t i =0;i<6;i++)
    {
        LIUQIN_ID id =_liuqin[i]->id();
        liuqins[id] = true;
    }
    //找宫卦
    std::set<LIUQIN_ID> fushengs;
    for(size_t i =0;i<5;i++)
    {
        if(!liuqins[(LIUQIN_ID)i])
        {
            //缺少的
            fushengs.insert((LIUQIN_ID)i);
        }
    }

    if(fushengs.empty())
        return;

    Wuxing & Wo = _chonggua.wuxing();
    Chonggua& purgua = Chonggua::from(_chonggua.gonggua(),_chonggua.gonggua());
    for(size_t i =0;i<6;i++)
    {
        
        TianganDizhi &z = purgua.yao(i)->get_ganzhi();
        Liuqin& lq = Liuqin::from(Wo,z.get_dizhi().get_wuxing());
        if(fushengs.find(lq.id()) != fushengs.end()) 
        {
            _fushen[i] = &lq;
        } 
        else
        {
            _fushen[i] = NULL;
        }
    }

}

Chonggua & LiuqinChonggua::gonggua()
{
    return _gonggua;
}
Chonggua & LiuqinChonggua::gong()
{
    return _gong;
}

Chonggua & LiuqinChonggua::chonggua()
{
    return _chonggua;
}

Liuqin * LiuqinChonggua::liuqin(int pos)
{
    return _liuqin[pos];
}

Liuqin * LiuqinChonggua::fushen(int pos)
{
    return _fushen[pos];
}
bool LiuqinChonggua::hasFushen()
{
    for(int i=0;i<6 ;i++)
    {
        if(_fushen[i])
        {
            return true;
        }
    }
    return false;
}


}
