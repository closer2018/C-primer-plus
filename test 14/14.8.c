/*8.巨人航空公司的机群由 12 个座位的飞机组成。它每天飞行一个航
班。根据下面的要求，编写一个座位预订程序。
a.该程序使用一个内含 12 个结构的数组。每个结构中包括：一个成员
表示座位编号、一个成员表示座位是否已被预订、一个成员表示预订人的
名、一个成员表示预订人的姓。
b.该程序显示下面的菜单：
To choose a function, enter its letter label:
a) Show number of empty seats
b) Show list of empty seats
c) Show alphabetical list of seats
d) Assign a customer to a seat assignment
e) Delete a seat assignment
f) Quit
c.该程序能成功执行上面给出的菜单。选择d)和e)要提示用户进行额外
输入，每个选项都能让用户中止输入。
d.执行特定程序后，该程序再次显示菜单，除非用户选择f)。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 20
#define MAX 12     //最大座位数
struct plane{
    int num;
    int flag;//0代表没人，1代表有人
    char fname[LEN];
    char lname[LEN];
};

char * s_gets(char * st, int n);	    //输入字符串的函数
char get_choice(void);					//用户输入选择
void show_number(struct plane *se);		//空位置的个数
void show_empty(struct plane *se);		//打印所有空位置
void show_list(struct plane *se);		//打印所有位置信息
void assign_seat(struct plane *se);		//预订一个位置
void delete_seat(struct plane *se);		//删除一个位置
void write_file(struct plane *se,char *name);//数据写入文件

int main(void)
{
    struct plane seat[MAX];
    char ch;
    char name[LEN];
    FILE *fp;

    for(int i=0;i<MAX;i++)//初始化结构
        seat[i]=(struct plane){(i+1),0,"",""};

    //从文件读取
    puts("输入你要打开的文件名：");
    s_gets(name,LEN);
    if ((fp = fopen(name, "a+b")) == NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    fread(seat,sizeof(struct plane),MAX,fp);
    //选择清单
    while( (ch=get_choice()) != 'f')
    {
        switch(ch)
        {
        case 'a':show_number(seat);
                break;
        case 'b':show_empty(seat);
                break;
        case 'c':show_list(seat);
                break;
        case 'd':assign_seat(seat);
                break;
        case 'e':delete_seat(seat);
                break;
        default:puts("程序错误.");
            break;
        }
    }

    write_file(seat,name);//数据写入文件
    puts("再见.");

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
            while (getchar() != '\n')
                continue;   // 清理输入行
    }
    return ret_val;
}

char get_choice(void)
{
    char ch;

    puts("\nTo choose a function, enter its letter label(请选择):");
    printf("a) Show number of empty seats(显示空座数量)\n"
           "b) Show list of empty seats(显示空座名单)\n"
           "c) Show alphabetical list of seats(按顺序显示座位名单)\n"
           "d) Assign a customer to a seat assignment(预定座位)\n"
           "e) Delete a seat assignment(删除座位)\n"
           "f) Quit(离开)\n");
    while(( ch = (tolower(getchar())) ) != 'a' && ch != 'b' &&
          ch != 'c' && ch != 'd' && ch != 'e' && ch != 'f') //转小写字母
    {
        while(getchar() !='\n') continue;//清理输入行
        puts("请输入正确的字母.");
    }
    while(getchar() !='\n') continue;

    return ch;
}

void show_number(struct plane *se)//空位置的个数
{
    int i,count=0;

    for(i=0;i<MAX;i++)
    {
        if(se[i].flag == 0)
            count++;
    }
    printf("空位置的数量是%d.\n",count);
}

void show_empty(struct plane *se)//打印所有空位置
{
    int i;

    puts("空位置的号码如下:\n");
    for(i=0;i<MAX;i++)
    {
        if(se[i].flag==0)
            printf("%d ",se[i].num);
    }
    printf("\n");
}

void show_list(struct plane *se)//打印所有位置信息
{
    int i;

    puts("所有位置的清单如下：\n");
    for(i=0;i<MAX;i++)
    {
        printf("%d\t%s\t%s\n",se[i].num,se[i].fname,se[i].lname);
    }
}

void assign_seat(struct plane *se)//预订一个位置
{
    int nu;
    int temp;

    puts("输入你的要预定的座位号(1-MAX).");
    while(!((temp=scanf("%d",&nu)) == 1 && nu>=1 && nu<=MAX
            && se[nu-1].flag == 0))
    {
        while(getchar() != '\n') continue;
        if(temp !=1 || nu<1 || nu>MAX)
            printf("座位号错误,请输入1-MAX!\n");
        else
            printf("对不起,你的座位已经被预订了!请重新输入座位号.\n");
    }
    while(getchar() != '\n') continue;
    se[nu-1].flag=1; //预定座位
    puts("请输入你的姓：");
    s_gets(se[nu-1].fname,LEN);
    puts("请输入你的名：");
    s_gets(se[nu-1].lname,LEN);
    printf("预定成功.\n");
}

void delete_seat(struct plane *se)//删除一个座位
{
    int nu;

    puts("输入你的要删除的座位号(1-MAX).");
    while(!((scanf("%d",&nu)) == 1 && nu>=1 && nu<=MAX
            && se[nu-1].flag == 1))
    {
        while(getchar() != '\n') continue;
        if(se[nu-1].flag == 0)//空座位不能删除
            printf("对不起,此座位没人!请重新输入座位号.\n");
        else
            printf("座位号错误,请输入1-MAX!\n");
    }
    while(getchar() != '\n') continue;
    se[nu-1]=(struct plane){nu,0,"",""};//直接更改信息
    printf("删除成功！\n");
}

void write_file(struct plane *se,char *name)//数据写入文件
{
    FILE *p;

    p=fopen(name,"w+b");
    fwrite(se, sizeof(struct plane),MAX,p);
    fclose(p);
}
