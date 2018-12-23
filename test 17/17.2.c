/*2.假设list.h（程序清单17.3）使用下面的list定义：
typedef struct list
{
    Node * head;    // 指向list的开头
    Node * end;     //指向list的末尾
} List;
重写 list.c（程序清单 17.5）中的函数以适应新的定义，并通过
films.c（程序清单 17.4）测试最终的代码。*/
#include <stdio.h>
#include <stdlib.h> /* 提供exit()的原型 */
#include "17.2.h"  /* 定义List、Item */
#include "17.2list.c"

void showmovies(Item item);
char * s_gets(char * st, int n);

int main(void)
{
    List movies;
    Item temp;
    /* 初始化   */
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "没有存储空间。\n");
        exit(1);
    }
    /* 获取用户输入并储存 */
    puts("输入第一个电影名:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("输入评级 <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') continue;
        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "分配空间失败。\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("装满了.");
            break;
        }
        puts("输入下一个电影名 (空行结束):");
    }
    /* 显示数据*/
    if (ListIsEmpty(&movies))
        printf("没有输入数据. ");
    else
    {
        printf("电影清单如下:\n");
        Traverse(&movies, showmovies);
    }
    printf("你输入了 %d 部电影.\n", ListItemCount(&movies));
    /* 清理   */
    EmptyTheList(&movies);
    printf("Bye!\n");

    return 0;
}
void showmovies(Item item)
{
    printf("电影: %s 评级: %d\n", item.title,item.rating);
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
