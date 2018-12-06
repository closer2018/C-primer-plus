/*4.编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件。使用
argc控制循环。 */
#include <stdio.h>
#include <stdlib.h>  // 提供 exit()的原型
#define SIZE 40
int main(int argc, char *argv[])
{
    FILE *p;
    int i;
    char ch;

    for (i = 1; i < argc; i++)
    {
        printf("File %d:\n", i);
        if ((p = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", argv[i]);
            //exit(EXIT_FAILURE);
        }
        while ((ch = getc(p)) != EOF)
            putchar(ch);
        printf("\n");
    }

    return 0;
}
