#include<stdio.h>    //打印A,逐行递增一个字母且不重复
int main(void)
{
    int a,b;      //a为列,b为行
    char c='A';
    for(a=1;a<=6;a++)
    {
        for(b=1;b<=a;b++)
        {
            printf("%c",c++);
        }
        printf("\n");
    }

    return 0;
}
