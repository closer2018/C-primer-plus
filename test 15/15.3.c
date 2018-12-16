/*3.编写一个函数，接受一个 int 类型的参数，并返回该参数中打开位的
数量。在一个程序中测试该函数*/
#include <stdio.h>
#include <limits.h>

int count_bit(int n);

int main(void)
{
    int n;

    puts("输入一个整数：");
    while( (scanf("%d",&n)) != 1)
    {
        printf("请输入一个整数.");
        while(getchar() != '\n') continue;
    }
    while(getchar() != '\n') continue;
    printf("%d打开位的数量是%d.\n",n,count_bit(n));

    return 0;
}

int count_bit(int n)
{
    int i=0;
    while(n)
    {
        if(n&01)//n&01是求n最后一位的值
            i++;
        n>>=1;//等同于n/=2
    }

    return i;
}
