#include <stdio.h>/*10.编写一个函数，把两个数组中相对应的元素相加，然后把结果储存
到第 3 个数组中。也就是说，如果数组1中包含的值是2、4、5、8，数组2中
包含的值是1、0、4、6，那么该函数把3、4、9、14赋给第3个数组。函数接
受3个数组名和一个数组大小。在一个简单的程序中测试该函数。*/
#define SIZE 5
void sum_ar(double ar1[], double ar2[], double ar3[] , int n);		//加数组的函数
void print_ar(double ar[], int rows);						//打印数组的函数
int main(void)
{
    double array1[SIZE] ={1.2, 2.3, 2.6, 3.5, 3.2};
    double array2[SIZE] ={7.8, 8.6, 7.2, 3.9, 6.6};
    double sum[SIZE];

    printf("The original array1:\n");
    print_ar(array1, SIZE);
    printf("The original array2:\n");
    print_ar(array2, SIZE);
    sum_ar(array1,array2,sum,SIZE);
    printf("The sum array:\n");
    print_ar(sum, SIZE);

    return 0;
}

void sum_ar(double ar1[], double ar2[], double ar3[] , int n)
{
    int r;
    for (r = 0; r < n; r++)
        ar3[r] = ar1[r] + ar2[r];
}

void print_ar(double ar[], int rows)
{
    int r;
    for (r = 0; r < rows; r++)
            printf("%g\t ", ar[r]);
        printf("\n");

}
