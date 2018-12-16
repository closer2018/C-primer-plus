/*1.编写一个函数，把二进制字符串转换为一个数值。例如，有下面的语
句：
char * pbin = "01001001";
那么把pbin作为参数传递给该函数后，它应该返回一个int类型的值25。*/

#include <stdio.h>
#include<math.h>
int transf(char *st);

int main(void)
{
    char *pbin="01001001";

    printf("%s的十进制是%d.\n",pbin,transf(pbin));

    return 0;
}

int transf(char *st)
{
    int tol=0;

    while(*st)//等于*st!='\0'
        tol=(tol<<1)+(*st++-'0');

    return tol;
}
