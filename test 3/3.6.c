/*6.1个水分子的质量约为3.0×10 -23 克。1夸脱水大约是950克。编写一个
程序，提示用户输入水的夸脱数，并显示水分子的数量。*/
#include<stdio.h>
int main(void)
{
    float water=0.0,n=0.0;
    double m;
    printf("请输入水的夸脱数:\n");
    scanf("%f",&water);
    n=water*950;
    m=n/3.0e-23;
    printf("那么重量为%.2f克的水中水分子数量是:%le\n",n,m);

    return 0;
}
