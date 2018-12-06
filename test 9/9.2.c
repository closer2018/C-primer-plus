#include <stdio.h>//设计一个函数chline(ch, i, j)，打印指定的字符j行i列。
void chline(char ,int ,int );
int main()
{
    int hang=0,lie=0;
    char ch;

    printf("你要打印什么字符:");
    ch=getchar();
    printf("输入行数列数:");
    scanf("%d %d",&hang,&lie);
    chline(ch,hang,lie);
    printf("\n");

    return 0;
}

void chline(char ch,int hang,int lie)
{
    int a,b;

    for(a=1;a<=hang;a++)
    {
        for(b=1;b<=lie;b++)
            printf("%c",ch);
        printf("\n");
    }
}
