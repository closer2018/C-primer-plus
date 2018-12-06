#include <stdio.h> /*两数的调和平均数这样计算：先得到两数的倒数，然后计算
两个倒数的平均值，最后取计算结果的倒数。编写一个函数，接受两个double类型
的参数，返回这两个参数的调和平均数。*/
double HA (double,double);
int main(void)
{
    double m=0,n=0;
    printf("输入两个数:");
    scanf("%lf%lf",&m,&n);
    printf("他们的调和平均数是:%.4lf.\n",HA(m,n));
    return 0;
}

double HA (double m,double n)
{

    return (1/((1/m+1/n)/2));
}
