/*9.编写一个符合以下描述的函数。首先，询问用户需要输入多少个单
词。然后，接收用户输入的单词，并显示出来，使用malloc()并回答第1个问
题（即要输入多少个单词），创建一个动态数组，该数组内含相应的指向
char的指针（注意，由于数组的每个元素都是指向char的指针，所以用于储
存malloc()返回值的指针应该是一个指向指针的指针，且它所指向的指针指
向char）。在读取字符串时，该程序应该把单词读入一个临时的char数组，
使用malloc()分配足够的存储空间来储存单词，并把地址存入该指针数组
（该数组中每个元素都是指向 char 的指针）。然后，从临时数组中把单词
拷贝到动态分配的存储空间中。因此，有一个字符指针数组，每个指针都指
向一个对象，该对象的大小正好能容纳被储存的特定单词。下面是该程序的
一个运行示例：
How many words do you wish to enter? 5
Enter 5 words now:
I enjoyed doing this exerise
Here are your words:
I
enjoyed
doing
this
exercise*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 40
char * * mal_ar(int n);

int main(void)
{
    int words, i;
    char * * st;

    printf("你想输入几个单词? ");
    scanf("%d", &words);
    while((getchar()) != '\n')
        continue;       //滤掉回车
    printf("现在输入%d个单词:\n", words);
    st = mal_ar(words);
    printf("你输入的单词如下:\n");
    for (i = 0; i < words; i++)
    {
        puts(st[i]);
        free(st[i]);	//释放每个指针指向的内存
    }
    free(st);			//释放指针数组

    return 0;
}

char * * mal_ar(int n)
{
    char * * pt;
    int i, j;
    char ch;

    //给n个指针分配动态内存空间，返回指针的指针
    pt = (char * *)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {   //给每个指针指向的地址分配内存空间
        pt[i] = (char *)malloc(SIZE * sizeof(char));
        //可以仅用scanf("%s", pt[i]);
        while (isspace(ch = getchar()))				//处理单词之前的空格符
            continue;
        pt[i][0] = ch;								//单词首字符
        j = 1;
        while (!isspace(pt[i][j] = getchar()))
            j++;
        pt[i][j] = '\0';							//将末尾的空格替换为\0'
    }

    return pt;
}

