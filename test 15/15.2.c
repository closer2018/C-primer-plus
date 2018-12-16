/*2.编写一个程序，通过命令行参数读取两个二进制字符串，对这两个二
进制数使用～运算符、&运算符、|运算符和^运算符，并以二进制字符串形
式打印结果（如果无法使用命令行环境，可以通过交互式让程序读取字符
串）。*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int trans_2to10(char *st);//2进制字符串转10进制整数
char *trans_10to2(int num,char *ch);//10进制整数转二进制字符串
void show(const char * st);//打印字符串

int main(int argc,char *argv[])
{
    int x,y;
    char ch[CHAR_BIT*sizeof(int) + 1];

    if(argc!=3)
    {
        fprintf(stderr,"参数错误!\n");
        exit(EXIT_FAILURE);
    }

    x=trans_2to10(argv[1]);
    y=trans_2to10(argv[2]);

    printf("     ~%s     是: ",argv[1]);
    show(trans_10to2(~x,ch));
    printf("     ~%s     是: ",argv[2]);
    show(trans_10to2(~y,ch));
    printf("%s & %s是: ",argv[1],argv[2]);
    show(trans_10to2(x&y,ch));
    printf("%s | %s是: ",argv[1],argv[2]);
    show(trans_10to2(x|y,ch));
    printf("%s ^ %s是: ",argv[1],argv[2]);
    show(trans_10to2(x^y,ch));

    return 0;
}

int trans_2to10(char *st)
{
    int tol=0;

    while(*st)
        tol=(tol<<1)+(*st++-'0');

    return tol;
}

char *trans_10to2(int n,char *ch)
{
    int i;
    const static int size=CHAR_BIT*sizeof(int);

    for (i=size-1;i>=0;i--,n>>= 1)
        ch[i]=(01&n)+'0';
    ch[size]='\0';

    return ch;
}

void show(const char *st)
{
    int i=0;

    while(st[i])
    {
        putchar(st[i]);
        if(++i%4==0 && st[i])
            putchar(' ');
    }
    printf("\n");
}

