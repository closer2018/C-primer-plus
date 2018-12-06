#include <stdio.h>  //初始100万,年化8%,每年取10万,几年取完
#define RATE 0.08  //利率年化8%
int main(void)
{
	int n;
	float mon=100.0;//100万本金
	for(n=1;mon>=0;n++)
    {
        mon=mon*(1+0.08)-10;
    }
    printf("%d",n-1);
	return 0;
 }
