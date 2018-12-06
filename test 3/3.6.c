#include<stdio.h>
int main(void)
{
    float water=0.0,n=0.0;
    double m;
    printf("请输入水的夸脱数:\n");
    scanf("%f",&water);
    n=water*950;
    m=n/3.0e-23;
    printf("那么重量为%.2f克的水中水分子数量是:%le\n"
           ,n,m);
    system("pause");
    return 0;
}
