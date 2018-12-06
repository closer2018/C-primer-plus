#include <stdio.h> //读入8个整数,倒序打印8个整数
int main(void)
{
    long integer[8];
    int a;
    printf("请输入8个整数:");
    for(a=0;a<8;a++)  //数组从0开始存储,所以a=0
    {
        scanf("%d",&integer[a]);
    }
    for(a=7;a>=0;a--)  //8位数,最后的数组元素为7
    {
        printf("%d",integer[a]);
    }
    printf("\n");
	system("pause");
    return 0;
 }
