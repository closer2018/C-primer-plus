/*6.编写一个程序，创建一个整型变量toes，并将toes设置为10。程序中还
要计算toes的两倍和toes的平方。该程序应打印3个值，并分别描述以示区
分。*/
#include<stdio.h>
int main(void)
{
    int toes,toes_2,toes2;
    toes=10;
    toes_2=toes*2;
    toes2=toes*toes;
    printf("toes是:%d\n",toes);
    printf("toes_2是:%d\n",toes_2);
    printf("toes的平方是:%d\n",toes2);

    return 0;
}
