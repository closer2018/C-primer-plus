/*6.修改程序清单16.17，使用struct names元素（在程序清单16.17后面的
讨论中定义过），而不是double类型的数组。使用较少的元素，并用选定的
名字显式初始化数组。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
#define NUM 7
struct names {
    char first[SIZE];
    char last[SIZE];
};

int comp(const void * p1, const void * p2);
int main(void)
{
    int i;
    struct names staff[NUM]={
        {"古","舔叻"},
        {"张","渣辉"},
        {"张","白汁"},
        {"陈","笑春"},
        {"周","认罚"},
        {"谢","挺峰"},
        {"流","德化"}
    };
    puts("原数组是：");
    for(i=0;i<NUM;i++)
        printf("%s%s\n",staff[i].first,staff[i].last);
    qsort(staff, NUM, sizeof(struct names),comp);
    puts("\n排序后是：");
    for(i=0;i<NUM;i++)
        printf("%s%s\n",staff[i].first,staff[i].last);


    puts("\n再见.");

    return 0;
}

/* 按从小到大的顺序排序 */
int comp(const void * p1, const void * p2)
{
/* 要使用指针来访问这两个值 */
    const struct names *a1 = (const struct names *)p1;
    const struct names *a2 = (const struct names *)p2;
    int temp=strcmp(a1->first,a2->first);

    return temp? temp : strcmp(a1->last,a2->last) ;
}
