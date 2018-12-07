/*11.编写一个程序，接受两个命令行参数。第1个参数是一个字符串，第
2个参数是一个文件名。然后该程序查找该文件，打印文件中包含该字符串
的所有行。因为该任务是面向行而不是面向字符的，所以要使用fgets()而不
是getc()。使用标准C库函数strstr()（11.5.7节简要介绍过）在每一行中查找
指定字符串。假设文件中的所有行都不超过255个字符。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //提供strstr函数
#define SIZE 256
int main (int argc,char *argv[])
{
    FILE *p;
    char ch[SIZE];
    int flag1,flag2;

    if(argc!=3)
    {
        fprintf(stderr, "命令行参数数量错误\n.");
        exit(EXIT_FAILURE);
    }
    else
    {
        if( (p=fopen(argv[2],"r")) ==NULL )
            {
                fprintf(stderr,"不能打开%s文件",argv[2]);
                exit(EXIT_FAILURE);
            }
    }
    while( fgets(ch,SIZE,p) != NULL)
    {
        if( strstr( ch,argv[1] ))//在行中查找字符串参数
        {
            fputs(ch,stdout);
            flag1=0;
        }
        else
            flag2=1;
    }
    if(flag1&&flag2)
        puts("没有该字符串！");
    fclose(p);

    return 0;
}
