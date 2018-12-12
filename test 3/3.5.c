/*5.一年大约有3.156×10 7 秒。编写一个程序，提示用户输入年龄，然后显
示该年龄对应的秒数。*/
#include<stdio.h>
int main(void)
{
    int ages;
    double seconds;
    printf("你多大了:");
    scanf("%d",&ages);
    seconds=ages*3.156e7;
    printf("你的年龄对应的秒数是:%e秒.",seconds);

    return 0;
}
