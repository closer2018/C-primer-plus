/*6.编写一个程序，生成1000个1～10范围内的随机数。不用保存或打印
这些数字，仅打印每个数出现的次数。用 10 个不同的种子值运行，生成的
数字出现的次数是否相同？可以使用本章自定义的函数或ANSI C的rand()和
srand()函数，它们的格式相同。这是一个测试特定随机数生成器随机性的方
法。*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define SIZE_N 10

int main(void)
{
    int i,j;
    int ar[SIZE_N];//各随机数出现次数的数组
    int seed[SIZE_N]={1,2,3, 4, 5, 6, 7, 8, 9, 10};

    for(i=0;i<SIZE_N;i++)
    {
        for(j=0;j<SIZE_N;j++)
            ar[j]=0;
        srand(seed[i]);
        printf("种子是%d\n",seed[i]);
        for(j=0;j<SIZE;j++)
            ar[rand()%10]++;

        for(j=0;j<SIZE_N;j++)
        {
            printf("%d:%-5d",j+1,ar[j]);
            if(j==4)
                puts("");
        }
        puts("");
    }
    return 0;
}
