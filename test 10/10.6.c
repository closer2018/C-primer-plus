#include<stdio.h>/*6.编写一个函数，把double类型数组中的数据倒序排列，并在一个简单
的程序中测试该函数。*/
double sort(double *ar, int n);//倒序函数

int main(void)
{
    int n=0;

    double array[]={1.5, 3.75, 4.3, 2.6, 2.15, 6.66};
    for(n=0;n<6;n++)
        printf("%g\t",array[n]);
    printf("\n");
    sort(array,6);
    printf("\n");

    return 0;
}

double sort(double *ar, int n)
{
    int i;

    for(i=n-1;i>=0;i--)
        printf("%g\t",ar[i]);

}
