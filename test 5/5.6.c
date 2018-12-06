#include<stdio.h> //计算前n个整数的平方

int main(void)
{
    long numble=0,a=0,b=0;
    printf("输入一个整数:");
    scanf("%d",&numble);
    while (a++<numble)
    {
        b=a*a;
        printf("%d的平方是%d.\n",a,b);

    }
    system("pause");
    return 0;
}
