/*8.编写一个程序，以一个字符和任意文件名作为命令行参数。如果字符
后面没有参数，该程序读取标准输入；否则，程序依次打开每个文件并报告
每个文件中该字符出现的次数。文件名和字符本身也要一同报告。程序应包
含错误检查，以确定参数数量是否正确和是否能打开文件。如果无法打开文
件，程序应报告这一情况，然后继续处理下一个文件。*/
#include <stdio.h>
#include <stdlib.h>  // 提供 exit()的原型
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *p;
    char ch;
    int i,count=0;

    if (argc < 2)
    {
        fprintf(stderr, "命令行参数数量错误\n.");
        exit(EXIT_FAILURE);
    }

    if(argc==2)
    {
        puts("输入一些文字:");
        while ((ch = getchar()) != EOF)
        {
            if (ch == argv[1][0])
                count++;
        }
        printf("你的输入中%s出现了%d次.\n",argv[1], count);

    }
    else
    {
        for(i=2;i<argc;i++)
            {
                count=0;
                if ((p = fopen(argv[i], "r")) == NULL)
                {
                    fprintf(stderr,"Can't open %s\n", argv[i]);
                        continue;
                }

                while( (ch=getc(p)) != EOF)
                {//检测是否文件结尾
                    if(ch == argv[1][0])
                        count++;
                }
                printf("%s有%d个%s字符.\n",argv[i],count,argv[1]);
            }
    }

    return 0;
}
