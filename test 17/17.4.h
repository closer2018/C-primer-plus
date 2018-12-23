#ifndef _17_4_H_
#define _17_4_H_
#include <stdbool.h>
#define MAXQUEUE 10

// 在这里插入Item类型的定义，例如
typedef struct item
{
    long arrive;   /* 一位顾客加入队列的时间 */
    int processtime; /* 该顾客咨询时花费的时间 */
}Item;

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef struct queue
{
    Node * front;
    Node * rear;
    int items;  /* 队列中的项数    */
} Queue;

//初始化队列
void InitializeQueue(Queue * pq);

//检查队列是否已满
bool QueueIsFull(const Queue * pq);

//检查队列是否为空
bool QueueIsEmpty(const Queue *pq);

// 确定队列中的项数
int QueueItemCount(const Queue * pq);

//在队列末尾添加项
bool EnQueue(Item item, Queue * pq);

//从队列的开头删除项
bool DeQueue(Item *pitem, Queue * pq);

//清空队列
void EmptyTheQueue(Queue * pq);
#endif // _17_4_H_
