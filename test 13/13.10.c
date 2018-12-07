/*10.编写一个程序打开一个文本文件，通过交互方式获得文件名。通过
一个循环，提示用户输入一个文件位置。然后该程序打印从该位置开始到下
一个换行符之前的内容。用户输入负数或非数值字符可以结束输入循环。*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long site;//偏移量
    char name[20];//存名字
    char ch[256];//存储字符
    FILE *p;

    printf("请输入你需要打开的文本文件:");
    gets(name);
    if( (p=fopen(name, "r")) ==NULL )
        {
            fprintf(stderr,"打不开%s文件",name);
            exit(EXIT_FAILURE);
        }
    puts("请输入你需要浏览的文件位置(大于等于0的数字):");
    while( (scanf("%ld",&site)) == 1  &&  site>=0  )
    {
        getchar();
        fseek(p,site,SEEK_SET);
        fgets(ch,256,p);
        fputs(ch,stdout);
        puts("请输入你需要浏览的文件位置(大于等于0的数字,不是正整数离开):");
    }
    puts("bye.");
    fclose(p);

    return 0;
}
