/* 1.不使用全局变量，重写程序清单12.4。*/
#include <stdio.h>
int critic(void);
int main(void)
{
    int units = 0;   /* 外部变量 */

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        units=critic();
    printf("You must have looked it up!\n");
    return 0;
}
int critic(void)
{
    int n=0;
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &n);
    return n;
}
