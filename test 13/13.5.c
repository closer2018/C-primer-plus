/*5.修改程序清单13.5中的程序，用命令行界面代替交互式界面。*/
//命令行参数argv[1]代表目标文件名，后面几个为源文件名
//该程序把多个源文件加到源文件末尾
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
char * s_gets(char * st, int n);
int main(int argc, char *argv[])
{
    FILE *fa, *fs;  // fa 指向目标文件，fs 指向源文件
    int files = 0;    // 附加的文件数量
    char ch;
    int i;

    if(argc<3)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }

    for(i=2;i<argc;i++)
    {
        if (strcmp(argv[1], argv[i]) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", argv[i]);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                    continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n",argv[i]);
            if (ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n",argv[1]);
            fclose(fs);
            printf("File %s appended.\n", argv[i]);
        }
    }
    printf("%s contents:\n", argv[1]);
    rewind(fa);

    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; // 只分配一次
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)         // 如果地址不是NULL，
            *find = '\0';    // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

