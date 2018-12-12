/*3.修改程序清单 14.2 中的图书目录程序，使其按照输入图书的顺序输出
图书的信息，然后按照标题字母的声明输出图书的信息，最后按照价格的升
序输出图书的信息*/
#include <stdio.h>
#include <string.h>//提供strcmp()
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100     // 最大书籍数量
struct book {       // 建立 book 模板
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
char * s_gets(char * st, int n);
void sort_by_input(const struct book library[] ,int n);
void sort_by_title(struct book library[] ,int n);
void sort_by_price(struct book library[] ,int n);

int main(void)
{
    static struct book library[MAXBKS]; // 结构数组
    int count = 0;
    int index;

    puts("请输入新的书本标题(输入[enter] 结束程序).");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        puts("现在输入作者.");
        s_gets(library[count].author, MAXAUTL);
        puts("现在输入价格.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;    // 清理输入行
        if (count < MAXBKS)
            puts("输入下一个标题.");
    }
    if (count > 0)
    {
        puts("按输入顺序排序,书本清单如下:");
        sort_by_input(library,count);

        puts("按标题顺序排序,书本清单如下:");
        sort_by_title(library,count);

        puts("按价格大小排序,书本清单如下:");
        sort_by_price(library,count);
    }
    else
        puts("没有新的书本？好吧！.\n");
    puts("再见.\n");

    return 0;
}

char * s_gets(char * st, int n)
{

    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)       // 如果地址不是 NULL，
            *find = '\0';    // 在此处放置一个空字符
        else
            while (getchar() != '\n') continue;   // 清理输入行
    }

    return ret_val;
}

void sort_by_input(const struct book library[] ,int n)
{
    for (int index = 0; index < n; index++)
        printf("%s by %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);
   printf("\n");
}

void sort_by_title(struct book library[] ,int n)
{
    struct book temp;
    int i, j;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(strcmp(library[i].title,library[j].title) > 0)
            {//冒泡排序
                temp=library[j];
                library[j]=library[i];
                library[i]=temp;
            }
    for (int index = 0; index < n; index++)
        printf("%s by %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);
   printf("\n");
}

void sort_by_price(struct book library[] ,int n)
{
    struct book temp;
    int i, j;

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(library[i].value>library[j].value)
            {//冒泡排序
                temp=library[j];
                library[j]=library[i];
                library[i]=temp;
            }
    for (int index = 0; index < n; index++)
        printf("%s by %s: $%.2f\n", library[index].title,
               library[index].author, library[index].value);
   printf("\n");
}

