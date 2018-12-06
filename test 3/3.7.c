#include<stdio.h>
int main(void)
{
    float height=0.0,a=0.0;
    printf("请输入你的身高(英寸):");
    scanf("%f",&height);
    a=height*2.54;
    printf("你的身高是%.2f厘米.\n",a);
    system("pause");
    return 0;
}
