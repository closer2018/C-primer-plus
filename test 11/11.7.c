/*7.strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中，截断s2，或者有必
要的话在末尾添加空字符。如果s2的长度是n或多于n，目标字符串不能以空
字符结尾。该函数返回s1。自己编写一个这样的函数，名为mystrncpy()。在
一个完整的程序中测试该函数，使用一个循环给函数提供输入值。*/
#include <stdio.h>
#include <string.h>
#define SIZE 40
char *mystrncpy(char *s1,char *s2, int n);
int main(void)
{
    char s1[SIZE];
    char s2[SIZE];
    int num;

    printf("Input the first string (type quit to quit):\n");
    while (strcmp(gets(s1), "quit"))		//输入quit结束
    {
        printf("Input the second string:\n");
        gets(s2);
        printf("Input the number of char copied from s2: ");
        scanf("%d", &num);
        getchar();						//跳过回车
        //当s2的长度大于或等于要拷贝的字符数时，要给s1末尾加上'\0',
        //并且注意要在调用函数之前，不然strlen(s1)会发生改变
        if (strlen(s2) >= num)
            s1[strlen(s1) + num] = '\0';
        puts(mystrncpy(s1, s2, num));	//输出拷贝后的字符串s1
        printf("Input the first string (type quit to quit):\n");
    }

    printf("Bye.\n");

    getchar();
    return 0;
}

char *mystrncpy(char *s1,char *s2, int n)
{
    int i;
    char *str=s1;

    while(*s1++)
        continue;//s1指针指向位置已经超过空字符
    *--s1=*s2;
    for(i=1;i<n&&*s2;i++)
        *++s1=*++s2;

    return str;
}
