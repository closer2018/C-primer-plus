/*4.在一个循环中编写并测试一个函数，该函数返回它被调用的次数*/
#include <stdio.h>
void first (void);
static int num=0;
int main(void)
{
    for(int i=0;i<5;i++)
        first();
    puts("");
    printf("used %d times.\n",num);

    return 0;
}
void first (void)
{
    printf("0 ");
    num++;
}
