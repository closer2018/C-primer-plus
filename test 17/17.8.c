/*8.修改宠物俱乐部程序，把所有同名的宠物都储存在同一个节点中。当
用户选择查找宠物时，程序应询问用户该宠物的名字，然后列出该名字的所
有宠物（及其种类）。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "17.8.h"
#include "17.8pet.c"

char get_choice(void);
char * s_gets(char * st, int n);
void addpet(Tree * pt);
void printpet(Item temp);
void findpet(const Tree * pt);
void droppet(Tree * pt);
void showpet(const Tree * pt);

int main(void)
{
	Tree pet;
	char ch;

	InitializeTree(&pet);
	while ((ch = get_choice()) != 'q')
	{
		switch (ch)
		{
		case 'a': addpet(&pet);
			break;
		case 'l': showpet(&pet);
			break;
		case 'f': findpet(&pet);
			break;
		case 'n': printf("%d 个宠物在俱乐部内.\n",
			TreeItemCount(&pet));
			break;
		case 'd': droppet(&pet);
			break;
		default: puts("切换错误");
		}
		printf("\n");
	}

	DeleteAll(&pet);
	printf("再见.\n");

	return 0;
}

char get_choice(void)
{
	char ch;

	puts("宠物俱乐部欢迎你");
	puts("输入与您的选择相对应的字母:");
	puts("a) 添加一个宠物\t\t\t  l) 显示宠物列表");
	puts("n) 宠物数量    \t\t\t  f) 寻找宠物");
	puts("d) 删除一个宠物 \t\t  q) 离开");

	ch = getchar();
	while (strchr("alnfdq", tolower(ch)) == NULL)
	{
		while (getchar() != '\n')
			continue;
		printf("请输入 a, l, n, f, d 或者 q.\n");
		ch = getchar();
	}
	while (getchar() != '\n')
		continue;

	return ch;
}

void showpet(const Tree * pt)
{
	if (TreeIsEmpty(pt))
		printf("俱乐部内没有宠物.\n");
	else
		Traverse(pt, printpet);
}

void findpet(const Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
		puts("俱乐部内没有宠物.\n");
	else
	{
		printf("输入宠物名字:\n");
		s_gets(temp.name, LEN);
		FindItem(pt, &temp);
	}
}

void addpet(Tree * pt)
{
	Item temp;

	if (TreeIsFull(pt))
		puts("俱乐部没房间了.\n");
	else
	{
		printf("输入宠物名字:\n");
		s_gets(temp.name, LEN);
		printf("输入宠物种类:\n");
		s_gets(temp.kind[0], LEN);
		temp.num = 1;
		AddItem(pt, &temp);
	}
}

void droppet(Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("没有条目.\n");
		return;
	}

	printf("输入宠物名字:\n");
	s_gets(temp.name, LEN);
	if (DelItem(pt, &temp) == 0)
	{
		printf("找不到你的宠物.\n");
	}
}

void printpet(Item temp)
{
	int i;

	printf("名字: %s\t\t种类: ", temp.name);
	for (i = 0; i < temp.num; i++)
		printf("%s ", temp.kind[i]);
	printf("\n");
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}