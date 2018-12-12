/*.编写一个程序，先提示用户输入名，然后提示用户输入姓。在一行打
印用户输入的名和姓，下一行分别打印名和姓的字母数。字母数要与相应名
和姓的结尾对齐，如下所示：
Melissa Honeybee
7　　　　8
接下来，再打印相同的信息，但是字母个数与相应名和姓的开头对齐，
如下所示：
Melissa Honeybee
7　　　8*/
#include <stdio.h>
#include <string.h>
int main(void)
{
    char firstname[40],secondname[40];
    int a,b;
    printf("请输入名:");
    scanf("%s",firstname);

    printf("请输入姓:");
    scanf("%s",secondname);

    a=strlen(firstname);
    b=strlen(secondname);
    printf("%s %s\n",firstname,secondname);
    printf("%*d %*d\n",a,a,b,b);
    printf("%s %s\n",firstname,secondname);
    printf("%-*d %-*d\n",a,a,b,b);

    return 0;
}
