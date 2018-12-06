/*5.设计并测试一个函数，搜索第1个函数形参指定的字符串，在其中查
找第2个函数形参指定的字符首次出现的位置。如果成功，该函数返指向该
字符的指针，如果在字符串中未找到指定字符，则返回空指针（该函数的功
能与 strchr()函数相同）。在一个完整的程序中测试该函数，使用一个循环
给函数提供输入值。*/
#include <stdio.h>
#include <string.h>

#define SIZE 80
char *search_string(char *str,char c);
int main(void)
{
    char str[SIZE];
    char ch;
    char *temp;

    puts("输入一段字符串(quit离开)：");
    gets(str);
    while( strcmp(str,"quit") )
    {
        puts("输入一个字母.");
        scanf("%c", &ch);
        while( getchar() != '\n')
            continue;
        temp=search_string(str,ch);
        if(temp!=NULL)
            printf("找到了！以%c开始的字符串是%s.",ch,temp);
        else
            puts("没有!");
        puts("输入一段字符串(quit离开)：");
        gets(str);
    }
    puts("再见！");

    getchar();
    return 0;
}

char *search_string(char *str,char c)
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
    if(flag)
        return str-1;
    else
        return NULL;
}
