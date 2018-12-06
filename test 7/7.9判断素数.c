#include <stdio.h>  //编写一个程序,只接受正整数输入,然后显示所有小于或等于该数的素数.
int main(void)
{
    long num=0;
    long a,b;//a用于外层,b用于内层
    int flag; //标记素数


    printf("请输入一个正整数(q离开):\n");
    while(scanf("%ld",&num)==1)
    {
    if(num>0)   //大于0的正整数
        {
            printf("%ld的素数有:\n",num);
            for(a=2;a<=num;a++) //a到num的数进行遍历
            {
                flag = 1;   //素数标记为1
                for(b=2;b*b<=a;b++)  //判断遍历的各个数是否是素数
                {
                    if(a%b==0)  //能被整除就不是素数
                        flag=0; //不是素数标记为0
                }
                if(flag==1)   //判断是否是素数
                    printf("%ld ",a);
            }
            printf("\n");
        }
    else //小于等于零不算
        printf("请输入正整数.\n");
    printf("请在输入一个数(q离开):");
    }

    return 0;
}
