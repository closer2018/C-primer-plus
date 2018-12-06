#include<stdio.h> //输入整数,打印比该数大10的数

int main(void)
{
    long a,b=0;
    printf("请输入一个整数:");
    scanf("%ld",&a);
    while(b++<11)
    {
        printf("%ld ",a++);
    }
    system("pause");
    return 0;
}
