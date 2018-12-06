#include<stdio.h>
int main(void)
{
    int ages;
    double seconds;
    printf("你多大了:");
    scanf("%d",&ages);
    seconds=ages*3.156e7;
    printf("你的年龄对应的秒数是:%e秒.",seconds);
    system("pause");
    return 0;
}
