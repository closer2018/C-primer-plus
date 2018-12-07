#include <stdio.h>//编写一个程序，在遇到 EOF 之前，把输入作为字符流读取。该程序//要报告输入中的大写字母和小写字母的个数。
#include <ctype.h>
int main(void)
{
    char ch;
    int up_letter=0,low_letter=0;

    printf("输入大写小写字母,统计个数.\n");
    while( (ch=getchar()) != EOF )
    {
        if(islower(ch))
            low_letter++;
        if(isupper(ch))
            up_letter++;
    }
    printf("大写字母有%d个,小写字母有%d个.",up_letter,low_letter);

    return 0;
}
