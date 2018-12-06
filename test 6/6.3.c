#include<stdio.h>    //打印F,逐行递增一个字母但字母递减到A
int main(void)
{
    int a,b;   //a为列,b为行
    char c='F';
    for(a=1;a<=6;a++)
    {
        for(b=0;b<a;b++)
        {
            printf("%c",c-b);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
