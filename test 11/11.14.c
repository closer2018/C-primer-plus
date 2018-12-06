/*14.编写一个通过命令行运行的程序计算幂。第1个命令行参数是double
类型的数，作为幂的底数，第2个参数是整数，作为幂的指数。*/
#include <stdio.h>
#include <stdlib.h>
double mypower(double n, int exp);
int main(int argc, char * argv[])
{
    printf("The result is: %g",
            mypower(atof(argv[1]), atoi(argv[2])));
}

double mypower(double n, int exp)
{
    double pow=1.0;

    if(exp>0)
        for(pow=1.0;exp>=1;exp--)
            pow*=n;
    else if(exp<0)
    {
        if(!n)//即n=0的时候，0的负数幂没有意义
            puts("没有意义!");
        for(pow=1.0;exp<0;exp++)
            pow*=(1/n);

    }
    else if(n)//等同于else if(n&&exp=0)
        //非0的0次方都是1
        pow=1;
    else
    {
        pow=1/n;
        puts("没有意义!");
    }
    return pow;
}
