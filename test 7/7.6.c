#include <stdio.h> //编写程序读取输入，读到#停止，报告ei出现的次数。
int main(void)
{
    char ch;
    char ch_pre=0; //前一个字符
    int n=0; //记录ei出现次数.
    printf("输入文字(统计ei出现次数,#离开):\n");
    while((ch=getchar())!='#')
    {
        if((ch_pre=='e')&&(ch=='i'))
            n++;
        ch_pre=ch; //每一次循环后,把ch赋值给ch_pre,ch_pre就变为前一个字符
    }
    printf("\"ei\"出现了%d次.\n",n);
    return 0;
}
