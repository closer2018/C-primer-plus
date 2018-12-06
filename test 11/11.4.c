/*4.设计并测试一个函数，它类似编程练习3的描述，只不过它接受第2个
参数指明可读取的最大字符数。*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 40
void word_get(char *ar,int n);
int main(void)
{
    char ar[SIZE];

    word_get(ar,10);
    puts(ar);

    system("pause");
    return 0;
}

void word_get(char *ar, int n)
{
    char ch;
    int i=0;

    while( isspace( ch=getchar() ) )
        continue;
    do
    {
        *(ar+i)=ch;
        i++;
    }

    while( !isspace(ch=getchar()) && i<(n-1) );
    ar[i]='\0';
}
