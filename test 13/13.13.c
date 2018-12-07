/*13.用变长数组（VLA）代替标准数组，完成编程练习12。*/

#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int row=20,col=30;//20行,每行30列
    int ar_old[row][col];
    char ar_new[row][col+1];
    char name[20];
    FILE *p1,*p2;//p1指向读取文件，p2指向输入文件
    char ch[]={" .':~*=?%#"};
    int i,j;

    puts("请输入你要读取的文件名:");//打开读取文件
    gets(name);
    if((p1=fopen(name,"r")) == NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            fscanf(p1,"%d",&ar_old[i][j]);
            ar_new[i][j]=ch[ar_old[i][j]];//把文件内容转化成相应符号放入字符数组中
        }
        ar_new[i][j]='\0';//执行完上一个循环，此时col=j。
    }

    puts("请输入你要存入的文件名:");//打开存入文件
    gets(name);
    if((p2=fopen(name,"w")) == NULL)
    {
        fprintf(stderr,"不能打开%s文件",name);
        exit(EXIT_FAILURE);
    }
    for(i=0;i<row;i++)
    {
        fprintf(p2,"%s\n",ar_new[i]);
        fprintf(stdout,"%s\n",ar_new[i]);
    }
    if(fclose(p1) !=0 || fclose(p2) !=0)
        fputs("关闭文件失败.\n",stderr);

    return 0;
}
