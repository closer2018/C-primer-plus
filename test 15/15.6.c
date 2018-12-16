/*6.设计一个位字段结构以储存下面的信息。
字体ID：0～255之间的一个数；
字体大小：0～127之间的一个数；
对齐：0～2之间的一个数，表示左对齐、居中、右对齐；
加粗：开（1）或闭（0）；
斜体：开（1）或闭（0）；
在一个程序中使用该结构来打印字体参数，并使用循环菜单来让用户改
变参数。例如，该程序的一个运行示例如下：
ID SIZE ALIGNMENT  B   I   U
1  12   left      off off off

f)change fonts	s)change size 	 a)change alignment
b)toggle bold 	i)toggle italic  u)toggle underline
q)quit
s
Enter font size (0-127): 36
ID SIZE ALIGNMENT  B   I   U
1  36   left      off off off
该程序要使用按位与运算符（&）和合适的掩码来把字体ID和字体大小
信息转换到指定的范围内。*/

#include <stdio.h>
#include <string.h>

struct word {
    unsigned int font: 8;
    unsigned int size: 7;
    unsigned int alignment: 2;
    unsigned int bold: 1;
    unsigned int italic: 1;
};

const char *align[3]={"左","中","右"};
const char *open[2]={"关","开"};

char get_choice(void);
char get_select(void);
void print(struct word *);

int main(void)
{
    struct word type={1,12,0,0,0};
    char choice;
    char ch;
    int num;

    print(&type);
    while ((choice=get_choice())!='q')
    {
        switch (choice)
        {
        case 'f': printf("改变字体 (0 - 255): ");
                  scanf("%u",&num);
                  getchar();
                  type.font=num;
                  break;
        case 's': printf("改变大小 (0 - 127): ");
                  scanf("%u",&num);
                  getchar();
                  type.size=num;
                  break;
        case 'a': printf("选择对齐方式:\n");
                  printf("l)左   c)中   r)右\n");
                  if ((ch=get_select())=='l')
                      type.alignment=0;
                  else if (ch=='c')
                      type.alignment=1;
                  else
                      type.alignment=2;
                  break;
        case 'b': type.bold=!type.bold;
                  break;
        case 'i': type.italic=!type.italic;
                  break;
        default : break;
        }
        print(&type);
    }
    printf("再见.\n");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("f)改变字体\ts)改变大小\ta)改变对齐方式\n");
    printf("b)切换粗体\ti)切换斜体\nq)离开\n");

    while(strchr("fsabiq",ch=getchar())==NULL)
    {
        while (getchar()!='\n') continue;
        printf("请输入正确的字母.\n");
    }
    while(getchar()!='\n') continue;

    return ch;
}

char get_select(void)
{
    char ch;

    while(strchr("lcr", ch=getchar())==NULL)
    {
        while (getchar()!='\n') continue;
        printf("请输入正确的字母.\n");
    }
    while(getchar()!='\n')
        continue;

    return ch;
}

void print(struct word * pst)
{
    printf("\n 字体 大小   对齐方式    粗    斜\n");
    printf("%3u", pst->font);
    printf("%6u", pst->size);
    printf("%10s", align[pst->alignment]);
    printf("%8s", open[pst->bold]);
    printf("%6s\n\n", open[pst->italic]);
}
