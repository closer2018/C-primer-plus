/*4.编写一个程序，提示用户输入身高（单位：英寸）和姓名，然后以下
面的格式显示用户刚输入的信息：
Dabney, you are 6.208 feet tall
使用float类型，并用/作为除号。如果你愿意，可以要求用户以厘米为
单位输入身高，并以米为单位显示出来。*/
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

    return 0;
}
