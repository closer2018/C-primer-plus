#include<stdio.h>
int main(void)
{
    float a;
    printf("输入一个小数:(请输入64.25)");
    printf("_____\b\b\b\b\b");
    scanf("%f",&a);
    printf("Enter a floating-point value:%.2f\n",a); //64.25
    printf("fixed-point notation:%f\n",a);    //64.250000
    printf("exponential notation:%e\n");   //6.425000e+01
    printf("p notation:%.2a\n");    //0x1.01p+6
    system("pause");
    return 0;
}
