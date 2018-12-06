#include <stdio.h> //100的单利息和复利比较
#include <math.h>
#define DEI 0.05 //dei 利率
#define DAP 0.1  //dap 利率
int main(void)
{
    float dei=100.0, dap=100.0, x;  //dei和dap本金都是100
	int n;

	for( n = 1, x = 0.0; x >= 0; n++)
	{
		dap = 100+DAP * 100 * n;
		dei = 100*pow(1+DEI,n) ;
		x = dap - dei;
	}
    printf("%d\n", n-1);//注意for循环顺序：当经过某次循环实现反超后仍会迭代n再继续比较，得到反超结论退出循环后，此时n已经+1了
    printf("dap:%f\tdei:%f\n", dap, dei);

    system("pause");
    return 0;
}
