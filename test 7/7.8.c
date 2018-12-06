#include <stdio.h>  //编写一个程序，提示用户输入一周工作的小时数，然后打印工资总额、税金和净收入。
#define BASE1 8.75
#define BASE2 9.33
#define BASE3 10.00
#define BASE4 11.20
//四种等级的基本工资
#define TIME 40 //超过40小时为加班
#define OVERTIME 1.5    //加班超过40小时=1.5倍的时间
#define TAX1 15/100 //前300美元为15%
#define TAX2 20/100 //续150美元为20%
#define TAX3 25/100 //余下为25%
#define BREAK1 300  //税率的第一个分界点
#define BREAK2 450  //税率的第二个分界点
int main(void)
{
    int a=0,n=0;
    double base=0,work_time=0,tax=0,income=0,wage=0;    //tax税,income收入,wage工资,base基本工资
    const int LENGTH=65;    //*的长度

    for(a=0;a<LENGTH;a++)
        printf("*");
    printf("\n请选择你的工资等级:\n");
    printf("1) $8.75//hr \t\t\t 2) $9.33/hr\n");
    printf("3) $10.00//hr \t\t\t 4) $11.20/hr\n");
    printf("5) 离开\n");
    for(a=0;a<LENGTH;a++)
        printf("*");
    printf("\n");//打印表格

    while(scanf("%d",&n)==1)
    {
    switch(n)
        {
        case 1:base=BASE1;
                break;
        case 2:base=BASE2;
                break;
        case 3:base=BASE3;
                break;
        case 4:base=BASE4;
                break;
        case 5:printf("离开.\n");
                return 0;
        default:printf("请输入正确选项.\n");
        }//选择基本工资等级

    printf("你一周工作多少小时?\n");
    scanf("%lf",&work_time);
    if(work_time<=TIME)
        wage=work_time*base;
    else
    {
        work_time=(work_time-TIME)*OVERTIME+TIME;
        wage=work_time*base;
    }
    if(wage<=BREAK1)
        tax=wage*TAX1;
    else if(wage <=BREAK2)
        tax=BREAK1*TAX1+(wage-BREAK1)*TAX2;
    else
        tax=BREAK1*TAX1+(BREAK2-BREAK1)*TAX2+(wage-BREAK2)*TAX3;  //计算税
    income=wage-tax;
    printf("总工资:%.2lf 税:%.2lf 净收入:%.2lf\n",wage,tax,income);
    printf("再次选择工资等级(1-4;输入q离开):\n");
    }
    return 0;
}
