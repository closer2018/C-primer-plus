/*1.修改程序清单13.1中的程序，要求提示用户输入文件名，并读取用户
输入的信息，不使用命令行参数。 */
#include <stdio.h>
#include <stdlib.h>  // 提供 exit()的原型
int main(void)
{
    int ch;      // 读取文件时，储存每个字符的地方
    FILE *fp;  // “文件指针”
    char st[20];
    unsigned long count = 0;
    printf("请输入文件名：");
    fscanf(stdin,"%s",st);
    if ((fp = fopen(st, "r")) == NULL)
    {
        printf("Can't open %s\n", st);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // 与 putchar(ch); 相同
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters\n", st, count);
    return 0;
}
