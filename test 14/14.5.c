/*5.编写一个程序满足下面的要求。

a.外部定义一个有两个成员的结构模板name：一个字符串储存名，一个
字符串储存姓。
b.外部定义一个有3个成员的结构模板student：一个name类型的结构，
一个grade数组储存3个浮点型分数，一个变量储存3个分数平均数。
c.在main()函数中声明一个内含CSIZE（CSIZE = 4）个student类型结构的
数组，并初始化这些结构的名字部分。用函数执行d、e、f和g中描述的任
务。
d.以交互的方式获取每个学生的成绩，提示用户输入学生的姓名和分
数。把分数储存到grade数组相应的结构中。可以在main()函数或其他函数中
用循环来完成。
e.计算每个结构的平均分，并把计算后的值赋给合适的成员。
f.打印每个结构的信息。
g.打印班级的平均分，即所有结构的数值成员的平均值。*/

#include <stdio.h>
#include <math.h>
#define LEN 10
#define CSIZE 4
#define NUM 3

struct name{
    char first_name[LEN];
    char second_name[LEN];
};
struct student{
    struct name names;
    float grade[NUM];
    float average;
};
void d_get_score(struct student stus[],int n);
void e_average(struct student stus[],int n);
void f_print(struct student stus[],int n);
void g_all_aver(struct student stus[],int n);

int main(void)
{
    struct student stus[CSIZE]={
                        {.names={"辰","小春"}},
                        {.names={"渣","渣辉"}},
                        {{"房","事龙"},{0,0,0},0},
                        {{"古","舔叻"},{0,0,0},0}
                            };
    d_get_score(stus,CSIZE);
    e_average(stus,CSIZE);
    f_print(stus,CSIZE);
    g_all_aver(stus,CSIZE);

    return 0;
}

void d_get_score(struct student stus[],int n)
{
    int i,j;

    for(i=0,j=0;i<n;i++)
    {
        for(j=0;j<NUM;j++)
        {
            printf("输入%s%s的第%d个成绩：\n",stus[i].names.first_name,
                   stus[i].names.second_name,j+1);
            while(scanf("%f",&stus[i].grade[j]) !=1)
                while(getchar() !='\n') continue;//清理输入行
            while(getchar() !='\n') continue;//清理输入行
        }
    }
    puts("");
}

void e_average(struct student stus[],int n)
{
    float tol;
    int i,j;

    for(i=0;i<n;i++)
    {
        tol=0;
        for(j=0;j<NUM;j++)
        {
            tol+=stus[i].grade[j];
        }
        stus[i].average=tol/j;
    }
}

void f_print(struct student stus[],int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        printf("%s%s的%d门成绩分别是",stus[i].names.first_name,
               stus[i].names.second_name,NUM);
        for(j=0;j<NUM;j++)
        {
            printf(" %g",stus[i].grade[j]);
        }
        printf(",平均分是%.2f.\n",stus[i].average);
    }
}

void g_all_aver(struct student stus[],int n)
{
    float tol=0;
    float aver;
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<NUM;j++)
        {
            tol+=stus[i].grade[j];
        }
    }
    aver=tol/(i*j);
    printf("班级平均分是%.2f.\n",aver);
}

