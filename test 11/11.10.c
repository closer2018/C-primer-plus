/*10.编写一个函数接受一个字符串作为参数，并删除字符串中的空格。
在一个程序中测试该函数，使用循环读取输入行，直到用户输入一行空行。
该程序应该应用该函数只每个输入的字符串，并显示处理后的字符串。*/
#include <stdio.h>
#include <string.h>
#define SIZE 40
char * s_gets(char * st, int n);
void delete_space(char * st);
int main(void)
{
    char str[SIZE];

    while (*s_gets(str, SIZE) != '\n')  //输入空行结束
        delete_space(str);
    puts("Bye.");

    getchar();
    return 0;
}

//自定义的字符串输入函数
char * s_gets(char * st, int n)
{
    int i = 0;

    printf("Input the first string (blank line to quit):\n");
    if (fgets(st, n, stdin) != NULL && st[0] != '\n')	//即返回值st不等于NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return st;
}

//删除空格的函数
void delete_space(char * st)
{
    char *temp=st;

    printf("\nThe original string is:\n");
    puts(st);
    while(*st)
    { //如果遇到空格，后面所有字符往前进一格
        if(*st==' ')
            for(int i=0;st[i]!='\0';i++)
                st[i]=st[i+1];
        else
            st++;
    }
    puts("Now, the string is:");
    puts(temp);
}

