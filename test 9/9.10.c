#include <stdio.h>/*10.十进制转2-10进制*/
void to_base_n(unsigned long n,unsigned int base);
int main(void)
{
    unsigned long num;
    unsigned int base;

    printf("输入一个整数(q离开):\n");
    while (scanf("%lu%u", &num,&base) == 2)
    {
        printf("等于%u进制: ",base);
        to_base_n(num,base);
        putchar('\n');
        printf("输入一个整数(q离开):\n");
    }
    printf("完工.\n");

    return 0;
}

void to_base_n(unsigned long n,unsigned int base)
{
    int r;

    r = n % base;
    if (n >= base)
        to_base_n(n/base,base);
    printf("%d",r);
}


