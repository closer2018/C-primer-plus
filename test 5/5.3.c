#include<stdio.h> //天数转换为周和天
#define WEEK_DAY 7
int main(void)
{
    int day=0,week=0,right=0;
    printf("请输入一个天数:");
    scanf("%d",&day);
    while(day>0)
    {
        week=day/WEEK_DAY;
        right=day%WEEK_DAY;
        printf("%d天有%d周,%d天.\n ",day,week,right);
        printf("当你输入0时结束\n");
        scanf("%d",&day);
    }
    system("pause");
    return 0;
}
