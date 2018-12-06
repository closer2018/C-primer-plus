#include <stdio.h>
#define CM 100
int main(void)
{
    float height;
    char name[40];
    printf("请输入名字和身高(cm):");
    scanf("%s%f",name,&height);
    height=height/CM;
    printf("%s,you are %.3fm feet tall\n",name,height);
    system("pause");
    return 0;
}
