#include <stdio.h>/*7.编写一个函数，从标准输入中读取字符，直到遇到文件结尾。程序要
报告每个字符是否是字母。如果是，还要报告该字母在字母表中的数值位
置。例如，c和C在字母表中的位置都是3。合并一个函数，以一个字符作为
参数，如果该字符是一个字母则返回一个数值位置，否则返回-1。*/
#include <string.h>
int GET_CH(char);
int main(void)
{
    char ch;

    printf("输入文本:");
    while((ch=getchar()) != EOF)
    {
        if(GET_CH(ch)!=-1)
            printf("%c是字母 在第%d位.\n",ch,GET_CH(ch));
        else
        {
            putchar(ch);
            printf("不是字母.\n");
        }

    }
    return 0;
}

int GET_CH(char ch)
{
    if(isalpha(ch))
        return tolower(ch)-'a'+1;
    else
        return -1;
}
