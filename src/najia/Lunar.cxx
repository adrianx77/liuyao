#include <stdlib.h>
#include <stdio.h>
#include "Lunar.hxx"

namespace Zhouyi{

// 1900 ~ 2100 農曆年大小閏月資料
int lunarInfo[] = {
    0x04bd8,0x04ae0,0x0a570,0x054d5,0x0d260,0x0d950,0x16554,0x056a0,0x09ad0,0x055d2,    //1900 ~ 1909
    0x04ae0,0x0a5b6,0x0a4d0,0x0d250,0x1d255,0x0b540,0x0d6a0,0x0ada2,0x095b0,0x14977,    //1910
    0x04970,0x0a4b0,0x0b4b5,0x06a50,0x06d40,0x1ab54,0x02b60,0x09570,0x052f2,0x04970,    //1920
    0x06566,0x0d4a0,0x0ea50,0x06e95,0x05ad0,0x02b60,0x186e3,0x092e0,0x1c8d7,0x0c950,    //1930
    0x0d4a0,0x1d8a6,0x0b550,0x056a0,0x1a5b4,0x025d0,0x092d0,0x0d2b2,0x0a950,0x0b557,    //1940
    
    0x06ca0,0x0b550,0x15355,0x04da0,0x0a5b0,0x14573,0x052b0,0x0a9a8,0x0e950,0x06aa0,    //1950
    0x0aea6,0x0ab50,0x04b60,0x0aae4,0x0a570,0x05260,0x0f263,0x0d950,0x05b57,0x056a0,    //1960
    0x096d0,0x04dd5,0x04ad0,0x0a4d0,0x0d4d4,0x0d250,0x0d558,0x0b540,0x0b6a0,0x195a6,    //1970
    0x095b0,0x049b0,0x0a974,0x0a4b0,0x0b27a,0x06a50,0x06d40,0x0af46,0x0ab60,0x09570,    //1980
    0x04af5,0x04970,0x064b0,0x074a3,0x0ea50,0x06b58,0x055c0,0x0ab60,0x096d5,0x092e0,    //1990
    
    0x0c960,0x0d954,0x0d4a0,0x0da50,0x07552,0x056a0,0x0abb7,0x025d0,0x092d0,0x0cab5,    //2000
    0x0a950,0x0b4a0,0x0baa4,0x0ad50,0x055d9,0x04ba0,0x0a5b0,0x15176,0x052b0,0x0a930,    //2010
    0x07954,0x06aa0,0x0ad50,0x05b52,0x04b60,0x0a6e6,0x0a4e0,0x0d260,0x0ea65,0x0d530,    //2020
    0x05aa0,0x076a3,0x096d0,0x04bd7,0x04ad0,0x0a4d0,0x1d0b6,0x0d250,0x0d520,0x0dd45,    //2030
    0x0b5a0,0x056d0,0x055b2,0x049b0,0x0a577,0x0a4b0,0x0aa50,0x1b255,0x06d20,0x0ada0,    //2040
    
    0x04b63,0x0937f,0x049f8,0x04970,0x064b0,0x068a6,0x0ea5f,0x06b20,0x0a6c4,0x0aaef,    //2050
    0x092e0,0x0d2e3,0x0c960,0x0d557,0x0d4a0,0x0da50,0x05d55,0x056a0,0x0a6d0,0x055d4,    //2060
    0x052d0,0x0a9b8,0x0a950,0x0b4a0,0x0b6a6,0x0ad50,0x055a0,0x0aba4,0x0a5b0,0x052b0,    //2070
    0x0b273,0x06930,0x07337,0x06aa0,0x0ad50,0x04b55,0x04b6f,0x0a570,0x054e4,0x0d260,    //2080
    0x0e968,0x0d520,0x0daa0,0x06aa6,0x056df,0x04ae0,0x0a9d4,0x0a4d0,0x0d150,0x0f252,    //2090
    0x0d520};                                                                          //2100

const char* jieqiInfo[] = 
{
    "立春", "雨水", "惊蛰", "春分", "清明", "谷雨",
    "立夏", "小满", "芒种", "夏至", "小暑", "大暑",
    "立秋", "处暑", "白露", "秋分", "寒露", "霜降",
    "立冬", "小雪", "大雪", "冬至", "小寒", "大寒"
};

//  推算节气, 默认返回立春  OUT:阳历
//  以1899年12月31日(星期日)为基准日, 之后每一天与之差值为积日
//  F = 365.242 * (y – 1900) + 6.2 + 15.22 *x - 1.9 * sin(0.262 * x)  误差 0.05天左右
//  计算第x个节气公式 x = [1,2,3,4,5,...........24]
//                    [小寒,大寒,立春..... ]
def getJieqi(year,x=3)
{     // 基准日
    if (x<1 || x>4)
//     if x not in range(1,25):
         return None
     try:
         year  = int(year)
         x = int(x)
     except:
         return None
     if year < 1900:
         return None
     x -= 1
     startDT = datetime.datetime(1899,12,31)
     # 相差的天数
     days = 365.242*(year - 1900) + 6.2 + 15.22*x - 1.9*math.sin(0.262*x)
     delta = datetime.timedelta(days=days)
     return startDT+delta
}

TianganDizhi * DateTime::year()
{

}
TianganDizhi * DateTime::month()
{

}

TianganDizhi * DateTime::day()
{

}
TianganDizhi * DateTime::shi()
{

}


}