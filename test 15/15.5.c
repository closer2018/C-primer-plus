/*5.编写一个函数，把一个 unsigned int 类型值中的所有位向左旋转指定数
量的位。例如，rotate_l(x, 4)把x中所有位向左移动4个位置，而且从最左端
移出的位会重新出现在右端。也就是说，把高阶位移出的位放入低阶位。在
一个程序中测试该函数。*/

#include <stdio.h>
#include <limits.h>
#define SIZE CHAR_BIT * sizeof(unsigned int)

char *trans_10to2(unsigned int n,char *ch);//十进制转二进制字符串
void show(const char *st);
unsigned int move_left(unsigned int, int);
int main(void)
{
    unsigned int num;
    int bit;
    char st[SIZE + 1];

    printf("输入一个整数和你要左移动的位置数:\n");
    while( (scanf("%u%d",&num,&bit)) != 2)
    {
        printf("请输入整数.");
        while(getchar() != '\n') continue;
    }
    while(getchar() != '\n') continue;
    printf("原来的二进制字符串是:\n");
    show(trans_10to2(num,st));
    num = move_left(num, bit);//把所有位向左移动
    printf("现在的二进制字符串是:\n");
    show(trans_10to2(num,st));
}

unsigned int move_left(unsigned int n, int bit)
{
    int i;

    for(i=0;i<bit;i++)
        n=(n<<1)+((n>>(SIZE-1))&01);//n向左移一格，最右边为0
                                    //(n>>(SIZE-1))&01即是最右边0加上最左边的值
                                    //循环移动的位数次
    return n;
}

char *trans_10to2(unsigned int n,char *ch)//十进制转二进制字符串
{
    int i;

    for (i=SIZE-1;i>=0;i--,n>>= 1)
        ch[i]=(01&n)+'0';//n&01是求n最后一位的值
    ch[SIZE]='\0';

    return ch;
}

void show(const char *st)
{
    int i=0;

    while(st[i])
    {
        putchar(st[i]);
        if(++i%4==0 && st[i])
            putchar(' ');
    }
    printf("\n");
}

