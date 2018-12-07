#include <stdio.h> //修改程序清单8.8中的get_first()函数，让该函数返回读取的第1个非空
//白字符，并在一个简单的程序中测试。
#include <ctype.h>
char get_choice(void);  //除了abcq,不能选择其他的
char get_first(void);   //得到输入的第一格字符
int get_int(void); //只能输入整数
void count(void); //得到整数,且消除空格影响
int main(void)
{
    int choice;
    void count(void);

    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a': printf("Buy low, sell high.\n");
                    break;
            case 'b': putchar('\a'); /* ANSI */
                    break;
            case 'c': count();
                    break;
            default:  printf("Program error!\n");
                    break;
        }
    }
    printf("Bye.\n");

    return 0;
}
void count(void) //得到整数,且消除空格影响
{
    int n, i;

    printf("Count how far? Enter an integer:\n");
    n = get_int();
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    while (getchar() != '\n')
        continue;
}
char get_choice(void) //除了abcq,不能选择其他的
{
    int ch;

    printf("Enter the letter of your choice:\n");
    printf("a. advice       b. bell\n");
    printf("c. count        q. quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();
    }
    return ch;
}

char get_first(void) //得到输入的第一格非空白字符
{
    char ch;
    while( isspace(ch = getchar()))
        continue;
    while (getchar() != '\n' )
        continue;

    return ch;
}


int get_int(void) //只能输入整数
{
    int input;
    char ch;

    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch); // 处理错误输出
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
    return input;
}

