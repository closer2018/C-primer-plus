#include<stdio.h> //打印$,逐行递增一个
int main(void)
{
    int a,b;   //a为列,b为行
    for(a=1;a<=5;a++)
    {
        for(b=0;b<a;b++)
        {
            printf("$");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
