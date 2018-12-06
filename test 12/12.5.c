/*5.编写一个程序，生成100个1～10范围内的随机数，并以降序排列（可
以把第11章的排序算法稍加改动，便可用于整数排序，这里仅对整数排
序）。*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void print_ar(int *ar,int n);//打印函数
int main(void)
{
    int ar[100]={0};
    int i;

    srand((unsigned int)time(0));
    for(i=0;i<SIZE;i++)
        ar[i]=(int)rand()%10 + 1;//随机数存入数组

    puts("old:");
    for(i=0;i<SIZE;i++)
    {//打印初始100个随机数
        printf("%-4d",ar[i]);
        if(i%10==9)
            puts("");
    }

    puts("new:");
    print_ar(ar,SIZE);//打印排序好的数

    return 0;
}

void print_ar(int *ar,int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(ar[i]<ar[j])
            {
                temp=ar[j];
                ar[j]=ar[i];
                ar[i]=temp;
            }
    for(i=0;i<n;i++)
    {
        printf("%-4d",ar[i]);
        if(i%10==9)
            puts("");
    }
}
