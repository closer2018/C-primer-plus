#include <stdio.h>
#include <stdlib.h>
#include "17.3.h"


/* 接口函数 */
/* 把链表设置为空 */
void InitializeList(List * plist)
{
    for(int i=0;i<MAXSIZE;i++)
    {
        strcpy(plist->entries[i].title,"");
        plist->entries[i].rating=0;
        plist->items=0;
    }
}
/* 如果链表为空，返回true */
bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}
/* 如果链表已满，返回true */
bool ListIsFull(const List * plist)
{
    if (plist->items == MAXSIZE)
        return true;
    else
        return false;
}
/* 返回节点的数量 */
unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}
/* 创建储存项的节点，并将其添加至由plist指向的链表末尾（较慢的实现） */
bool AddItem(Item item, List * plist)
{
    if (plist->items == MAXSIZE)
    {
        fprintf(stderr,"满了.\n");
        return false;  /* 失败时退出函数 */
    }
    plist->entries[plist->items] =item;
    (plist->items)++;

    return true;
}
/* 访问每个节点并执行pfun指向的函数 */
void Traverse(const List * plist, void(*pfun)(Item item))
{
    for(int i=0;i<plist->items;i++)
    {
        (*pfun)(plist->entries[i]); /* 把函数应用于链表中的项 */
    }
}
/* 释放由malloc()分配的内存 *//* 设置链表指针为NULL   */
void DeleteAll(List * plist)
{
    for(int i=0;i<plist->items;i++)
    {
        strcpy(plist->entries[i].title,"");
        plist->entries[i].rating=0;
        plist->items=0;
    }
}
