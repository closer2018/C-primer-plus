#include <stdio.h> //输入8个数,并计算8个数的和
int main(void)
{
    double x[8],y[8];
    int a;
    printf("请输入8个数:");
    for(a=0;a<=7;a++)
    {
        y[0]=x[0];
        scanf("%lf",&x[a]);
        y[a]=y[a-1]+x[a];
    }
    printf("数字是:");
    for(a=0;a<=7;a++)
    {
        printf("%15.3lf",x[a]);
    }
    printf("\n");
    printf("数字和:");
    for(a=1;a<=8;a++)
    {
        printf("%15.3lf",y[a-1]);
    }
    printf("\n");
    system("pause");
	return 0;
 }
