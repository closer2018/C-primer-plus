/*3.编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作
为原始文件名和输出文件名。该程序要使用 ctype.h 中的 toupper()函数，在
写入到输出文件时把所有文本转换成大写。使用标准I/O和文本模式。 */
#include <stdio.h>
#include <stdlib.h>  // 提供 exit()的原型
#include <ctype.h>
#define SIZE 40
int main(void)
{
    FILE *fp_old,*fp_new;
    char name_old[SIZE],name_new[SIZE];
    char ch;

    printf("请输入源文件名:");
    gets(name_old);
    printf("请输入新建文件名:");
    gets(name_new);
    if((fp_old=fopen(name_old,"r")) ==NULL)
        fprintf(stderr,"不能打开%s文件.\n",name_old);
    if((fp_new=fopen(name_new,"w")) ==NULL)
        fprintf(stderr,"不能打开%s文件.\n",name_new);
    //拷贝数据
    while( (ch=getc(fp_old)) !=EOF )
        putc(toupper(ch),fp_new);
    fclose(fp_old);
    fclose(fp_new);

    return 0;
}
