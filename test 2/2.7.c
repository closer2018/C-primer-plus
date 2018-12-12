/*7.许多研究表明，微笑益处多多。编写一个程序，生成以下格式的输
出：
Smile!Smile!Smile!
Smile!Smile!
Smile!
该程序要定义一个函数，该函数被调用一次打印一次“Smile!”，根据程
序的需要使用该函数。*/
#include<stdio.h>


void hhh(void)
{
    printf("smile!");
}

int main(void)
{
    hhh();hhh();hhh();printf("\n");
    hhh();hhh();printf("\n");
    hhh();printf("\n");

    return 0;
}
