#include <stdio.h>/*编写并测试一个函数larger_of()，该函数把两个double类型变量的值
替换为较大的值。例如， larger_of(x, y)会把x和y中较大的值重新赋给两个变量。*/
double larger_of(double *,double *);
int main(void)
{
    double x=0,y=0;

    printf("输入2个数来比大小:\n");
    scanf("%lf%lf",&x,&y);
    larger_of(&x,&y);
    printf("2个数是%.2lf %.2lf.\n",x,y);
    return 0;
}
double larger_of(double *x,double *y)
{
    *x > *y ? (*y = *x) : (*x = *y);
}
