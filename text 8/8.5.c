#include <stdio.h> //猜数字程序,使用二分查找（binary search）策略
#define LOW 1   //初始下限
#define HIGH 100    //初始上限
int get_guess(void);
int main(void)
{
    while(1)
        get_guess();
}

int get_guess(void)
{
    long guess = (HIGH+LOW)/2;
    long n=1;//n为猜的次数
    long low=LOW;
    long high= HIGH;
    char ch;

    printf("选择一个整数大于%d小于%d,我来猜它.\n",LOW,HIGH);
    printf("对就输入\"y\",大了打\"b\",小了打\"s\".\n");
    printf("额...是%ld吗?\n",guess);
    while ((ch=getchar()) != 'y')  /* 获取响应，与 y 做对比 */
    {
        if(ch=='s')
        {
            low=guess; //猜小了,重置下限为猜的数
            guess=(guess+high)/2;//重置guess在下限和上限之间
        }
        else if(ch=='b')
        {
            high=guess;//猜大了,重置上限
            guess=(guess+low)/2;//重置guess在上限和下限之间
        }
        else
            printf("我只认识'y','b'和 's'.\n");

        printf("额...是%ld吗?\n",guess);
        while(getchar()!='\n')
            continue; //只取输入首字母
        if(guess==HIGH-1)
            guess++; //让取值能达到上限
        n++;
    }
        printf("看来我猜对了\n");
        printf("我只猜了%ld次就猜出来了.\n",n);
        printf("快表扬我!\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("来继续猜吧!\n");
        while(getchar()!='\n')
            continue; //只取输入首字母
    return 0;
}
