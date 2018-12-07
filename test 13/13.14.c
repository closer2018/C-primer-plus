/*14.数字图像，尤其是从宇宙飞船发回的数字图像，可能会包含一些失
真。为编程练习12添加消除失真的函数。该函数把每个值与它上下左右相邻
的值作比较，如果该值与其周围相邻值的差都大于1，则用所有相邻值的平
均值（四舍五入为整数）代替该值。注意，与边界上的点相邻的点少于4
个，所以做特殊处理。*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>//提供abs绝对值函数
#define ROW 20 //20行
#define COL 30 //每行30列
void eliminate_distortion(int ar_old[][COL],int n);//处理失真函数
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
    if((p1=fopen(name,"r"))  ==  NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            fscanf(p1,"%d",&ar_old[i][j]);//读取文件内容,scanf读取会跳过空格。
        }
    }

    eliminate_distortion(ar_old,ROW);//处理失真

    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            ar_new[i][j]=ch[ar_old[i][j]];//把文件内容转化成相应符号放入字符数组中
        }
        ar_new[i][j]='\0';//执行完上一个循环，此时COL=j。
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
        fprintf(p2,"%s\n",ar_new[i]);//打印到p2指向的文件
        fprintf(stdout,"%s\n",ar_new[i]);//打印到屏幕
    }
    //关闭文件
    if(fclose(p1) !=0 || fclose(p2) !=0)
        fputs("关闭文件失败.\n",stderr);

    return 0;
}

void eliminate_distortion(int ar_old[][COL],int n)//处理失真函数
{
    int i,j;

    for(i=0;i<n;i++) //处理失真
    {
        for(j=0;j<COL;j++)
        {
            if((i == 0 && j == 0) || (i == 0 && j == 29) || (i == 19 && j == 0) || (i == 19 && j == 29)) //在四个角的时候
                ;
            else if (i == 0) //在第一行
            {       //与下左右相比
                if ((abs(ar_old[i][j]-ar_old[i][j-1]) > 1) && (abs(ar_old[i][j]-ar_old[i][j+1]) > 1) && (abs(ar_old[i][j]-ar_old[i+1][j]) > 1))
                    ar_old[i][j]=(ar_old[i][j-1]+ar_old[i][j+1]+ar_old[i+1][j])/3.0+0.5;//四舍五入
            }
            else if (j == 0) //在第一列
            {      //与上下右相比
                if ((abs(ar_old[i][j]-ar_old[i-1][j]) > 1) && (abs(ar_old[i][j]-ar_old[i][j+1]) > 1) && (abs(ar_old[i][j]-ar_old[i+1][j]) > 1))
                    ar_old[i][j]=(ar_old[i-1][j]+ar_old[i][j+1]+ar_old[i+1][j])/3.0+0.5;//四舍五入
            }

            else if (i == 19) //在最后一行
            {     //与上左右相比
                if ((abs(ar_old[i][j]-ar_old[i][j-1]) > 1) && abs((ar_old[i][j]-ar_old[i][j+1]) > 1) && (abs(ar_old[i][j]-ar_old[i-1][j]) > 1))
                    ar_old[i][j]=(ar_old[i-1][j]+ar_old[i][j-1]+ar_old[i][j+1])/3.0+0.5;//四舍五入
            }

            else if (j == 29) //在最后一列
            {     //与上下左相比
                if ((abs(ar_old[i][j]-ar_old[i][j-1]) > 1) && (abs(ar_old[i][j]-ar_old[i+1][j]) > 1) && (abs(ar_old[i][j]-ar_old[i-1][j]) > 1))
                    ar_old[i][j]=(ar_old[i-1][j]+ar_old[i][j-1]+ar_old[i+1][j])/3.0+0.5;//四舍五入
            }

            else //在中间
            {     //与上下左右相比
                if ((abs(ar_old[i][j]-ar_old[i][j-1]) > 1) && (abs(ar_old[i][j]-ar_old[i][j+1]) > 1) && (abs(ar_old[i][j]-ar_old[i-1][j]) > 1) && (abs(ar_old[i][j]-ar_old[i+1][j]) > 1))
                    ar_old[i][j]=(ar_old[i-1][j]+ar_old[i+1][j]+ar_old[i][j-1]+ar_old[i][j+1])/4.0+0.5;//四舍五入
            }
        }
    }
}
