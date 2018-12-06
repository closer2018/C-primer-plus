#include<stdio.h> //计算2个浮点数之差除以两数乘积结果
double dif(double m,double n);//定义函数dif
int main(void)
{
    double m,n,z;
    printf("请输入两个浮点数:");
    while(scanf("%lf%lf",&m,&n)==2)
    {
        printf("%lf\n",dif(m,n));
        printf("继续输入两个浮点数:");
    }
    printf("你输入的不是浮点数.\n");
    system("pause");
    return 0;
}
double dif(double m,double n) //函数内容是求差除乘积
{
    double z;
    z=(m-n)/(m*n);
    return z;
}
