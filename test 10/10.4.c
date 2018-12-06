#include<stdio.h>/*4.编写一个函数，返回储存在double类型数组中最大值的下标，并在一
个简单的程序中测试该函数。*/
double return_max(double *ar , int n);

int main(void)
{
    double array[]={1.5, 3.75, 4.3, 2.6, 2.15, 6.66};
    printf("%g",return_max(array,6));
    printf("\n");

    return 0;
}

double return_max(double ar[] , int n)
{
    int i,max=0;

    for(i=0;i<n;i++)
    {
        if(ar[max]<ar[i])
        max=i;
    }

    return max;
}
