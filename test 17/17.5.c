/*5.编写一个程序，提示用户输入一个字符串。然后该程序把该字符串的
字符逐个压入一个栈（参见复习题5），然后从栈中弹出这些字符，并显示
它们。结果显示为该字符串的逆序。*/

#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 40

/*头文件开始*/
#define SMAX 100
typedef char Item;

typedef struct stack{
    Item item[SMAX];
    int items;
}Stack;

//初始化栈
void InitializeStack(Stack * ps);

//确定栈为空
int StackIsEmpty(const Stack * ps);

//确定栈为满
int StackIsFull(const Stack * ps);

//统计栈内项数
int StackItemCount(const Stack * ps);

//从栈顶压入项
int AddItem(Stack * ps, Item item);

//从栈顶弹出项
int DelItem(Stack * ps, Item * pitem);

//清空项
void EmptyItem(Stack * ps);

/*头文件结束*/


/*主函数开始*/
char * s_gets(char * st, int n);

int main()
{
    Stack stack;
    Item temp[SIZE];
    Item ch;
    int i;

    InitializeStack(&stack);
    //用户数据压入栈中
    printf("输入字符串:\n");
    while(s_gets(temp,SIZE)!=NULL && temp[0]!='\0')
    {
        for(i=0;temp[i] != '\0';i++)
        {
            if (AddItem(&stack,temp[i]) == 0)
                break;
        }
        if(StackIsFull(&stack))
        {
            fprintf(stderr,"栈满了.\n");
            break;
        }
        printf("输入下一个字符串(空行结束):\n");
    }
    //从栈中弹出数据并输出
    if(StackIsEmpty(&stack))
    {
        fprintf(stderr, "没有数据.\n");
        exit(1);
    }

    printf("你输入了 %d 个字符.\n",StackItemCount(&stack));
    printf("倒序字符串输入如下:\n");
    while(!StackIsEmpty(&stack))
    {
        DelItem(&stack,&ch);
        putchar(ch);
    }
    printf("\nBye.\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');  // 查找换行符
        if (find)           // 如果地址不是NULL，
            *find = '\0';     // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;      // 处理输入行的剩余内容
    }
    return ret_val;
}
/*主函数结束*/


/*函数定义开始*/
//初始化栈
void InitializeStack(Stack * ps)
{
    ps->items=0;
}

//确定栈为空
int StackIsEmpty(const Stack * ps)
{
    if(ps->items==0)
        return 1;
    else
        return 0;
}

//确定栈为满
int StackIsFull(const Stack * ps)
{
    return (ps->items==SMAX) ? 1:0;
}

//统计栈内项数
int StackItemCount(const Stack * ps)
{
    return ps->items;
}

//从栈顶压入项
int AddItem(Stack * ps, Item item)
{
    if(StackIsFull(ps))
        return 0;
    else
    {
        ps->item[ps->items]=item;
        ps->items++;
        return 1;
    }
}

//从栈顶弹出项
int DelItem(Stack * ps, Item * pitem)
{
    if (StackIsEmpty(ps))
        return 0;
    else
    {
        *pitem=ps->item[ps->items-1];
        EmptyItem(ps);
        ps->items--;
        return 1;
    }
}

//清空项
void EmptyItem(Stack * ps)
{
    ps->item[ps->items-1]='\0';
}

/*函数定义结束*/
