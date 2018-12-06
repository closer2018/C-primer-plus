#include <stdio.h> //编写一个程序，读取整数直到用户输入 0。
//输入结束后，程序应报告用户输入的偶数（不包括 0）个数、
//这些偶数的平均值、输入的奇数个数及其奇数的平均值。
int main(void)
{
    long even_num=0,odd_num=0; //偶数和奇数个数
    long num;
    long even_sum=0,odd_sum=0; //偶数和奇数和
    printf("请输入一个整数(按0退出):");
    for(scanf("%ld",&num);num!=0;)
    {
        if(num%2==0)
        {
            even_num++;
            even_sum+=num; //计算偶数和
        }
        else
        {
            odd_num++;
            odd_sum+=num; //计算奇数和
        }
    printf("继续输入一个整数(0退出):");
    scanf("%ld",&num);
    }
    printf("\n");
    printf("偶数的个数为%ld,它们的平均数是:%.3f\n",even_num,(even_num==0)?0:((float)even_sum/even_num));
    printf("奇数的个数为%ld,它们的平均数是:%.3f\n",odd_num,(odd_num==0)?0:((float)odd_sum/odd_num));
    return 0;
}
