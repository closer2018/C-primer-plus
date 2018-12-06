/*6.使用命令行参数的程序依赖于用户的内存如何正确地使用它们。重写
程序清单 13.2 中的程序，不使用命令行参数，而是提示用户输入所需信
息。*/
// reducto.c –把文件压缩成原来的1/3！
#include <stdio.h>
#include <stdlib.h>  // 提供 exit()的原型
#define LEN 40
int main(void)
{
    FILE *in, *out; // 声明两个指向 FILE 的指针
    int ch;
    char name_in[LEN],name_out[LEN]; // 储存输出文件名
    int count = 0;

    printf("请输入源文件名：");
    fscanf(stdin,"%s",name_in);
    printf("请输入目标文件名：");
    fscanf(stdin,"%s",name_out);
    // 设置输入
    if ((in = fopen(name_in, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",name_in);
        exit(EXIT_FAILURE);
    }
    // 设置输出

    if ((out = fopen(name_out, "w")) == NULL)
    {          // 以写模式打开文件
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    // 拷贝数据
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);// 打印3个字符中的第1个字符
    // 收尾工作
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
