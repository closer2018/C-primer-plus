/*11.编写一个函数，读入10个字符串或者读到EOF时停止。该程序为用
户提供一个有5个选项的菜单：打印源字符串列表、以ASCII中的顺序打印字
符串、按长度递增顺序打印字符串、按字符串中第1个单词的长度打印字符
串、退出。菜单可以循环显示，除非用户选择退出选项。当然，该程序要能
真正完成菜单中各选项的功能*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 10
#define SIZE 80
char * s_gets(char * st, int n);			//获取字符串输入
char get_choice(void);						//获取选择
void print_sour(char * st[], int n);		//打印源字符串
void print_ascii(char * st[], int n);		//按ASCII码顺序打印
void print_length(char * st[], int n);		//按长度顺序打印
void print_first_word(char * st[], int n);	//按第一个单词的长度顺序打印
int first_word(char * st);					//计算第一个单词数
void get_choice_main(void);                 //获取字符串，并选择
int main(void)
{
    get_choice_main();

    getchar();
    return 0;
}

//获取字符串，并选择
void get_choice_main(void)
{
    char str[LIM][SIZE];
    char * ptr[LIM];
    int row = 0;							//输入的字符串数量
    char choice;							//用户输入的选择字符

    puts("输入一些字符串（不大于10个）:");
    while( row<LIM && s_gets(str[row],SIZE) != NULL )//统计输入字符串的个数
    {
        ptr[row]=str[row];
        row++;
    }
    while((choice=get_choice()) != 'q')
        {
            printf("\n");
            switch(choice)
            {
                case 'a':print_sour(ptr,row);
                        break;
                case 'b':print_ascii(ptr,row);
                        break;
                case 'c':print_length(ptr,row);
                        break;
                case 'd':print_first_word(ptr,row);
                        break;
                default: puts("Error!");
                         break;

            }
            printf("\n");
        }
    puts("再见！");
}

//自定义的字符串输入函数
char * s_gets(char * st, int n)
{
    int i = 0;

    if (fgets(st, n, stdin) != NULL)
    {	//即返回值st不等于NULL
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
        return st;
    }
    else
        return NULL;

}

//获取选择
char get_choice(void)
{
    char choice;

    printf("a:打印源字符串列表\t b:以ASCII中的顺序打印字符串\n"
           "c:按长度递增顺序打印字符串\t d:按字符串中第1个单词的长度打印字符串\n"
           "q:退出\n");
    puts("请输入你的选择:");
    choice=getchar();
    while(getchar() != '\n')
        continue;
    while(choice<'a'||choice>'d'&&choice!='q')
    {//输入不是a-d,且不是q，则提示重新输入
        puts("请输入正确的选择:");
        choice=getchar();
        while(getchar() != '\n')
            continue;
    }

    return choice;
}

//打印源字符串
void print_sour(char * st[], int n)
{
    for(int i=0;i<n;i++)
        puts(st[i]);
}

//按ASCII码顺序打印
void print_ascii(char * st[], int n)
{
    char *t;

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(strcmp(st[i],st[j]) >0)
            {//冒泡算法排序
                t=st[j];
                st[j]=st[i];
                st[i]=t;
            }
    for(int i=0;i<n;i++)
        puts(st[i]);
}

//按长度顺序打印
void print_length(char * st[], int n)
{
    char *t;

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(strlen(st[i]) > strlen(st[j]) )
            {//冒泡算法排序
                t=st[j];
                st[j]=st[i];
                st[i]=t;
            }
    for(int i=0;i<n;i++)
        puts(st[i]);
}

//按第一个单词的长度顺序打印
void print_first_word(char * st[], int n)
{
    char *t;

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if( first_word(st[i]) > first_word(st[j]) )
            {//冒泡算法排序
                t=st[j];
                st[j]=st[i];
                st[i]=t;
            }
    for(int i=0;i<n;i++)
        puts(st[i]);
}

//计算第一个单词数
int first_word(char * st)
{
    int i=0,n=0;
    while(!isalpha(st[i])) //不是字母的话，跳过
        i++;
    while(isalpha(st[i]))
    {//是字母，n+1
        i++;
        n++;
    }

    return n;
}

