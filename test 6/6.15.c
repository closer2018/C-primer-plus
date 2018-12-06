#include <stdio.h> //倒序打印输入的文字
int main(void)
{
    char word[256];
    int a=-1,b;
    printf("输入一行话:");
    do
    {
        a++;
        scanf("%c", &word[a]);
    } while (word[a] != '\n');
    for(b=a;b>0;b--)
    {
        printf("%c",word[b-1]);
	}
	return 0;
 }
