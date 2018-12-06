#include <stdio.h>  /*编写一个函数，接受3个参数：一个字符和两个整数。字符参数是待
                      打印的字符，第1个整数指定一行中打印字符的次数，第2个整数指定打印指
                      定字符的行数。编写一个调用该函数的程序。*/
void TEST(char ch,int i,int j);
int main()
{
    int i,j;
    char ch;

    printf("输入字符:\n");
    ch=getchar();
    printf("打印几行,每行几个:\n");
    scanf("%d%d",&j,&i);
    TEST(ch,i,j);
    return 0;
}
void TEST(char ch,int i,int j) //i一行打印几次,j打印几行
{
    int m,n;
    for(m=1;m<=j;m++)
    {
        for(n=1;n<=i;n++)
            printf("%c",ch);
        printf("\n");
    }
}
