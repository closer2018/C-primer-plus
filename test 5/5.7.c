#include<stdio.h> //一个数的立方
void cube (double n);
int main(void)
{
    double numble=0.0;
    printf("输入一个数:");
    scanf("%lf",&numble);
    cube(numble);
    system("pause");
    return 0;
}

void cube(double n)
{
    printf("%f的立方是:%f.\n",n,n*n*n);
}
