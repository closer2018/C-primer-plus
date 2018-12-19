/*4.ANSI库这样描述clock()函数的特性：
#include <time.h>
clock_t clock (void);
这里，clock_t是定义在time.h中的类型。该函数返回处理器时间，其单
位取决于实现（如果处理器时间不可用或无法表示，该函数将返回-1）。然
而，CLOCKS_PER_SEC（也定义在time.h中）是每秒处理器时间单位的数
量。因此，两个 clock()返回值的差值除以 CLOCKS_PER_SEC得到两次调用
之间经过的秒数。在进行除法运算之前，把值的类型强制转换成double类
型，可以将时间精确到小数点以后。编写一个函数，接受一个double类型的
参数表示时间延迟数，然后在这段时间运行一个循环。编写一个简单的程序
测试该函数。*/

#include <stdio.h>
#include <time.h>
#define CCS ((double)clock()/CLOCKS_PER_SEC)

void check_delay(double time);

int main()
{
    double time;

    puts("请输入显示菜单的延迟(q离开):");
    while( scanf("%lf",&time) ==1 )
    {
        check_delay(time);
        puts("时间到了.");
        puts("再次输入延迟(q离开):");
    }

    return 0;
}

void check_delay(double time)
{
    double start=CCS;
    while((CCS - start) <time )
        ;
}
