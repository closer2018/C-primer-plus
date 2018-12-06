/* 1.设计并测试一个函数，从输入中获取下n个字符（包括空白、制表
符、换行符），把结果储存在一个数组里，它的地址被传递作为一个参数。*/
#include <stdio.h>
#define SIZE 40
char *c_get(char *ar,int n);
int main(void)
{
    char ar[SIZE];

    c_get(ar,10);
    puts(ar);

    return 0;
}

char *c_get(char *ar,int n)
{
    int i=0;

    while(i<n)
        ar[i++]=getchar();
    ar[i]='\0';

    return ar;
}
