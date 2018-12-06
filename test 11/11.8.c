/*8.编写一个名为string_in()的函数，接受两个指向字符串的指针作为参
数。如果第2个字符串中包含第1个字符串，该函数将返回第1个字符串开始
的地址。例如，string_in("hats", "at")将返回hats中a的地址。否则，该函数返
回空指针。在一个完整的程序中测试该函数，使用一个循环给函数提供输入
值。*/
#include <stdio.h>
#include <string.h>
#define SIZE 40
char * s_gets(char * st, int n);
char *string_in(char *s1,char *s2);
int main(void)
{
    char str1[SIZE];
    char str2[SIZE];

    printf("Input the first string (type quit to quit):\n");
    while (strcmp(s_gets(str1, SIZE), "quit"))		//输入quit结束
    {
        printf("Input the second string:\n");
        s_gets(str2, SIZE);
        if ( string_in(str1, str2) )
        {
            printf("Find!\n");
            puts( string_in(str1, str2) );
        }
        else
            printf("Can't find!\n");
        printf("Input the first string (type quit to quit):\n");
    }
    printf("Bye.\n");

    getchar();
    return 0;
}

//自定义的字符串输入函数
char * s_gets(char * st, int n)
{
    int i = 0;

    if (fgets(st, n, stdin))	//即返回值st不等于NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return st;
}

//在s1中检测s2
char *string_in(char *s1,char *s2)
{
    int i;

    while(*s1) //遍历s1字符串
    {
        i=0;
        while (s1[i] == s2[i])//检查是否相等
        {
            i++;
            if(!s2[i])//相等到最后s2末尾是0.！0是1，return。
                return s1;
        }

        s1++;
    }
    return NULL;
}
