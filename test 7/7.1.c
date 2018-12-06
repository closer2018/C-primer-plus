#include <stdio.h> //读取输入,#停止,打印空格换行符数和其他字符数
int main(void)
{
    char ch;
    int space=0,enter=0,other=0;

    while ((ch = getchar()) != '#')
    {
        if(ch==' ')
            space++;
        else if(ch=='\n')
            enter++;
        else
            other++;
    }
    printf("空格数:%d换行符数:%d其他字符数:%d\n",space,enter,other);
    return 0;
}
