/*2.编写一个函数，提示用户输入日、月和年。月份可以是月份号、月份
名或月份名缩写。然后该程序应返回一年中到用户指定日子（包括这一天）
的总天数*/
#include <stdio.h>
#include <string.h>//提供strcmp()函数
#include <ctype.h>//提供tolower()函数
#include <stdlib.h>//提供exit
int get_days(int n);//天
int get_months(void);//月
int get_years(void);//年
int answer(void);//答案
char * s_gets(char * st, int n);

struct month{
    char name[20];
    char abbr[4];
    int days;
    char monumb[3];
};
struct month months[12]={
                        { "january", "jan", 31, "1" },
                        { "february", "feb", 28, "2" },
                        { "march", "mar", 31, "3" },
                        { "april", "apr", 30, "4" },
                        { "may", "may", 31, "5" },
                        { "june", "jun", 30, "6" },
                        { "july", "jul", 31, "7" },
                        { "august", "aug", 31, "8" },
                        { "september", "sep", 30, "9" },
                        { "october", "oct", 31, "10" },
                        { "november", "nov", 30, "11" },
                        { "december", "dec", 31, "12" }
                        };

int main(void)
{
    answer();
    puts("再见.");

    return 0;
}

int get_days(int n)
{
    int d;

    puts("请输入日:");
    while( scanf("%d",&d) != 1 || (d<1 ||d>months[n-1].days))
    {
        while( getchar() !='\n')
            continue;//清理输入行
        printf("请输入正确的日(1到%d).",months[n-1].days);
    }
    while( getchar() !='\n') continue;//清理输入行

    return d;//返回日
}

int get_months(void)//月
{
    char m[20];//月份
    int i=0,n=0;

    puts("请输入月份(可以是月份号(1-12)、月份名或月份名缩写):");
    s_gets(m,20);

    while(m[i])
    {
        if(isalpha(m[i]))
            m[i] = tolower(m[i]);  // 转换为小写
        i++;
    }
    for(i=0;i<12;i++)
    {//匹配月份
        if( strcmp( m, months[i].name) == 0 ||
            strcmp( m, months[i].abbr) == 0 ||
            strcmp( m, months[i].monumb) == 0)
            {
                n=i+1;
                break;
            }
    }
	if (n>12||n<1)
	{
		printf("错误的月份.\n");
		exit(1);
	}

    return n;//返回月份
}

int get_years(void)//年
{
    int y;//年

    puts("请输入年份:");
    while( scanf("%d",&y) != 1 )
    {
        while( getchar() !='\n')
            continue;//清理输入行
        puts("请输入正确的年份:");
    }
    while( getchar() !='\n') continue;//清理输入行
    if( (y%4 == 0 && y%100 != 0 )||(y%400 == 0 && y%3200 != 0)) //判断是平年还是闰年
        months[1].days=29;//闰年，2月修改为29天
    else
        months[1].days=28;//平年，2月修改为28天

    return y;//返回年
}

int answer(void)//答案
{
    int day=0;
    int month;
    int year;
    int i,tol=0;

    year=get_years();
    month=get_months();
    day=get_days(month);

    for(i=0,tol=0;i<month-1;i++)//统计月份日合计
        tol+=months[i].days;
    tol+=day;//加上单月的日数
    printf("直至%d-%d-%d 共计%d天.\n",year,month,day,tol);

    return tol;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)         // 如果地址不是NULL，
            *find = '\0';    // 在此处放置一个空字符
    else
        while (getchar() != '\n')
            continue;     // 清理输入行中剩余的字符
    }
    return ret_val;
}

