#include <stdio.h>/*9.编写一个程序，初始化一个double类型的3×5二维数组，使用一个处理
变长数组的函数将其拷贝至另一个二维数组中。还要编写一个以变长数组为
形参的函数以显示两个数组的内容。这两个函数应该能处理任意N×M数组
（如果编译器不支持变长数组，就使用传统C函数处理N×5的数组）。*/
#define M 5
#define N 3
void copy_ar(double ar1[][M],double ar[][M],int n);//拷贝一维数组函数
void printf_array(int n, int m ,double ar[n][m]); //打印一维数组函数

int main(void)
{
    double array[N][M]={ {1.1 , 2.1 , 3.1 , 4.1 , 5.1},
                         {1.2 , 2.2 , 3.2 , 4.2 , 5.2} ,
                         {1.3 , 2.3 , 3.3 , 4.3 , 5.3} };
    double array1[N][M];

    copy_ar(array1 , array , M);
    printf_array(N,M,array1);
    return 0;
}

void copy_ar(double ar1[][M],double ar[][M],int n)//一次拷贝一组一维数组
{
    int i,j;

    for(i=0;i<n;i++)
        for(j=0;j<M;j++)
            ar1[i][j]=ar[i][j];
}

void printf_array(int n, int m ,double ar[n][m])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%g\t ",ar[i][j]);
        printf("\n");
    }

}
