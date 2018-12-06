#include <stdio.h>  //编写一个程序，提示用户输入一周工作的小时数，然后打印工资总额、税金和净收入。
#define BASE_PAY 10   //基本工资10美元/小时
#define TIME 40 //超过40小时为加班
#define OVERTIME 1.5    //加班超过40小时=1.5倍的时间
#define TAX1 15/100 //前300美元为15%
#define TAX2 20/100 //续150美元为20%
#define TAX3 25/100 //余下为25%
#define BREAK1 300  //税率的第一个分界点
#define BREAK2 450  //税率的第二个分界点
int main(void)
{
    double work_time=0,tax=0,income=0,wage=0;    //tax税,income收入,wage工资
    printf("你一周工作多少小时?\n");
    scanf("%lf",&work_time);
    if(work_time<=TIME)
        wage=work_time*BASE_PAY;
    else
    {
        work_time=(work_time-TIME)*OVERTIME+TIME;
        wage=work_time*BASE_PAY;
    }
    if(wage<=BREAK1)
        tax=wage*TAX1;
    else if(wage <=BREAK2)
        tax=BREAK1*TAX1+(wage-BREAK1)*TAX2;
    else
        tax=BREAK1*TAX1+(BREAK2-BREAK1)*TAX2+(wage-BREAK2)*TAX3;  //计算税
    income=wage-tax;
    printf("工资:%.2lf 税:%.2lf 净收入:%.2lf\n",wage,tax,income);
    return 0;
}
