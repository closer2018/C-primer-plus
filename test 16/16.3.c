/*3.极坐标用向量的模（即向量的长度）和向量相对x轴逆时针旋转的角
度来描述该向量。直角坐标用向量的x轴和y轴的坐标来描述该向量（见图
16.3）。编写一个程序，读取向量的模和角度（单位：度），然后显示x轴
和y轴的坐标。相关方程如下：
x = r*cos A y = r*sin A
需要一个函数来完成转换，该函数接受一个包含极坐标的结构，并返回
一个包含直角坐标的结构（或返回指向该结构的指针）。*/

#include "16.3.h"
int main()
{
    polar pv;//极坐标结构
    rect rv;//直角坐标结构

    puts("请输入极坐标的大小和角度(q离开):");
    while( (scanf("%lf%lf",&pv.magnitude,&pv.angle) == 2))
    {
        rv=polar_to_rect(pv);
        printf("对应的直角坐标是x=%.3lf,y=%.3lf\n\n",rv.x, rv.y);
        puts("请输入极坐标的大小和角度(q离开):");
    }
    puts("再见.");

    return 0;
}

rect polar_to_rect(polar pv)//极坐标转换为直角坐标
{
    rect rv;

    rv.x=pv.magnitude*cos(pv.angle*DEG_TO_RED);
    rv.y=pv.magnitude*sin(pv.angle*DEG_TO_RED);

    return rv;
}
