#include<stdio.h> //华式温度转摄氏温度和开式温度
void Temperatures(double n);
int main(void)
{
    float n;
    printf("输入一个华氏温度℉:");

    while(scanf("%f",&n)==1)
    {
        Temperatures(n);
        printf("再输入一个(q或非数字离开):");
    }
    system("pause");
    return 0;
}

void Temperatures(double n)
{
    const float a=5.0,b=9.0,c=32.0,d=273.16;
    float e=0,f=0;
    e=a/b*(n-c);
    f=e+d;
    printf("华氏温度:%.2f℉ 摄氏温度:%.2f℃ 开式温度:%.2fK\n",n,e,f);
}
