/*9.编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整
的程序中测试该函数，使用一个循环给函数提供输入值。*/
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define QUIT "quit"
char * s_gets(char * st, int n);
void reverse(char * st);
int main(void)
{
    char str[SIZE];

    printf("Input the first string (type quit to quit):\n");
    while (strcmp(s_gets(str, SIZE), QUIT))		//输入quit结束
    {
        reverse(str);
        puts(str);
        printf("Input the first string (type quit to quit):\n");
    }


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

//使字符串倒序的函数
void reverse(char * st)
{
    unsigned int i;
    char temp;

    size_t length = strlen(st);
    for (i = 0; i < length / 2; i++)
    {
        temp = st[length - i -1];
        st[length - i - 1] = st[i];
        st[i] = temp;
    }
    st[length] = '\0';
}

//这个函数只是倒序打印输入字符串，并不会使字符串倒序。
//void reverse(char * st)
//{
//    int i=0;
//
//    for(i=strlen(st)-1;i>=0;i--)
//        putchar(st[i]);
//    st[0]='\0';
//}
