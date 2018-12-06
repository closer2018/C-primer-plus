#include<stdio.h>    //打印金字塔,输入字母从下到上且往两边递减到A
int main(void)
{
    char ch = 0,temp = 0;
    int i,j,length;
    printf("请输入大写字母:");
    scanf("%c",&ch);

    length = ch - 'A' + 1;   //有多少行字母
    for (i = 0; i < length; i++)
    {
        temp = 'A'-1 ;
        for (j = 0; j < (length - i -1); j++)
            printf(" ");
        for (j = 0; j <= i; j++)
            printf("%c", ++temp);
        for (j = 0; j < i; j++)
            printf("%c", --temp);
        printf("\n");
    }
    system("pause");
    return 0;
}
