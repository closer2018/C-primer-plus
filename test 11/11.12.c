/*12.编写一个程序，读取输入，直至读到 EOF，报告读入的单词数、大
写字母数、小写字母数、标点符号数和数字字符数。使用ctype.h头文件中的
函数。*/
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int words=0,upper=0,lower=0;
    int punct=0,digit=0,inword=0;

    while((ch=getchar()) != EOF)
    {
        if(!isspace(ch) && (!ispunct(ch)) && !inword)
        {
            inword=1;
            words++;
        }
        if(isspace(ch) || ispunct(ch) && inword )
            inword=0;
        if(isupper(ch) )
            upper++;
        if(islower(ch))
            lower++;
        if(ispunct(ch))
            punct++;
        if(isdigit(ch))
            digit++;
    }
    printf("单词数: %d, 大写字母数: %d, 小写字母数: %d, 标点数: %d, 数字数: %d.\n",
            words, upper, lower, punct, digit);

    getchar();
    return 0;
}
