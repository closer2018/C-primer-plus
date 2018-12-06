/*16.编写一个程序读取输入，直至读到文件结尾，然后把字符串打印出
来。该程序识别和实现下面的命令行参数：
-p　　　　按原样打印
-u　　　　把输入全部转换成大写
-l　　　　把输入全部转换成小写
如果没有命令行参数，则让程序像是使用了-p参数那样运行。*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 80
#define LIM 10
int main(int argc, char * argv[])
{
    int col;
    int i;
    int row = 0;
    char str[LIM][SIZE];

    while (row < LIM && fgets(str[row], SIZE, stdin) != NULL)
    {
        if (argc == 1);
        else if (!strcmp(argv[1], "-p"))
            ;
        else if (!strcmp(argv[1], "-u"))
            for (col = 0; str[row][col] != '\0'; col++)
                str[row][col] = toupper(str[row][col]);
        else if (!strcmp(argv[1], "-l"))
            for (col = 0; str[row][col] != '\0'; col++)
                str[row][col] = tolower(str[row][col]);
        row++;
    }
    for (i = 0; i < row; i++)
        fputs(str[i], stdout);


    getchar();
    return 0;
}
