#include <stdio.h>//设计一个函数min(x, y)，返回两个double类型值的较小值。
double min(double,double);
int main()
{
    double a=0,b=0;

    printf("输入两个大小不一样的数:");
    scanf("%lf %lf",&a,&b);
    printf("小的数是%lf.\n",min(a,b));

    return 0;
}

double min(double a,double b)
{
    return (a<b ? a:b);
}
