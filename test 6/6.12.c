#include <stdio.h> //计算2个无限序列
int main(void)
{
    double m,n,a,k;
    double l=-1.0;
    int num;
    printf("请输入次数:");
    scanf("%d",&num);
    for(n=1.0,a=0.0,m=0.0;n<=num;n++)
    {
        a=1.0/n;
        m+=a;
        l*=-1.0;
        k+=a*l;
    }
     printf("第一个序列1.0+1.0/2.0+1.0/3.0+1.0/4.0+...是%lf\n",m);
     printf("第二个序列1.0-1.0/2.0+1.0/3.0-1.0/4.0+...是%lf\n",k);
	system("pause");
    return 0;
 }
