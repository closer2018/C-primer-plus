/*2.编写一个程序，要求提示输入一个ASCII码值（如，66），然后打印
输入的字符*/
#include<stdio.h>
int main(void)
{
    char a;
    printf("请输入一个数字:");
    scanf("%d",&a);
    printf("这个数字的ASCII码值是%c\n",a);

    return 0;
}
