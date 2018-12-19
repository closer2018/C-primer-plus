#include <stdio.h> //2µÄ8´ÎÃİ
#include<math.h>
int main(void)
{
    int num[8],a;
    for(a=0;a<8;a++)
    {
        num[a]=pow(2,a+1);
    }
    do
    {
        printf("%ld ",num[a-1]);
        a--;
    }
    while(a>0);
    printf("\n");

	return 0;
 }
