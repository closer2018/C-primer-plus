#pragma once

#define LEN 10000
#define MAX 10000

typedef struct item {
	char word[LEN];
	int num;
} Item;

typedef struct trnode {
	Item item;
	struct trnode * left;
	struct trnode * right;
} Trnode;

typedef struct tree {
	Trnode * root;
	int size;
} Tree;

//初始化树
static void InitializeTree(Tree * ptree);

//确认树为满
static int TreeIsFull(const Tree * ptree);

//确认树为空
static int TreeIsEmpty(const Tree * ptree);

//统计项数
static int TreeItemCount(const Tree * ptree);

//查找项
static int InTree(const Tree * ptree, const Item * pi);

//添加项
static int AddItem(Tree * ptree, const Item * pi);

//删除项
static int DelItem(Tree * ptree, const Item * pi);

//遍历树
static void Traverse(const Tree * ptree, void(*pfun)(Item item));

//清空树
static void DeleteAll(Tree * ptree);

//对某一项计数
static int ItemCount(const Tree * ptree, const Item * item);
