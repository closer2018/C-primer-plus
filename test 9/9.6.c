#include <stdio.h> /*6.编写并测试一个函数，该函数以3个double变量的地址作为参数，把最
小值放入第1个函数，中间值放入第2个变量，最大值放入第3个变量。*/
void TEST(double *,double *,double *);
int main(void)
{
    double num1,num2,num3;

    printf("enter 3 numbers:\n");
    scanf("%lf%lf%lf",&num1,&num2,&num3);
    printf("Originally\nnum1 = %.2f, num2 = %.2f, num3 = %.2f\n",
            num1, num2, num3);
    TEST(&num1,&num2,&num3);
    printf("Now\nnum1 = %.2f, num2 = %.2f, num3 = %.2f\n",
            num1, num2, num3);

    return 0;
}

void TEST(double *x,double *y,double *z)
{
    double t;

    if (*y<*x )
    {
        t=*x;
        *x=*y;
        *y=t;
    }
    if (*z<*x)
    {
        t=*x;
        *x=*z;
        *z=t;
    }
    if (*z<*y)
    {
        t=*y;
        *y=*z;
        *z=t;
    }
}
