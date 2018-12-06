#include <stdio.h>

int main(void)
{
    char name[40];
    char xing[40];
    printf("输入你的名:");
    scanf("%s",name);
    printf("输入你的姓:");
    scanf("%s",xing);
    printf("你的名字是%s,姓是%s\n",name,xing);
    system("pause");
    return 0;
}
