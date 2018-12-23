/* 1.修改程序清单17.2，让该程序既能正序也能逆序显示电影列表。一种
方法是修改链表的定义，可以双向遍历链表。另一种方法是用递归。*/
#include <stdio.h>
#include <stdlib.h>    /* 提供malloc()原型 */
#include <string.h>    /* 提供strcpy()原型 */
#define TSIZE 45    /* 储存片名的数组大小 */

typedef struct film {
    char title[TSIZE];
    int rating;
    struct film * next;  /* 指向链表中的下一个结构 */
    struct film *prev; //指向上一个结构
}Node;

char * s_gets(char * st, int n);

int main(void)
{
    Node * head = NULL;//头指针
    Node *pre =NULL;//上一个节点
    Node *end;//尾节点
    Node *current;//当前节点
    char input[TSIZE];

    /* 收集并储存信息 */
    puts("输入第一个电影名:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)   /* 第1个结构 */
            head = current;
        else         /* 后续的结构 */
            pre->next = current;//上个节点的next指针指向当前节点
        current->prev=pre;//当前节点的prev指针指向上一个节点
        current->next = NULL;//当前节点指向空指针，表示结尾
        strcpy(current->title, input);
        puts("输入评级(0-10):");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("下一个电影名 (输入空行结束):");
        pre = current;//当前节点变为上一个节点，循环下去
    }
    end=pre;//end指向最后一个节点

    if (head == NULL)
        printf("没有输入. ");
    else
        printf("电影列表如下:\n");
    // 正序显示电影列表
    current = head;
    while (current != NULL)
    {
        printf("电影: %s 评级: %d\n",
                current->title, current->rating);
        current = current->next;
    }
    //逆序显示电影列表
    puts("\n现在是逆序显示电影列表。");
    current=end;//从末尾开始
    while(current !=NULL)
    {
        printf("电影: %s  评级: %d\n",
                current->title,current->rating);
        current=current->prev;
    }

    /* 完成任务，释放已分配的内存 */
    current = head;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    }
    printf("再见!\n");

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
        if (find)        // 如果地址不是 NULL，
            *find = '\0';     // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;   // 处理剩余输入行
    }
    return ret_val;
}
