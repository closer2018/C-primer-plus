#include <stdio.h> //该程序要报告平均每个单词的字母数。不要把空白统计为单词的字母。
#include <ctype.h>
int main(void)
{
    char ch=0;
    double average_letter=0;
    int inword=0;//在单词中为1,不在为0
    int chars=0;
    int words=0;

    printf("输入单词,统计平均字母个数.\n");
    while((ch=getchar())!= EOF)
    {
        if(!isspace(ch) && !ispunct(ch))//不是空白和标点
            chars++;    //统计字符个数
        if(!ispunct(ch)&&!isspace(ch)&&!inword)//不是空格标点且在单词中
        {
            inword=1; //就说明开始单词,在单词为1
            words++; //单词数加1
        }
        if(ispunct(ch)||isspace(ch)&&inword) //离开单词且是空白或标点
            inword=0;//单词结束了,不在单词中了
    }
    average_letter=(double)chars/(double)words;
    printf("有%d个字符和%d个单词\n",chars,words);
    printf("平均字母个数是:%.2f个.\n",average_letter);

    return 0;
}
