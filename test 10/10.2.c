#include<stdio.h>/*2.编写一个程序，初始化一个double类型的数组，然后把该数组的内容
拷贝至3个其他数组中（在main()中声明这4个数组）。使用带数组表示法的
函数进行第1份拷贝。使用带指针表示法和指针递增的函数进行第2份拷贝。
把目标数组名、源数组名和待拷贝的元素个数作为前两个函数的参数。第3
个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指
针。也就是说，给定以下声明，则函数调用如下所示：
double　source[5]　=　{1.1,　2.2,　3.3,　4.4,　5.5};
double　target1[5];
double　target2[5];
double　target3[5];
copy_arr(target1,　source,　5);
copy_ptr(target2,　source,　5);
copy_ptrs(target3, source, source + 5);*/
#define SIZE 5
void copy_arr(double ar1[], double ar[],int n);
void copy_ptr(double *ar2 , double *ar, int n);
void copy_ptrs(double *ar3 , double *ar ,double *end);
void printf_array(double ar[] , int n);
int main(void)
{
    double source[SIZE]={1.1 , 2.2 , 3.3 , 4.4 , 5.5 };
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1,source,SIZE);
    copy_ptr(target2,source,SIZE);
    copy_ptrs(target3,source,source+SIZE);
    printf_array(target1 , SIZE);
    printf_array(target2 , SIZE);
    printf_array(target3 , SIZE);

    return 0;
}

void copy_arr(double ar1[], double ar[],int n)
{
    int i;

    for(i=0;i<n;i++)
        ar1[i]=ar[i];
}

void copy_ptr(double *ar2 , double *ar, int n)
{
    int i=0;

    for(i=0;i<n;i++)
        *ar2++=*ar++;


}

void copy_ptrs(double *ar3 , double *ar ,double *end)
{
    int i=0;

    for(i=0;ar<end;i++)
        *ar3++=*ar++;
}

void printf_array(double ar[] , int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%g ",ar[i]);
    printf("\n");
}
