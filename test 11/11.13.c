/*13.编写一个程序，反序显示命令行参数的单词。例如，命令行参数是
see you later，该程序应打印later you see。*/
#include <stdio.h>
#include <string.h>
//void reverse(char * st);
int main(int argc, char * argv[])
{
    int count;

    for (count = argc - 1; count > 0; count--)
        printf("%s ", argv[count]);

    return 0;
}

////这个函数只是倒序打印输入字符串，并不会使字符串倒序。
//void reverse(char * st)
//{
//    int i=0;
//
//    for(i=strlen(st)-1;i>=0;i--)
//        putchar(st[i]);
//    st[0]='\0';
//}
