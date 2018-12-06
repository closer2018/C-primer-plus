#include<stdio.h> //把分钟转换为小时和分钟
#define SECOND 60
int main(void)
{
    int minute=0,hour=0,right=0;
    printf("请输入分钟数:");
    scanf("%d",&minute);
    while(minute>0)
    {
        hour=minute/SECOND;
        right=minute%SECOND;
        printf("%d分钟有%d小时和%d分钟\n",minute,hour,right);
        printf("输入下一个分钟数(小于等于0时停止)\n");
        scanf("%d",&minute);
    }
    system("pause");
    return 0;
}
