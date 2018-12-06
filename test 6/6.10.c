#include<stdio.h> //输入上下限整数,计算两数间所有数的平方和
int main(void)
{
    long a,b,i,j,k;
    printf("请输入两个整数(先小后大):");
    while(scanf("%ld%ld",&a,&b)==2,a<b)
    {
        for(i=0,k=0;i<=b-a;i++)
        {
            j=(a+i)*(a+i);
            k+=j;
        }
    printf("%ld 到%ld 的平方和是%ld\n",a*a,b*b,k);
    printf("输入下一组数:");
    }
    system("pause");
    return 0;
}

