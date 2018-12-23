/*4.重写mall.c（程序清单17.7），用两个队列模拟两个摊位*/

#include <stdio.h>
#include <stdlib.h>       // 提供 rand() 和 srand() 的原型
#include <time.h>        // 提供 time() 的原型
#include "17.4.h"
#include "17.4queue.c"
#define MIN_PER_HR 60.0

bool newcustomer(double x);  // 是否有新顾客到来？
Item customertime(long when); // 设置顾客参数

int main(void)
{
    Queue line1;
    Queue line2;
    Item temp;          // 新的顾客数据

    int hours;          // 模拟的小时数
    int perhour;         // 每小时平均多少位顾客
    int wait_time1 = 0;     //摊位1从当前到空闲的时间
    int wait_time2 = 0;     //摊位2从当前到空闲的时间
    long cycle, cyclelimit;  // 循环计数器、计数器的上限
    long turnaways = 0;     // 因队列已满被拒的顾客数量
    long customers = 0;     // 加入队列的顾客数量
    long served = 0;      // 在模拟期间咨询过Sigmund的顾客数量
    long sum_line = 0;     // 累计的队列总长
    double min_per_cust;    // 顾客到来的平均时间
    long line_wait = 0;     // 队列累计的等待时间

    puts("输入模拟的小时数:");
    scanf("%d", &hours);
    puts("输入每小时的平均客户数量:");
    scanf("%d", &perhour);
    cyclelimit = MIN_PER_HR * hours;
    min_per_cust = MIN_PER_HR / perhour;

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int) time(0)); // rand() 随机初始化
    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line1)&&QueueIsFull(&line2))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                if(line1.items>line2.items)
                    EnQueue(temp, &line2);
                else if(line2.items>line1.items)
                    EnQueue(temp, &line1);
                else
                    (rand()%2) ? EnQueue(temp, &line1):EnQueue(temp, &line2);
            }
        }
        if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
        {
            DeQueue(&temp, &line1);
            wait_time1 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
        {
            DeQueue(&temp, &line2);
            wait_time2 = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }

        if (wait_time1 > 0)
            wait_time1--;

        if (wait_time2 > 0)
            wait_time2--;

        sum_line +=(long)QueueItemCount(&line1)
                    +(long)QueueItemCount(&line2);
    }
    if (customers > 0)
    {
        printf("接受的顾客: %ld\n", customers);
        printf("服务的顾客: %ld\n", served);
        printf("离开的顾客: %ld\n", turnaways);
        printf("平均队列大小: %.2f\n",
            (double) sum_line / cyclelimit);
        printf("平均等待时间: %.2f minutes\n",
            (double) line_wait / served);
    }
    else
        puts("没有顾客!");
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}
// x是顾客到来的平均时间（单位：分钟）
// 如果1分钟内有顾客到来，则返回true
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}
// when是顾客到来的时间
// 该函数返回一个Item结构，该顾客到达的时间设置为when，
// 咨询时间设置为1～3的随机值
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
