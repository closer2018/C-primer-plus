#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81//字符串长度
#define SIZE 4//菜单个数

char * s_gets(char * st, int n);
char get_choice(void);
void ToUpper(char * st);//大写
void ToLower(char * st);//小写
void Transpos(char * st);//反转
void Dummy(char * st);//原样

int main(void)
{
    char st[LEN];//存储原字符串
    char copy[LEN];
    char ch;//选择字母
    //函数指针数组
    void(*fp[SIZE])(char *) = {ToUpper, ToLower, Transpos, Dummy};
    int index;

    puts("输入一段文字(什么都不输入会离开程序):");
    while (s_gets(st, LEN) != NULL && st[0] != '\0')
    {
        while ((ch = get_choice()) != 'q')
        {
            switch (ch)
            {
            case 'a': index = 0;
                    break;
            case 'b': index = 1;
                    break;
            case 'c': index = 2;
                    break;
            case 'd': index = 3;
                    break;
            default : printf("程序错误.\n");
                    break;
            }
            strcpy(copy, st);
            (*(fp[index]))(copy);
            puts(copy);
        }
        printf("\n输入一段文字(什么都不输入会离开程序):\n");
    }
    puts("再见.");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("\n输入字母代码选择执行的函数:\n");
    printf("a). 大写\tb). 小写\n");
    printf("c). 反转\td). 原样\n");
    printf("q). 离开.\n");
    while ((ch = (tolower(getchar()))) < 'a' || ch > 'd' && ch != 'q')
    {
        while (getchar() != '\n') continue;
        printf("请输入正确的字母(a, b, c, d h或者 q).\n");
    }
    while (getchar() != '\n') continue;

    return ch;
}

void ToUpper(char * st)
{
    while (*st)
    {
        *st = toupper(*st);
        st++;
    }
}

void ToLower(char * st)
{
    while (*st)
    {
        *st = tolower(*st);
        st++;
    }
}

void Transpos(char * st)
{
    while (*st)
    {
        if (islower(*st))
            *st = toupper(*st);
        else if (isupper(*st))
            *st = tolower(*st);
        st++;
    }
}

void Dummy(char * st)
{

}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
