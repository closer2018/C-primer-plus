#include <stdio.h>/*8.使用编程练习2中的拷贝函数，把一个内含7个元素的数组中第3～第5
个元素拷贝至内含3个元素的数组中。该函数本身不需要修改，只需要选择
合适的实际参数（实际参数不需要是数组名和数组大小，只需要是数组元素
的地址和待处理元素的个数）。*/
#define SIZE 7
void copy_ar(double ar1[],double ar[],int n);//拷贝一维数组函数
void printf_array(double ar[] , int n); //打印一维数组函数

int main(void)
{
    double source[SIZE]={1.1 , 2.2 , 3.3 , 4.4 , 5.5 ,6.6 , 7.7 };
    double target[3];

    copy_ar(target,source+2,3);
    printf_array(target,3);

    return 0;
}

void copy_ar(double ar1[],double ar[],int n)//一次拷贝一组一维数组
{
    int i;

    for(i=0;i<n;i++)
        ar1[i]=ar[i];
}

void printf_array(double ar[] , int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%g ",ar[i]);
    printf("\n");
}
