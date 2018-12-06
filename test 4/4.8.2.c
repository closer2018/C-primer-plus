#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[40];
    char xing[40];
    int widthn,widthx;
    printf("输入你的名:");
    scanf("%s",name);
    printf("输入你的姓:");
    scanf("%s",xing);
    widthn=strlen(name)+3;
    widthx=strlen(xing)+3;
    printf("a:你的名字是\"%s\",姓是\"%s\".\n",name,xing);
    printf("b:你的名字是\"%20s\",姓是\"%20s\".\n",name,xing);
    printf("c:你的名字是\"%-20s\",姓是\"%-20s\".\n",name,xing);
    printf("d:你的名字是\"%*s\",姓是\"%*s\".\n",
           widthn,name,widthx,xing);
    system("pause");
    return 0;
}
