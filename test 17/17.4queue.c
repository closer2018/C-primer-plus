/* queue.c -- Queue类型的实现 */
#include <stdio.h>
#include <stdlib.h>
#include "17.4.h"

/* 局部函数 */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

//初始化队列
void InitializeQueue(Queue * pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

bool QueueIsFull(const Queue * pq)
{
    if(pq->items == MAXQUEUE)
        return true;
    else
        return false;
}

bool QueueIsEmpty(const Queue * pq)
{
    if(pq->items == 0)
        return true;
    else
        return false;
}

int QueueItemCount(const Queue * pq)
{
    return pq->items;
}

bool EnQueue(Item item, Queue * pq)
{
    Node * pnew;//1)创建一个新节点；

    if (QueueIsFull(pq))
        return false;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "分配失败!\n");
        exit(1);
    }
    CopyToNode(item, pnew);//2)把项拷贝到节点中
    pnew->next = NULL;//3)设置节点的next指针为NULL，表明该节点是最后一个节点；
    if (QueueIsEmpty(pq))
        pq->front = pnew;     /* 项位于队列的首端   */
    else//4)设置当前尾节点的next指针指向新节点，把新节点链接到队列中；
        pq->rear->next = pnew;  /* 链接到队列的尾端   */
    pq->rear = pnew;//5)把rear指针指向新节点，以便找到最后的节点；
    pq->items++; //6)项数加1。

    return true;
}

bool DeQueue(Item * pitem, Queue * pq)
{
    Node * pt;

    if (QueueIsEmpty(pq))
    {
        fprintf(stderr,"没有可删除的.\n");
        return false;
    }

    CopyToItem(pq->front, pitem);//1)把项拷贝到给定的变量中；
    pt = pq->front;
    pq->front = pq->front->next;//3)重置首指针指向队列中的下一个项；
    free(pt);//2)释放空出的节点使用的内存空间；
    pq->items--;//5)项数减1。

    if (pq->items == 0)
        pq->rear = NULL;//4)如果删除最后一项，把尾指针都重置为NULL；

    return true;
}

/* 清空队列 */
void EmptyTheQueue(Queue * pq)
{
    Item dummy;

    while (!QueueIsEmpty(pq))
        DeQueue(&dummy, pq);
}

/* 局部函数 */
static void CopyToNode(Item item, Node * pn)
{
    pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi)
{
    *pi = pn->item;
}
