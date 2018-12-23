#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h> /* C99特性      */
/* 特定程序的声明 */
#include <string.h>
#define TSIZE  45 /* 储存电影名的数组大小 */
#define MAXSIZE 100

typedef struct film{
    char title[TSIZE];
    int rating;
}Item;

typedef struct list{
    Item entries[MAXSIZE];//内含项的数组
    int  items; //list中的项数
}List;

//初始化链表为空
void InitializeList(List * plist);

//链表为空,返回ture
bool ListIsEmpty(const List *plist);

//链表为满，返回true
bool ListIsFull(const List *plist);

//确定链表中的项数, plist指向一个已初始化的链表
unsigned int ListItemCount(const List *plist);

//为链表添加项，成功返回ture
bool AddItem(Item item, List * plist);

//把函数作用于链表中的每一项,遍历列表
void Traverse(const List *plist, void(*pfun)(Item item));

//清空链表
void DeleteAll(List * plist);
#endif
