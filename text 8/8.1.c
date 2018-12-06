#include <stdio.h>  //设计一个程序，统计在读到文件结尾之前读取的字符数。
int main(void)
{
    int ch;
    int a=0;
    while((ch=getchar())!=EOF)
        a++;
    printf("%d\n",a);


    return 0;
}
