#include <stdio.h>/*11.编写一个程序，声明一个int类型的3×5二维数组，并用合适的值初始
化它。该程序打印数组中的值，然后各值翻倍（即是原值的2倍），并显示
出各元素的新值。编写一个函数显示数组的内容，再编写一个函数把各元素
的值翻倍。这两个函数都以函数名和行数作为参数。*/
#define M 5
#define N 3
void double_ar(double ar[][M] , int n);		//翻倍数组的函数
void printf_ar(int n, int m ,double ar[n][m]);					//打印数组的函数
int main(void)
{
    double array[N][M]={ {1.1 , 2.1 , 3.1 , 4.1 , 5.1},
                         {1.2 , 2.2 , 3.2 , 4.2 , 5.2} ,
                         {1.3 , 2.3 , 3.3 , 4.3 , 5.3} };

    printf("The original array:\n");
    printf_ar(N,M, array);

    double_ar(array,N);
    printf("The present array:\n");
    printf_ar(N,M, array);

    return 0;
}

void double_ar(double ar[][M] , int n)
{
    int i,j;

    for(i=0;i<n;i++)
        for(j=0;j<M;j++)
            ar[i][j]*=2;
}

void printf_ar(int n, int m ,double ar[n][m])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%g\t ",ar[i][j]);
        printf("\n");
    }
}
