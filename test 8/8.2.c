#include <stdio.h>  //编写一个程序，在遇到 EOF 之前，把输入作为字符流读取。程序要
//打印每个输入的字符及其相应的ASCII十进制值。
int main(void)
{
    char ch;
    int n=0; //n统计字符数
    while((ch=getchar())!=EOF)
    {
        n++; //打印字符输出
        if(ch >= 32)
            printf("%c",ch); //换行符和制表符的输出
        else if (ch =='\n' || ch == '\t' )
            printf("%s",ch=='\n' ? "\\n":"\\t");
        //一般控制字符的输出
        else
            printf("^%c",ch + 64);
        printf("%-5d",ch);
        if(ch=='\n')
            n=0;
        if(n%10==0) //10对换行
            printf("\n");
    }
    return 0;
}
