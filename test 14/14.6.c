/*6.一个文本文件中保存着一个垒球队的信息。每行数据都是这样排列：
4 Jessie Joybat 5 2 1 1
第1项是球员号，为方便起见，其范围是0～18。第2项是球员的名。第3
项是球员的姓。名和姓都是一个单词。第4项是官方统计的球员上场次数。
接着3项分别是击中数、走垒数和打点（RBI）。文件可能包含多场比赛的
数据，所以同一位球员可能有多行数据，而且同一位球员的多行数据之间可
能有其他球员的数据。编写一个程序，把数据储存到一个结构数组中。该结
构中的成员要分别表示球员的名、姓、上场次数、击中数、走垒数、打点和
安打率（稍后计算）。可以使用球员号作为数组的索引。该程序要读到文件
结尾，并统计每位球员的各项累计总和。
世界棒球统计与之相关。例如，一次走垒和触垒中的失误不计入上场次
数，但是可能产生一个RBI。但是该程序要做的是像下面描述的一样读取和
处理数据文件，不会关心数据的实际含义。
要实现这些功能，最简单的方法是把结构的内容都初始化为零，把文件
中的数据读入临时变量中，然后将其加入相应的结构中。程序读完文件后，
应计算每位球员的安打率，并把计算结果储存到结构的相应成员中。计算安
打率是用球员的累计击中数除以上场累计次数。这是一个浮点数计算。最
后，程序结合整个球队的统计数据，一行显示一位球员的累计数据。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20      //字符长度
#define SIZE 20     //球员个数

struct player{
    int num; //球员号
    char first_name[LEN];
    char last_name[LEN];
    int action;//上场次数
    int hit;//击中数
    int walk;//走垒数
    int rbi;//打点
    float average;//安打率
};
void a_get_zero(struct player *man,int n);//数据变0
void b_get_data(struct player *man,int n);//获取数据
void c_print(struct player *man,int n);//打印

int main(void)
{
    static struct player players[SIZE];
    a_get_zero(players,SIZE);
    b_get_data(players,SIZE);
    c_print(players,SIZE);
    printf("再见.");

    return 0;
}

void a_get_zero(struct player *man,int n)
{
    for(int i=0;i<n;i++)//清零
        man[i]=(struct player){0,"","",0,0,0,0,0};
}

void b_get_data(struct player *man,int n)
{
    FILE *p;
    char name[LEN];
    int nu,ac,hi,wa,rb;
    char f_name[LEN],l_name[LEN];


    puts("输入你要打开的文件名：");
    gets(name);
    if(( p = fopen(name,"rb")) == NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    while( (fscanf(p,"%d%s%s%d%d%d%d",&nu,f_name,
                   l_name,&ac,&hi,&wa,&rb)) == 7)
    {//读取文件数据叠加存储到变量
        man[nu].num = nu;
        if(man[nu].first_name[0] =='\0')
        {
            strcpy(man[nu].first_name,f_name);
            strcpy(man[nu].last_name,l_name);
        }
        man[nu].action += ac;
        man[nu].hit += hi;
        man[nu].walk += wa;
        man[nu].rbi += rb;
    }
	if (fclose(p) != 0)
		fprintf(stderr,"关闭文件时发生错误.\n");
}

void c_print(struct player *man,int n)
{
    int i=0;
    int ac=0,hi=0,wa=0,rb=0;

    for(i=0;i<n;i++)
    {//计算安打率
        man[i].average=man[i].hit /(float)man[i].action;
    }
    printf("\n");
    printf("球员号\t名\t姓\t场次\t击中数\t走垒数"
            "\t打点\t安打率\n");
    for(i=0;i<n;i++)
    {
        if(man[i].first_name[0] !='\0')
            {
            printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%.3g\n",
                   man[i].num,man[i].first_name,man[i].last_name,
                   man[i].action,man[i].hit,man[i].walk,man[i].rbi,
                   man[i].average);
            }
           ac +=man[i].action;
           hi +=man[i].hit;
           wa +=man[i].walk;
           rb +=man[i].rbi;
    }
    printf("\n");
    printf("总计: 场次 %d\t击中数 %d\t走垒数 %d\t打点 %d\t平均安打率 %.3g\n",
            ac,hi,wa,rb,hi/(float)ac);
}

