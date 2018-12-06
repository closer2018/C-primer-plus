#include <stdio.h>  //编写一个程序，让用户指定缴纳税金的种类和应纳税收入，然后计算税金。
#define TAX1 0.15
#define TAX2 0.28
//2种税率
#define SINGLE 17850
#define HOUSE 23900
#define SHARE 29750
#define DIVORCED 14875
//4种类别
int main(void)
{
    double gross=0.0,tax=0.0,base=0.0;
    int a,n;
    const int LENGTH=65;

    for(a=0;a<LENGTH;a++)
        printf("*");
    printf("\n请选择你的类别:\n");
    printf("1) 单身 \t\t\t 2) 户主\n");
    printf("3) 已婚,共有 \t\t\t 4) 已婚,离异\n");
    printf("5) 离开\n");
    for(a=0;a<LENGTH;a++)
        printf("*");
    printf("\n");//打印表格

    while(scanf("%d",&n)==1)
    {
    switch(n)
        {
        case 1:base=SINGLE;
                break;
        case 2:base=HOUSE;
                break;
        case 3:base=SHARE;
                break;
        case 4:base=DIVORCED;
                break;
        case 5:printf("离开.\n");
                return 0;
        default:printf("请输入正确选项.\n");
        }//选择类别

    printf("输入纳税金额:\n");
    scanf("%lf",&gross);
    if(gross<=base)
       tax=gross*TAX1;
    else
       tax=base*TAX1+(gross-base)*TAX2;
    printf("你需要缴纳的税金是:%.2lf.\n",tax);
    printf("再次选择类别(1-4;输入q离开):\n");
    }
    return 0;
}
