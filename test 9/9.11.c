#include <stdio.h>/*Fibonacci()函数，该函数用循环代替递归计算斐波那契数。*/
unsigned long Fibonacci(unsigned long n);
int main(void)
{
    unsigned long n,i;

    printf("输入一个正整数n:");
;
    while((scanf("%lu",&n)) == 1)
    {
        for(i=1;i<=n;i++)
            printf("%lu,",Fibonacci(i));
        printf("\n接着输入:");
    }

    return 0;
}

unsigned long Fibonacci(unsigned long n) //Fibonacci()函数,n超过40多就开始溢出了
{
    unsigned long a=1,b=1,i;

    for(i=2;i<=n;i++)   //i=3;i<=n;i++
    {
        b=a-b;             //a=a+b;
        a+=b;             //b=a-b;
    }
    return a;
}
