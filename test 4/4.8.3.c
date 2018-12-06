#include <stdio.h>

int main(void)
{
    double a=0;
    printf("输入一个小数:");
    scanf("%lf",&a);
    printf("a.输入%.1lf或%.1e\n",a,a);
    printf("b.输入%+.3lf或%.3E\n",a,a);
    system("pause");
    return 0;
}
