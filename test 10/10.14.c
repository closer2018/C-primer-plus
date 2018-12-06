#include<stdio.h>/*14.以变长数组作为函数形参，完成编程练习13。*/
#define ROWS 3
#define COLS 5
#define NUM 15
void get_ar(int n,int m ,double ar[n][m]); //得到数组
double ave_num(double ar[]); //一维平均值
void sum(int n,int m ,double ar[n][m]);//所有平均值
double max(int n,int m ,double ar[n][m]); //找出最大值
void printf_all(int n,int m ,double ar[n][m]);//打印函数

int main(void)
{
    double array[ROWS][COLS];

    printf_all(ROWS,COLS,array);

    return 0;
}

void get_ar(int n,int m ,double ar[n][m]) //得到数组
{
    int i,j;

    printf("请输入第3组数,每组5个.\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
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

void sum(int n,int m ,double ar[n][m])//所有平均值
{
    int i,j;
    double tol;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            tol+=ar[i][j];

    printf("所有数据的平均值是:%g.\n",tol/NUM);
}

double max(int n,int m ,double ar[n][m]) //找出最大值
{
    double max=ar[0][0];
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(max<ar[i][j])
            max=ar[i][j];
    }

    printf("最大值是%g.\n",max);
}

void printf_all(int n,int m ,double ar[n][m])//打印函数
{
    int i;

    get_ar(n,m,ar);
    for(i=0;i<n;i++)
        printf("第%d组数平均值是:%g.\n",i+1,ave_num(ar[i]));
    sum(n,m,ar);
    max(n,m,ar);
    printf("\n");
    printf("再见.\n");
}
