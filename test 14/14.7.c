/*7.修改程序清单 14.14，从文件中读取每条记录并显示出来，允许用户
删除记录或修改记录的内容。如果删除记录，把空出来的空间留给下一个要
读入的记录。要修改现有的文件内容，必须用"r+b"模式，而不是"a+b"模
式。而且，必须更加注意定位文件指针，防止新加入的记录覆盖现有记录。
最简单的方法是改动储存在内存中的所有数据，然后再把最后的信息写入文
件。跟踪的一个方法是在book结构中添加一个成员表示是否该项被删除。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 20
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBOOKS 10     // 最大书籍数量
int count = 0;      //外部变量，书的数目
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char * st, int n);		//输入字符串的函数
char get_choice(void);					//获取用户选择
void add(struct book li[]);				//添加若干本书
void change(struct book *li);				//替换一本书
void del(struct book *li);				//删除一本书
void print(struct book *li);				//打印书单
void write_file(struct book *li, char *name);	//将数据写入文件

int main(void)
{
    struct book library[MAXBOOKS];
    char ch,name[LEN];
    FILE * fp;

    puts("输入你要打开的文件名：");
    s_gets(name,LEN);
    if ((fp = fopen(name, "r+b")) == NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    rewind(fp);     // 定位到文件开始
    while (count < MAXBOOKS && fread(&library[count],
            sizeof(struct book), 1, fp) == 1)
    {
        count++;//统计当前书本数目
    }
    fclose(fp);

    print(library);//打印已有书籍列表
    printf("现有书籍%d本.\n",count);

    //选择清单
    while( (ch=get_choice()) != 'q')
    {
        switch(ch)
        {
        case 'a':add(library);
                break;
        case 'b':change(library);
                break;
        case 'c':del(library);
                break;
        case 'd':print(library);
                break;
        default:puts("程序错误.");
            break;
        }
    }

    //数据写入文件
    write_file(library,name);
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

char get_choice(void)   //获取用户选择
{
    char ch;

    puts("\n请输入你的选择：");
    printf("a:增\t\tb:改\n"
           "c:删\t\td:查\n"
           "q:保存和离开\n");
    while(( ch = (tolower(getchar())) ) != 'a' && ch != 'b' &&
          ch != 'c' && ch != 'd' && ch != 'q') //转小写字母
    {
        while(getchar() !='\n') continue;//清理输入行
        puts("请输入正确的字母.");
    }
    while(getchar() !='\n') continue;

    return ch;
}

void add(struct book li[])
{
    if(count == MAXBOOKS)
        puts("皇上,臣妾实在装不下了.\n");
    else
    {
        puts("请输入书名(按[enter]离开).");
        while (count < MAXBOOKS && s_gets(li[count].title, MAXTITL) != NULL
                && li[count].title[0] != '\0')
        {
            puts("请输入作者.");
            s_gets(li[count].author, MAXAUTL);
            puts("请输入价格.");
            scanf("%f", &li[count++].value);
            while (getchar() != '\n')
                continue;    // 清理输入行
            if (count < MAXBOOKS)
                puts("输入下一个书名(按[enter]回到选择界面).");
        }
    }
}

void change(struct book *li)
{
    int i;
    char title[MAXTITL];

    puts("请输入你需要替换信息的书籍名：");
    s_gets(title,MAXTITL);
    for(i=0;i<count;i++)
    {
        if( strcmp(title,li[i].title) == 0)//检测输入书名和文件中书名是否一致
        {
            puts("变更后的书籍名字是？");
            s_gets(li[i].title, MAXTITL);
            puts("请输入作者.");
            s_gets(li[i].author, MAXAUTL);
            puts("请输入价格.");
            scanf("%f", &li[i].value);
            while (getchar() != '\n')
                continue;    // 清理输入行
            break;
        }
    }
    if(i==count)
        puts("找不到你要更改的书籍!\n");
}

void del(struct book *li)
{
    int i,j;
    int flag=0;//标记是否找到
    char title[MAXTITL];

    if(count == 0)
        puts("皇上，臣妾这里没有书!\n");
    puts("请输入你需要删除的书籍名：");
    s_gets(title,MAXTITL);
    for(i=0;i<count;i++)
    {
        if( ! strcmp(title,li[i].title) )
        {//检测输入书名和文件中书名是否一致
            flag=1;
            for(j=i;j<count;j++)//一致则后面的数据变动
                li[j]=li[j+1];//后面的数据提到前面
            count--;
            //最后一条数据置零
            li[count]=(struct book){"","",0};
            /*strcpy(li[count].title, "");
            strcpy(li[count].author, "");
            li[count].value = 0;*/ //跟上面的同义替换
            break;
        }
    }
    if(!flag)
        puts("找不到你要删除的书籍!\n");
}

void print(struct book *li)
{
    int index;
    if (count > 0)
    {
        puts("\n书籍清单如下:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", li[index].title,
                    li[index].author, li[index].value);
        printf("\n");
    }
    else
        puts("没有找到书,真遗憾!\n");

}

void write_file(struct book *li, char *name)  //将数据写入文件
{
    FILE *p;

    p=fopen(name,"w+b");
    fwrite(li, sizeof(struct book), count,p);
    fclose(p);
}
