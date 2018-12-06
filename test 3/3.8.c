#include<stdio.h>
int main(void)
{
    float p=0.0,b=0.0,a=0.0,d=0.0,c=0.0;
    printf("请输入杯数:");
    scanf("%f",&b);
    p=b/2;
    a=b*8;
    d=a*2;
    c=d*3;
    printf("以品脱、盎司、大汤勺、茶勺为单位显示容量分别是%.3f,%.3f,%.3f,%.3f.\n"
           ,p,a,d,c);
    system("pause");
    return 0;
}
