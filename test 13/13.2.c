/*2.编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文
件名。尽量使用标准I/O和二进制模式。 */
#include <stdio.h>
#include <stdlib.h>  // 提供 exit()的原型
int main(int argc,char * argv[])
{
    FILE *p_old,*p_new;
    char ch[256];
    size_t bytes;

    if (argc != 3)
    {    //以读模式打开原始文件
        fprintf(stderr,"Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((p_old = fopen(argv[1], "rb")) == NULL)
    {    //以读写模式打开目标文件
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((p_new = fopen(argv[2], "wb")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
     //拷贝数据
    while((bytes = fread(ch,sizeof(char),256,p_old)) >0)
        fwrite(ch,sizeof(char),bytes,p_new);
    fclose(p_old);
    fclose(p_new);

    return 0;
}
