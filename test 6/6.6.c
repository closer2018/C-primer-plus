#include<stdio.h> //打印上限到下限之间的整数,该数平方,该数立方
int main(void)
{
    long a,b,c,d,e;
    printf("请输入一个整数上限:");
    scanf("%ld",&a);
    printf("请再输入一个整数下限:");
    scanf("%ld",&b);
    printf("%20s%20s%20s%20s\n","编号","数字","平方","立方");
    for(c=1;c<=b-a+1;c++)
    {
        d=(a+c-1)*(a+c-1);
        e=(a+c-1)*(a+c-1)*(a+c-1);
        printf("%20d%20ld%20ld%20ld\n",c,a+c-1,d,e);
    }

    return 0;
}
