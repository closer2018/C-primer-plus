/*15.使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字，
该函数返回0。*/
#include <stdio.h>
#include <ctype.h>
int myatoi(char * st);

int main(void)
{
    char str[40];
    gets(str);
    printf("%d\n", myatoi(str));

    getchar();
    return 0;
}

int myatoi(char * st)
{
    int sum=0;

    while(*st)
    {   //把字符数字逐位转化为数值
        if(isdigit(*st))
            sum=10*sum+(*st-'0');
        else//不是纯数字则返回0
            return 0;
        st++;
    }
    return sum;
}
