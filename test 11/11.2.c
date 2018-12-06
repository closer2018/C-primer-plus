/*2.修改并编程练习1的函数，在n个字符后停止，或在读到第1个空白、
制表符或换行符时停止，哪个先遇到哪个停止。不能只使用scanf()。*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 80
char *c_get(char *ar,int n);
int main(void)
{
    char ar[SIZE];

    c_get(ar,10);
    puts(ar);

    system("pause");
    return 0;
}

char *c_get(char *ar,int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        *(ar+i)=getchar();
        if(ar[i]==' '|| ar[i]=='\t' ||ar[i]=='\n')
            break;
    }
    ar[i]='\0';

    return ar;
}
