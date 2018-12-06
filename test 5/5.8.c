#include<stdio.h> //估算模

int main(void)
{
    int first,second;
    printf("输入模的第二项:");
    scanf("%d",&second);
    printf("现在输入第一项:");
    scanf("%d",&first);
    while(first>0)
    {
        printf("%d %% %d 是 %d\n",first,second,first%second);
        printf("输入下一个数作为模的第一项(小于0退出):");
        scanf("%d",&first);
    }
    system("pause");
    return 0;
}
