#include <stdio.h> //程序要打印每个输入的字符以及对应的ASCII码（十进制）。一行打印8个字符。
int main(void)
{
    char ch;
    int n=1; //字符数
    printf("请输入一些单词(#结束):\n");
    while ((ch = getchar()) != '#')
    {
        printf("%3c:%3d ",ch,ch);
        if(n++%8==0)
            printf("\n");
    }
    return 0;
}
