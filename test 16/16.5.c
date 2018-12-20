/*5.编写一个函数接受这些参数：内含int类型元素的数组名、数组的大小
和一个代表选取次数的值。该函数从数组中随机选择指定数量的元素，并打
印它们。每个元素只能选择一次（模拟抽奖数字或挑选陪审团成员）。另
外，如果你的实现有time()（第12章讨论过）或类似的函数，可在srand()中
使用这个函数的输出来初始化随机数生成器rand()。编写一个简单的程序测
试该函数。*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 10//数组最大数字数量

void print_rand(const int ar[],int len,int n);
int main()
{
    int n;//想要的制定数量的元素
    int ar[SIZE]={1,2,3,4,5,6,7,8,9,10};

    srand(time(0));//以系统时间为种子
    printf("原始数组是:\n");
    for(int i=0;i<SIZE;i++)
        printf("%-2d ",ar[i]);
    puts("\n你想要从数组中随机取几个数字？");
    while( scanf("%d",&n) == 1 )
    {
        print_rand(ar,SIZE,n);
        puts("\n再次输入你想要从数组中随机取出几个数字(q离开)？");
    }
    puts("再见.");

    return 0;
}

void print_rand(const int ar[],int len,int n)
{
    int i,j;
    int arcopy[len];
    int temp;//临时存放

    //创建一个数组副本，避免修改原始数组
    memcpy(arcopy,ar,len*sizeof(int));
    if(n>len||n<1)
        printf("你输入的数字范围不对(请输入1-%d)",len);
    else
    {
        printf("取出的%d个随机数如下：\n",n);
        for(i=0;i<n;i++)
        {
            j=(int)rand()%(len-i);//j是0到(10-i)之间的下标
            {   //每次随机到的下标对应的元素和数组最后一个元素交换
                //最后一个元素每次循环递减1，以保证不重复
                temp=arcopy[j];
                arcopy[j]=arcopy[len-i-1];
                arcopy[len-i-1]=temp;
            }
            printf("%-3d ",arcopy[len-i-1]);//打印数组
        }
    }

    printf("\n");
}
