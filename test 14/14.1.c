/*1.重新编写复习题 5，用月份名的拼写代替月份号（别忘了使用
strcmp()）。在一个简单的程序中测试该函数*/
#include <stdio.h>
#include <string.h>//提供strcmp()函数
#include <ctype.h>
int days(char *st);
char * s_gets(char * st, int n);

struct month{
    char name[20];
    char abbr[4];
    int days;
    int monumb;
};
struct month months[12]={
                        { "january", "jan", 31, 1 },
                        { "february", "feb", 28, 2 },
                        { "march", "mar", 31, 3 },
                        { "april", "apr", 30, 4 },
                        { "may", "may", 31, 5 },
                        { "june", "jun", 30, 6 },
                        { "july", "jul", 31, 7 },
                        { "august", "aug", 31, 8 },
                        { "september", "sep", 30, 9 },
                        { "october", "oct", 31, 10 },
                        { "november", "nov", 30, 11 },
                        { "december", "dec", 31, 12 }
                        };

int main(void)
{
    char temp[21];
    int i,n;

    puts("请输入月份名:");
    while( s_gets(temp,20) !=NULL && temp[0] != '\0')
    {
        if(  days(temp) ==0 )
            puts("错误的月份.");
        else
            printf("一年到%s月共有%d天.\n",temp,days(temp));
        puts("输入下一个月份名(回车离开):");
    }
    puts("再见.");

    return 0;
}

int days(char *st)
{
    int i=0,tol=0,n=0;

    while(st[i])
    {
        if(isalpha(st[i]))
            st[i] = tolower(st[i]);  // 转换为小写
        i++;
    }

    for(i=0;i<12;i++)
    {
        if( strcmp( st, months[i].name) == 0 )
        {
            n=i+1;
            break;
        }
    }

    for(i=0,tol=0;i<n;i++)
        tol+=months[i].days;
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

