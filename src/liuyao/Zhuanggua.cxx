#include "Zhuanggua.hxx"
#include "LiuqinChonggua.hxx"
#include "../base/Error.hxx"

namespace Zhouyi{
    
ZhuangguaJieguo * Zhuanggua::zhuanggua(YAO_ID yaos[6],Lunar * lunar)
{
    bool b = false;
    YAO_ID bengYaos[6],bianYaos[6];
    for(int i=0;i<6;i++)
    {
        if(yaos[i] & 2)
        {
            b = true;
            if(yaos[i] == YID_LAO_YING)
            {
                bianYaos[i] =YID_YANG;
            }
            else if(yaos[i] == YID_LAO_YANG)
            {
                bianYaos[i] =YID_YING;
            }
            else
            {
                throw Error(ERROR_INVALID_ID);
            }
        }
        else
        {
            bianYaos[i] = yaos[i];
        }
        
        bengYaos[i] = YAO_ID(yaos[i] & 1);
    }    
    Gua & xg = Gua::from(bengYaos[0],bengYaos[1],bengYaos[2]);
    Gua & sg = Gua::from(bengYaos[3],bengYaos[4],bengYaos[5]);
    Chonggua & ben = Chonggua::from(sg,xg);
    LiuqinChonggua * beng= new LiuqinChonggua(ben);

    LiuqinChonggua * bian = NULL;
    //Bian
    if(b)
    {
        Gua & bxg = Gua::from(bianYaos[0],bianYaos[1],bianYaos[2]);
        Gua & bsg = Gua::from(bianYaos[3],bianYaos[4],bianYaos[5]);
        Chonggua & biangua = Chonggua::from(bsg,bxg);
        Chonggua & gonggua = Chonggua::from(ben.gonggua(),ben.gonggua());
        bian= new LiuqinChonggua(biangua,gonggua);
    }



    return ZhuangguaJieguo::from(beng,bian,lunar);
}

ZhuangguaJieguo * Zhuanggua::zhuanggua(YAO_ID yaos[6])
{
    Lunar * now = Lunar::now();

    ZhuangguaJieguo * jieguo = zhuanggua(yaos,now);
    delete now;
    return jieguo;
}
ZhuangguaJieguo * Zhuanggua::zhuanggua(BAGUA_ID beng[2],BAGUA_ID bian[2],Lunar * lunar)
{
    Gua & xg = Gua::from(beng[0]);
    Gua & sg = Gua::from(beng[1]);
    Chonggua & ben = Chonggua::from(sg,xg);
    LiuqinChonggua * beng1= new LiuqinChonggua(ben);
    LiuqinChonggua * bian1 = NULL;
    if(bian[0] != BGID_INVALID || bian[1] !=BGID_INVALID)
    {
        Gua & bxg = Gua::from(bian[0]);
        Gua & bsg = Gua::from(bian[1]);
        Chonggua & biangua = Chonggua::from(bsg,bxg);
        Chonggua & gonggua = Chonggua::from(ben.gonggua(),ben.gonggua());
        bian1= new LiuqinChonggua(biangua,gonggua);
    }
    return ZhuangguaJieguo::from(beng1,bian1,lunar);
}
ZhuangguaJieguo * Zhuanggua::zhuanggua(BAGUA_ID beng[2],BAGUA_ID bian[2])
{
    Lunar * now = Lunar::now();

    ZhuangguaJieguo * jieguo = zhuanggua(beng,bian,now);
    delete now;
    return jieguo;
}


}