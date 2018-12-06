/*9.修改程序清单 13.3 中的程序，从 1 开始，根据加入列表的顺序为每个
单词编号。当程序下次运行时，确保新的单词编号接着上次的编号开始。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
int main(void)
{
    FILE *fp;
    char words[MAX];
    int i;

    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    puts("File contents:");
    rewind(fp);   /* 返回到文件开始处 */
    for(i=1; (fscanf(fp, "%s", words) == 1) ; i++)
        printf("%d.%s\n",i,words);


    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
