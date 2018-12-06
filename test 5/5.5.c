#include<stdio.h> //计算前20个整数的和

int main(void)
{
    int money=0,day=0,a=0;
    printf("输入你每天赚多少钱:");
    scanf("%d",&money);
    a=money;
    while (day++<20)
    {
        printf("第%d天赚%d钱.\n",day,money);
        money=money+a;
    }
    system("pause");
    return 0;
}
