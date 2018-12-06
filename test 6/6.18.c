#include <stdio.h>  //计算几周朋友超过150
# define DUN 150
int main(void)
{
	int man=5,n;  //n为周,man为人数
    for(n=1;man<=DUN;n++)
    {
        man-=n;
        man*=2;
        printf("第%d周,有%d个朋友\n",n,man);
    }
	return 0;
}
