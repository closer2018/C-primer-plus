#include<stdio.h>/*13.编写一个程序，提示用户输入3组数，每组数包含5个double类型的数
（假设用户都正确地响应，不会输入非数值数据）。该程序应完成下列任务。
a.把用户输入的数据储存在3×5的数组中
b.计算每组（5个）数据的平均值
c.计算所有数据的平均值
d.找出这15个数据中的最大值
e.打印结果
每个任务都要用单独的函数来完成（使用传统C处理数组的方式）。完
成任务b，要编写一个计算并返回一维数组平均值的函数，利用循环调用该
函数3次。对于处理其他任务的函数，应该把整个数组作为参数，完成任务c
和d的函数应把结果返回主调函数。*/
#define ROWS 3
#define COLS 5
#define NUM 15
void get_ar(double ar[][COLS], int n); //得到数组
double ave_num(double ar[]); //一维平均值
void sum(double ar[][COLS], int n);//所有平均值
double max(double ar[][COLS], int n); //找出最大值
void printf_all(double ar[][COLS], int n);//打印函数

int main(void)
{
    double array[ROWS][COLS];

    printf_all(array,ROWS);

    return 0;
}

void get_ar(double ar[][COLS], int n) //得到数组
{
    int i,j;

    printf("请输入第3组数,每组5个.\n");
    for(i=0;i<n;i++)
        for(j=0;j<COLS;j++)
        scanf("%lf",&ar[i][j]);

}

double ave_num(double ar[]) //一维数组平均值
{
    int i;
    double tol;

    for(i=0,tol=0;i<COLS;i++)
        tol+=ar[i];

    return tol/COLS;
}

void sum(double ar[][COLS], int n)//所有平均值
{
    int i,j;
    double tol;

    for(i=0;i<n;i++)
        for(j=0;j<COLS;j++)
            tol+=ar[i][j];

    printf("所有数据的平均值是:%g.\n",tol/NUM);
}

double max(double ar[][COLS], int n) //找出最大值
{
    double max=ar[0][0];
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<COLS;j++)
            if(max<ar[i][j])
            max=ar[i][j];
    }

    printf("最大值是%g.\n",max);
}

void printf_all(double ar[][COLS], int n)//打印函数
{
    int i;

    get_ar(ar,ROWS);
    for(i=0;i<ROWS;i++)
        printf("第%d组数平均值是:%g.\n",i+1,ave_num(ar[i]));
    sum(ar,ROWS);
    max(ar,ROWS);
    printf("\n");
    printf("再见.\n");
}
