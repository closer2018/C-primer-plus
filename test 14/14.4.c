/*4.编写一个程序，创建一个有两个成员的结构模板：
a.第1个成员是社会保险号，第2个成员是一个有3个成员的结构，第1个
成员代表名，第2个成员代表中间名，第3个成员表示姓。创建并初始化一个
内含5个该类型结构的数组。该程序以下面的格式打印数据：
Dribble, Flossie M.–– 302039823
如果有中间名，只打印它的第1个字母，后面加一个点（.）；如果没有
中间名，则不用打印点。编写一个程序进行打印，把结构数组传递给这个函
数。
b.修改a部分，传递结构的值而不是结构的地址。*/
#include <stdio.h>
#define SSN 20
#define LEN 10

struct names {
    char first_name[LEN];
    char mid_name[LEN];
    char last_name[LEN];
};

struct person {
    char num[SSN];
    struct names name;
};
void printa(struct person p[],int n);
void printb(struct person p);
int main (void)
{
    struct person people[5]={
        {"302039823",{"Dribble","Mindder","Flossie"}},
        {"123519823",{"asdw","uibdder","fhh"}},
        {"745689823",{"ksdv","","qwi"}},
        {"321356823",{"rsdv","mer","dgre"}},
        {"786354823",{"hbgv","","kco"}}
    };
    printa(people,5);

    for(int i=0;i<5;i++)
        printb(people[i]);

    printf("\n");
    return 0;
}
void printa(struct person p[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%s,%s %c%c -- %s\n",p[i].name.first_name,
               p[i].name.last_name,
               p[i].name.mid_name[0],
               (p[i].name.mid_name[0]=='\0')? '\0':'.',
               p[i].num);
    }
    printf("\n");
}

void printb(struct person p)
{
    printf("%s,%s %c%c -- %s\n",p.name.first_name,
               p.name.last_name,
               p.name.mid_name[0],
               (p.name.mid_name[0]=='\0')? '\0':'.',
               p.num);
}
