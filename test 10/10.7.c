#include<stdio.h>/*7.编写一个程序，初始化一个double类型的二维数组，使用编程练习2中
的一个拷贝函数把该数组中的数据拷贝至另一个二维数组中（因为二维数组
是数组的数组，所以可以使用处理一维数组的拷贝函数来处理数组中的每个
子数组）。*/
#define ROWS 3
#define COLS 2
void copy_ar(double ar1[],double ar[],int n);//拷贝一维数组函数
void printf_ar(double ar[][COLS],int rows); //打印二维数组函数

int main(void)
{
    int rows;
    double array[ROWS][COLS]={  {1.2,2.3},
                                {4.6,5.2},
                                {7.8,8.6}};
    double target[ROWS][COLS];

    for(rows=0;rows<ROWS;rows++)
        copy_ar(target[rows],array[rows],COLS);//每次拷贝一组一维,总共有几组一维就拷贝几次,就等于是拷贝3次,每次里面有2个double数.
    printf_ar(target,ROWS);

    return 0;
}

void copy_ar(double ar1[],double ar[],int n)//一次拷贝一组一维数组
{
    int i;

    for(i=0;i<n;i++)
        ar1[i]=ar[i];
}

void printf_ar(double ar[][COLS],int rows)
{
    int i,j;

    for(i=0;i<rows;i++)
    {
     for(j=0;j<COLS;j++)
        printf("%g ",ar[i][j]);
        printf("\n");
    }
}
