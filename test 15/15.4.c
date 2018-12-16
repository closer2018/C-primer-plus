/*4.编写一个程序，接受两个int类型的参数：一个是值；一个是位的位
置。如果指定位的位置为1，该函数返回1；否则返回0。在一个程序中测试
该函数。*/

#include <stdio.h>

int check_bit(int num,int b);

int main(void)
{
    int num,bit;

    puts("输入一个整数和位置：");
    while( (scanf("%d%d",&num,&bit)) != 2)
    {
        printf("请输入整数.");
        while(getchar() != '\n') continue;
    }
    while(getchar() != '\n') continue;
    printf("%d的二进制第%d位是%d.\n",num,bit,check_bit(num,bit));

	return 0;
}

int check_bit(int num,int b)
{
	for(int i=0;i<b;i++)
        num>>=1;//等同于num/=2

	return num&1;//num&01是求num最后一位的值
}
