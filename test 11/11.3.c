/*3.设计并测试一个函数，从一行输入中把一个单词读入一个数组中，并
丢弃输入行中的其余字符。该函数应该跳过第1个非空白字符前面的所有空
白。将一个单词定义为没有空白、制表符或换行符的字符序列。*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 40
void word_get(char *ar);
int main(void)
{
    char ar[SIZE];

    word_get(ar);
    puts(ar);

    system("pause");
    return 0;
}

void word_get(char *ar)
{
    char ch;

    while( isspace( ch=getchar() ) )
        continue;
    do
        *ar++=ch;
    while( !isspace( ch=getchar() ) );
    *ar='\0';
}
