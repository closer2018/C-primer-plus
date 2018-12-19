/*2.两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数
的平均值，最后取计算结果的倒数。使用#define指令定义一个宏“函数”，执
行该运算。编写一个简单的程序测试该宏。*/

#include <stdio.h>
#include <stdlib.h>

#define HARMONIC_AVERAGE1(X,Y)  1/( (1/(X)+1/(Y))/2 )
#define HARMONIC_AVERAGE2(X,Y)  (2*(X)*(Y))/((X)+(Y))

int main()
{
    double x,y;

    puts("请输入两个数(输入字母离开程序)");
    while( scanf("%lf%lf",&x,&y) ==2)
    {
        while(getchar() != '\n') continue;
        printf("用第一个公式%.3lf和%.3lf的调和平均数是%.3lf\n",x,y,HARMONIC_AVERAGE1(x,y));
        printf("用第二个公式%.3lf和%.3lf的调和平均数是%.3lf\n",x,y,HARMONIC_AVERAGE2(x,y));
        puts("请输入两个数(输入字母离开程序)");
    }
    puts("再见.");

    return 0;
}
