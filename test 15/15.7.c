/*7.编写一个与编程练习 6 功能相同的程序，使用 unsigned long 类型的变
量储存字体信息，并且使用按位运算符而不是位成员来管理这些信息。*/

#include <stdio.h>
#include <string.h>

#define ID_MASK 0xff
//括号缺失会出错
#define SIZE_MASK (0x7f << 8)
#define ALIGN_MASK (0x3 << 15)

#define CENTER (0x1 << 15)
#define RIGHT (0x2 << 15)
#define BOLD (0x1 << 17)
#define ITALIC (0x1 << 18)

const char *align[3]={"左","中","右"};
const char *open[2]={"关","开"};

char get_choice(void);
char get_select(void);
void print(unsigned long);

int main(void)
{
    unsigned long type=0;
    char choice;
    char ch;
    int num;

    print(type);
    while ((choice=get_choice())!='q')
    {
        switch (choice)
        {
        case 'f': printf("改变字体 (0 - 255): ");
                  scanf("%lu", &num);
                  getchar();
                  type&=~ID_MASK;		//把表示字体ID的位清空
                  type|=num;			//重置字体ID
                  break;
        case 's': printf("改变大小 (0 - 127): ");
                  scanf("%lu", &num);
                  getchar();
                  type&=~SIZE_MASK;
                  type|=(num << 8);
                  break;
        case 'a': type&=~ALIGN_MASK;
                  printf("选择对齐方式:\n");
                  printf("l)左   c)中   r)右\n");
                  if ((ch=get_select())=='c')
                      type|=CENTER;
                  else if (ch=='r')
                      type|=RIGHT;
                      break;
        case 'b': type^=BOLD;
                  break;
        case 'i': type^=ITALIC;
                  break;
        default : break;
        }
        print(type);
    }
    printf("再见.\n");

    return 0;
}

char get_choice(void)
{
    char ch;

    printf("f)改变字体\ts)改变大小\ta)改变对齐方式\n");
    printf("b)切换粗体\ti)切换斜体\nq)离开\n");

    while (strchr("fsabiq", ch=getchar())==NULL)
    {
        while (getchar()!='\n')
            continue;
        printf("请输入正确的字母.\n");
    }
    while (getchar()!='\n') continue;

    return ch;
}

char get_select(void)
{
    char ch;

    while (strchr("lcr", ch=getchar())==NULL)
    {
        while (getchar()!='\n')
            continue;
        printf("请输入正确的字母.\n");
    }
    while (getchar()!='\n') continue;

    return ch;
}

void print(unsigned long num)
{
    printf("\n 字体 大小   对齐方式    粗    斜\n");
    printf("%3u", num & ID_MASK);
    printf("%6u", (num & SIZE_MASK) >> 8);
    printf("%10s", align[(num & ALIGN_MASK) >> 15]);
    printf("%8s", open[(num & BOLD) >> 17]);
    printf("%6s\n\n", open[(num & ITALIC) >> 18]);
}
