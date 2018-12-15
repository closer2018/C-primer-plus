/*11.编写一个名为transform()的函数，接受4个参数：内含double类型数据
的源数组名、内含double类型数据的目标数组名、一个表示数组元素个数的
int类型参数、函数名（或等价的函数指针）。transform()函数应把指定函数
应用于源数组中的每个元素，并把返回值储存在目标数组中。例如：
transform(source, target, 100, sin);
该声明会把target[0]设置为sin(source[0])，等等，共有100个元素。在一
个程序中调用transform()4次，以测试该函数。分别使用math.h函数库中的两
个函数以及自定义的两个函数作为参数。*/

#include <stdio.h>
#include <math.h>
#define PSIZE 4
#define SIZE 100

void transform(double source[],double target[],int size,double(*pf)(double num));
double oppsite_val(double);//源数组取负值
double double_val(double);//源数组双倍

int main(void)
{
    int i, j;
    double source[SIZE],target[SIZE];
    double(*p[PSIZE])(double)={sin,sqrt,oppsite_val,double_val};

    printf("源数组:\n");
    for (i=0;i<SIZE;i++)
    {
        source[i]=i;
        printf("%7g ",source[i]);
        if (i%10==9)
            printf("\n");
    }
    printf("\n");
    for (i=0;i<PSIZE;i++)
    {
        printf("源数组%d:\n",i+1);
        //target[0]设置为sin(source[0])
        transform(source,target,SIZE,p[i]);//p[0]是sin，p[1]是开根
        for (j=0;j<SIZE;j++)
        {
            printf("%7.2f ",target[j]);
            if(j%10==9)
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

void transform(double source[],double target[],int size,double(*pf)(double num))
{
    for(int i=0;i<size;i++)
        target[i]=(*pf)(source[i]);
}

double oppsite_val(double num)
{
    return (-1*num);
}

double double_val(double num)
{
    return (2*num);
}
