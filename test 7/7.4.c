#include <stdio.h> //使用if else语句编写一个程序读取输入，读到#停止。
//用感叹号替换句号，用两个感叹号替换原来的感叹号，最后报告进行了多少次替换。
int main(void)
{
    char words;
    int n=0; //字符数
    printf("请输入内容(#离开):\n");
    while((words=getchar()) != '#')
    {
        if(words == '.')
            {
                words='!'; //替换句号
                n++;
            }
        else if (words == '!')
            {
                printf("!"); //替换!
                n++;
            }
        printf("%c",words);
    }
    printf("一共进行了%d次替换.\n",n);
    return 0;

}
