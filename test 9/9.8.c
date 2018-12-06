#include <stdio.h> /*8.第6章的程序清单6.20中，power()函数返回一个double类型数的正整数
次幂。改进该函数，使其能正确计算负幂。另外，函数要处理0的任何次幂
都为0，任何数的0次幂都为1（函数应报告0的0次幂未定义，因此把该值处
理为1）。要使用一个循环，并在程序中测试该函数。*/

double power(double n, int p);
int main(void)
{
    double n=0;
    int p=0;

    printf("输入底数和指数:\n");
    while ((scanf("%lf%d",&n,&p)) == 2)
        printf("%.2lf的%d次幂是:%lf\n",n,p,power(n,p));

    return 0;
}

double power(double n, int p) // 函数定义
{
    double pow = 1;
    int i;

    if(p==0)
    {
        if(n==0)
        {
            pow=1;
            printf("It is not defined.\n");
        }
        else
            pow=1;
    }


    else if(p>0)
        for (i = 1; i <= p; i++)
            pow *= n;
    else
        {
            if(n!=0)
            {
            for (i = 1; i <= -p; i++)   // for (i = 0; i > p; i--)
                pow *= n;               //      pow /= n;             //简化写法
            pow=1/pow;
            }
            else
                pow=0;
        }

    return pow;         // 返回pow的值
}
