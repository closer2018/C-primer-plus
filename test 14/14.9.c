/*9.巨人航空公司（编程练习 8）需要另一架飞机（容量相同），每天飞
4 班（航班 102、311、444 和519）。把程序扩展为可以处理4个航班。用一
个顶层菜单提供航班选择和退出。选择一个特定航班，就会出现和编程练习
8类似的菜单。但是该菜单要添加一个新选项：确认座位分配。而且，菜单
中的退出是返回顶层菜单。每次显示都要指明当前正在处理的航班号。另
外，座位分配显示要指明确认状态。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 20
#define MAX 12      //最大座位数
#define FL 5        //航班号字符串长度
#define F_N 4       //每天飞几班

int status;//全局变量，标记确认情况

struct plane{
    int num;
    int flag;//0代表没人，1代表有人
    char fname[LEN];
    char lname[LEN];
};
struct flights{//多个航班
    char flight_num[FL];//航班号
    struct plane seats[MAX];
};

void read_file(struct flights *se,char *name);        //读取文件
char * s_gets(char * st, int n);	    //输入字符串的函数
char get_choice(struct flights *se,int n);					//用户输入选择
void show_number(struct flights *se,int n);		//空位置的个数
void show_empty(struct flights *se,int n);		//打印所有空位置
void show_list(struct flights *se,int n);		//打印所有位置信息
void assign_seat(struct flights *se,int n);		//预订一个位置
void delete_seat(struct flights *se,int n);		//删除一个位置
int get_flight(struct flights *se);                  //选择航班
void confirm_seat(void);                //确认座位
void choose_seat_menu(struct flights *se,int n) ;          //座位菜单选择
void choose_flight_menu(struct flights *se);        //航班菜单选择
void write_file(struct flights *se,char *name);       //数据写入文件

int main(void)
{
    struct flights se[F_N];
    char name[LEN];

    read_file(se,name);//读取

    choose_flight_menu(se);//具体菜单

    if(status)//确认了才会保存
        write_file(se,name);//数据写入文件
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

void read_file(struct flights *se,char *name)
{
    FILE *fp;

    for(int i=0;i<F_N;i++)//初始化结构
        for(int j=0;j<MAX;j++)
            se[i].seats[j]=(struct plane){(j+1),0,"",""};

    //从文件读取
    puts("输入你要打开的文件名：");
    s_gets(name,LEN);
    if ((fp = fopen(name, "a+b")) == NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    fread(se,sizeof(struct flights),F_N,fp);
    fclose(fp);
}


int get_flight(struct flights *se)                  //选择航班
{
    int n;

    puts("\n请选择航班:");
    printf("1) 102 \t 2) 311\n"
           "3) 444 \t 4) 519\n"
           "88) 离开\n");
    while( (scanf("%d",&n)) != 1 && n != 2 &&
          n != 3 && n != 4 && n != 88)
    {
        while(getchar() !='\n') continue;//清理输入行
        puts("请输入正确的数字.");
    }
    while(getchar() !='\n') continue;

    if(n ==1)
        strcpy(se[n-1].flight_num,"102");
    else if(n ==2)
        strcpy(se[n-1].flight_num,"311");
    else if(n ==3)
        strcpy(se[n-1].flight_num,"444");
    else if(n ==4)
        strcpy(se[n-1].flight_num,"519");
    else if(n ==88)
        ;
    else
        {
            puts("程序错误.\n");
            exit(EXIT_FAILURE);
        }

    return n;
}

void choose_flight_menu(struct flights *se)     //航班菜单选择
{
    int n;

    while((n=get_flight(se)) != 88)
    {
        status=0;
        choose_seat_menu(se,n);
    }
}

char get_choice(struct flights *se,int n)
{
    char ch;

    printf("\nThe number of the flight is %s. To choose a function,"
            "enter its letter label"
            "(当前航班号是%s，请选择):\n",se[n-1].flight_num, se[n-1].flight_num);
    printf( "a) Show number of empty seats(显示空座数量)\n"
            "b) Show list of empty seats(显示空座名单)\n"
            "c) Show alphabetical list of seats(按顺序显示座位名单)\n"
            "d) Assign a customer to a seat assignment(预定座位)\n"
            "e) Delete a seat assignment(删除座位)\n"
            "f) Confirm seat allocation(确认座位分配)\n"
            "q) please save it before quit(离开前请保存座位分配)\n");
    while(( ch = (tolower(getchar())) ) != 'a' && ch != 'b' &&
          ch != 'c' && ch != 'd' && ch != 'e' && ch != 'f' &&
          ch != 'q') //转小写字母
    {
        while(getchar() !='\n') continue;//清理输入行
        puts("请输入正确的字母.");
    }
    while(getchar() !='\n') continue;

    return ch;
}

void choose_seat_menu(struct flights *se,int n)            //座位菜单选择
{
    char ch;

    while( (ch=get_choice(se,n)) != 'q')
    {
        switch(ch)
        {
        case 'a':show_number(se,n);
                break;
        case 'b':show_empty(se,n);
                break;
        case 'c':show_list(se,n);
                break;
        case 'd':assign_seat(se,n);
                break;
        case 'e':delete_seat(se,n);
                break;
        case 'f':confirm_seat();
                break;
        default:puts("程序错误.");
            break;
        }
    }
}

void show_number(struct flights *se,int n)//空位置的个数
{
    int i,count=0;

    for(i=0;i<MAX;i++)
    {
        if(se[n-1].seats[i].flag == 0)
            count++;
    }
    printf("空位置的数量是%d.\n",count);
}

void show_empty(struct flights *se,int n)//打印所有空位置
{
    int i;

    puts("空位置的号码如下:\n");
    for(i=0;i<MAX;i++)
    {
        if(se[n-1].seats[i].flag==0)
            printf("%d ",se[n-1].seats[i].num);
    }
    printf("\n");
}

void show_list(struct flights *se,int n)//打印所有位置信息
{
    int i;

    puts("所有位置的清单如下：\n");
    for(i=0;i<MAX;i++)
    {
        printf("%d\t%s\t%s\n",se[n-1].seats[i].num,se[n-1].seats[i].fname,se[n-1].seats[i].lname);
    }
}

void assign_seat(struct flights *se,int n)//预订一个位置
{
    int nu;
    int temp;

    puts("输入你的要预定的座位号(1-MAX).");
    while(!((temp=scanf("%d",&nu)) == 1 && nu>=1 && nu<=MAX
            && se[n-1].seats[nu-1].flag == 0))
    {
        while(getchar() != '\n') continue;
        if(temp !=1 || nu<1 || nu>MAX)
            printf("座位号错误,请输入1-MAX!\n");
        else
            printf("对不起,你的座位已经被预订了!请重新输入座位号.\n");
    }
    while(getchar() != '\n') continue;
    se[n-1].seats[nu-1].flag=1; //预定座位
    puts("请输入你的姓：");
    s_gets(se[n-1].seats[nu-1].fname,LEN);
    puts("请输入你的名：");
    s_gets(se[n-1].seats[nu-1].lname,LEN);
    printf("预定成功.\n");
}

void delete_seat(struct flights *se,int n)//删除一个座位
{
    int nu;

    puts("输入你的要删除的座位号(1-MAX).");
    while(!((scanf("%d",&nu)) == 1 && nu>=1 && nu<=MAX
            && se[n-1].seats[nu-1].flag == 1))
    {
        while(getchar() != '\n') continue;
        if(se[n-1].seats[nu-1].flag == 0)//空座位不能删除
            printf("对不起,此座位没人!请重新输入座位号.\n");
        else
            printf("座位号错误,请输入1-MAX!\n");
    }
    while(getchar() != '\n') continue;
    se[n-1].seats[nu-1]=(struct plane){nu,0,"",""};//直接更改信息
    printf("删除成功！\n");
}

void confirm_seat(void)                //确认座位
{
    status=1;
    printf("座位确认完成！\n");
}

void write_file(struct flights *se,char *name)//数据写入文件
{
    FILE *p;

    p=fopen(name,"w+b");
    fwrite(se, sizeof(struct flights),F_N,p);
    fclose(p);
}
