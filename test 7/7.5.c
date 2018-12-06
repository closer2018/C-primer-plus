#include <stdio.h> //使用switch重写练习4。
int main(void)
{
    char words;
    int n=0; //字符数
    printf("请输入内容(#离开):\n");
    while((words=getchar()) != '#')
    {
        switch(words)
        {
        case '.':words='!'; //替换句号
                n++;
                break;
        case '!':printf("!"); //替换!
                n++;
                break;
        default:break;
        }
        putchar(words);
    }
    printf("一共进行了%d次替换.\n",n);
    return 0;

}
