/*2.编写一个程序，提示用户输入名和姓，并执行一下操作：
a.打印名和姓，包括双引号；
b.在宽度为20的字段右端打印名和姓，包括双引号；
c.在宽度为20的字段左端打印名和姓，包括双引号；
d.在比姓名宽度宽3的字段中打印名和姓。*/
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
    return 0;
}
