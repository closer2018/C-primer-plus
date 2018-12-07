#include <stdio.h>//编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。获得
//用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的操作。
#include <ctype.h>
float get_float(void);
char get_choice(void);
char get_first(void);
int main(void)
{
    char choice;
    float num1, num2;

    while((choice=get_choice()) != 'q')
    {
        printf("输入第一个数字:");
        num1=get_float();
        printf("输入第二个数字:");
        num2=get_float();
        switch(choice)
        {
        case 'a':printf("%.2f + %.2f = %.2f\n",num1,num2,num1+num2);
                    break;
        case 'b':printf("%.2f - %.2f = %.2f\n",num1,num2,num1-num2);
                    break;
        case 'c':printf("%.2f * %.2f = %.2f\n",num1,num2,num1*num2);
                    break;
        case 'd':if(!num2)
        {
            printf("请重新输入一个不是0的值:");
            num2=get_float();
        }
            printf("%.2f / %.2f = %.2f\n",num1,num2,num1/num2);
                    break;
        default:printf("我只认识 a, s, m, d 或者 q.\n");
                     break;
        }
    }
    printf("再见.\n");
    return 0;
}
float get_float(void) //获得输入值并处理错误输入的函数
{
    char ch;
    float num;

    while(scanf("%f",&num)!=1)
    {
        while((ch=getchar()) !='\n')
            putchar(ch);//处理错误输入
        printf("不是一个数字.\n请输入一个正确的数字,"
               "例如2.5,-1.78E8,或者3:");

    }
    while (getchar()!='\n')
        continue;

    return num;
}

char get_choice(void)//打印界面和让用户选择的函数
{
    char ch;

    printf("输入你选择的操作:\n");
    printf("%-36s%s","a. 加", "s. 减\n");
    printf("%-36s%s","m. 乘", "d. 除\n");
    printf("%s\n", "q. 离开");

    ch=get_first(); //只取输入的第一个字符
    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd'
                && ch != 'q')
        {
            printf("请输入:a, s, m, d or q.\n");
            ch = get_first();
        }
    return ch;
}

char get_first(void) //只取输入的第一个字符
{
    char ch;
    while( isspace(ch = getchar()))
        continue;
    while (getchar() != '\n' )
        continue;

    return ch;
}
