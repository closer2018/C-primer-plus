/*6.编写一个名为is_within()的函数，接受一个字符和一个指向字符串的
指针作为两个函数形参。如果指定字符在字符串中，该函数返回一个非零值
（即为真）。否则，返回0（即为假）。在一个完整的程序中测试该函数，
使用一个循环给函数提供输入值。*/
#include <stdio.h>
#include <string.h>

#define SIZE 80
int is_within(char c,char *str);
int main(void)
{
    char str[SIZE];
    char ch;

    puts("输入一段字符串(quit离开)：");
    while( strcmp(gets(str),"quit") )
    {
        puts("输入一个字母.");
        scanf("%c", &ch);
        while( getchar() != '\n')
            continue;
        if(is_within(ch,str))
            puts("找到了！");
        else
            puts("没有!");
        puts("输入一段字符串(quit离开)：");
    }
    puts("再见！");

    getchar();
    return 0;
}

int is_within(char c,char *str)
{
    int flag=0;
    int i=0;

    while(i++<strlen(str))
    {
        if(*str++ ==c)
        {
            flag=1;
            break;
        }
    }

    return flag;
}
