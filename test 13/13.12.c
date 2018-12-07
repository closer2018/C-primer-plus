/*12.创建一个文本文件，内含20行，每行30个整数。这些整数都在0～9
之间，用空格分开。该文件是用数字表示一张图片，0～9表示逐渐增加的灰
度。编写一个程序，把文件中的内容读入一个20×30的int数组中。一种把这
些数字转换为图片的粗略方法是：该程序使用数组中的值初始化一个20×31
的字符数组，用值0 对应空格字符，1 对应点字符，以此类推。数字越大表
示字符所占的空间越大。例如，用#表示9。每行的最后一个字符（第31个）
是空字符，这样该数组包含了20个字符串。最后，程序显示最终的图片
（即，打印所有的字符串），并将结果储存在文本文件中*/

#include <stdio.h>
#include <stdlib.h>
#define ROW 20 //20行
#define COL 30 //每行30列
int main (void)
{
    int ar_old[ROW][COL];
    char ar_new[ROW][COL+1];
    char name[20];
    FILE *p1,*p2;//p1指向读取文件，p2指向输入文件
    char ch[]={" .':~*=?%#"};//数字对应字符
    int i,j;

    puts("请输入你要读取的文件名:");//打开读取文件
    gets(name);
    if((p1=fopen(name,"r")) == NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            fscanf(p1,"%d",&ar_old[i][j]);//读取文件内容,scanf读取会跳过空格。
            ar_new[i][j]=ch[ar_old[i][j]];//把文件内容转化成相应符号放入字符数组中
        }
        ar_new[i][COL]='\0';//执行完上一个循环，此时COL=j。
    }

    puts("请输入你要存入的文件名:");//打开存入文件
    gets(name);
    if((p2=fopen(name,"w")) == NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<ROW;i++)
    {
        fprintf(p2,"%s\n",ar_new[i]);
        fprintf(stdout,"%s\n",ar_new[i]);
    }
    if(fclose(p1) !=0 || fclose(p2) !=0)
        fputs("关闭文件失败.\n",stderr);

    return 0;
}
