/*7.编写一个程序，打开和读取一个文本文件，并统计文件中每个单词出
现的次数。用改进的二叉查找树储存单词及其出现的次数。程序在读入文件
后，会提供一个有3个选项的菜单。第1个选项是列出所有的单词和出现的次
数。第2个选项是让用户输入一个单词，程序报告该单词在文件中出现的次
数。第3个选项是退出。*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "17.7.h"
#include "17.7word.c"

#define LEN 10000
#define SIZE 10000

char get_choice(void);
char * s_gets(char * st, int n);
void count_word(Tree * pt, Item * item);
void print_word(Item temp);

int main(void)
{
	Tree words;
	Item temp;
	FILE * fp;
	char ch;
	char name[LEN];
	char word[SIZE];

	//打开文件
	printf("请输入文件名:\n");
	s_gets(name, LEN);
	if ((fp = fopen(name, "r")) == NULL)
	{//请将文件和.c源码放一起
		fprintf(stderr, "不能打开%s文件.\n", name);
		exit(1);
	}

	//从文件读取单词
	InitializeTree(&words);
	while (fscanf(fp, "%s", word) == 1)
	{
		strcpy(temp.word, word);
		temp.num = 1;
		AddItem(&words, &temp);
		if (TreeIsFull(&words))
		{
			fprintf(stderr, "二叉树满了.\n");
			break;
		}
	}
	fclose(fp);

	while ((ch = get_choice()) != 'q')
	{
		if (ch == 'a')
		{
			if (TreeIsEmpty(&words))
				printf("文件内没有单词.\n");
			else
				Traverse(&words, print_word);
		}
		else
			count_word(&words, &temp);
	}

	DeleteAll(&words);
	printf("再见.\n");

	return 0;
}

char get_choice(void)
{
	char ch;

	printf("\na. 显示单词列表\n");
	printf("b. 找寻一个单词\n");
	printf("q. 离开\n");

	ch = getchar();
	while (strchr("abq", tolower(ch)) == NULL)
	{
		while (getchar() != '\n')
			continue;
		printf("请输入a , b 或 q .\n");
		ch = getchar();
	}
	while (getchar() != '\n')
		continue;

	return ch;
}

void print_word(Item temp)
{
	printf("单词: %s\t\t\t有: %-5d个\n", temp.word, temp.num);
}

void count_word(Tree * pt, Item * item)
{
	int count;

	printf("输入你想搜索的单词:\n");
	s_gets(item->word, SIZE);
	item->num = 1;
	count = ItemCount(pt, item);
	if (!count)
		printf("找不到这个单词.\n");
	else
		printf("有: %d个\n", ItemCount(pt, item));
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