#include<stdio.h> //读取一个单词,倒序打印它
#include <string.h>
int main(void)
{
    char word[40];
    int n,a;
    printf("请输入一个单词:");
    scanf("%s",word);
    n=strlen(word);
    printf("这个单词倒过来写是:");
    for(a=0;a<=n;a++)
        printf("%c",word[strlen(word)-a-1]);
    printf("\n");

    return 0;
}
