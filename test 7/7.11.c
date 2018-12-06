#include <stdio.h>//编写一个程序，在循环中用switch语句实现用户输入不同的字母时有不同的响应
#include<ctype.h>
#define ARTICHOKE 2.05  //洋蓟价格a
#define BEET 1.15  //甜菜价格b
#define CARROT 1.09 //胡萝卜价格c
#define	DISCOUNT_LIMIT 100  //包装费和运费打折要求订单100美元
#define DISCOUNT_RATE 0.05	//折扣为%5
#define BREAK1 5
#define BREAK2 20   //磅数分界点
#define	FEE1 6.5
#define	FEE2 14 //装运费的分界点
#define FEE3_RATE 0.5
//不同重量区间的装运费，其中超过20磅的每续重一磅
//增加0.5元
int main(void)
{
    char ch;
    double weight=0;
    double weight_a=0,weight_b=0,weight_c=0; //购买三种蔬菜的重量
    double total_weight=0;	//总重量
    double veg_cost=0;		//三种蔬菜总共花费
    double order_cost=0;		//订单总额
    double total_cost=0;		//费用总额
    double pack_tran_fee=0;	//装运费
    double discount=0;    //折扣
    int count = 0;  //计磅数

    printf("请选择你需要买的货物字母\n");
    printf("a是洋蓟,b是甜菜,c是胡萝卜,q退出订购.\n");
    while((ch=tolower(getchar())) != 'q')
    {
        switch(ch)
        {
        case 'a':printf("输入你要购买的重量:\n");
                scanf("%lf",&weight);
                weight_a+=weight;
                count++;
                printf("继续输入a,b,c或q:\n");
                break;
        case 'b':printf("输入你要购买的重量:\n");
                scanf("%lf",&weight);
                weight_b+=weight;
                count++;
                printf("继续输入a,b,c或q:\n");
                break;
        case 'c':printf("输入你要购买的重量:\n");
                scanf("%lf",&weight);
                weight_c+=weight;
                count++;
                printf("继续输入a,b,c或q:\n");
                break;
        default:printf("请输入正确的货物字母");
        }
        while(getchar() != '\n')
            continue;					//滤掉输入重量后面的所有字符
    }

    if(!count)
    {
        printf("再见.\n");
        return 0;
    } //开始输出q，直接退出

    total_weight=weight_a+weight_b+weight_c;
    //总重量
    veg_cost=ARTICHOKE*weight_a + BEET*weight_b +CARROT*weight_c;
    //三种蔬菜总花费
    if(veg_cost>=DISCOUNT_LIMIT)
        {
            discount=veg_cost*DISCOUNT_RATE;
            order_cost=veg_cost-discount;
        }
    else
        order_cost=veg_cost;
    //折扣计算

    if (total_weight<=BREAK1)
        pack_tran_fee=FEE1;
    else if (total_weight<=BREAK2)
        pack_tran_fee=FEE2;
    else
        pack_tran_fee=FEE2+(total_weight-BREAK2)*FEE3_RATE;
    //装运费
    total_cost=order_cost+pack_tran_fee;
    //费用总额

    printf("你的购物信息如下:\n");
    if (weight_a)
        printf("洋蓟单价$%-15.2f 洋蓟重量$%-15.2f 洋蓟费用$%-15.2f\n",ARTICHOKE,weight_a,ARTICHOKE*weight_a);
    if (weight_b)
        printf("甜菜单价$%-15.2f 甜菜重量$%-15.2f 甜菜费用$%-15.2f\n",BEET,weight_b,BEET*weight_b);
    if (weight_c)
        printf("胡萝卜单价$%-13.2f 胡萝卜重量$%-13.2f 胡萝卜费用$%-13.2f\n",CARROT,weight_b,CARROT*weight_c);
    printf("订购蔬菜的费用$%-15.2f\n",veg_cost);
    if (discount)
        printf("折扣$%-15.2f\n",discount);
    printf("运费和包装费$%-15.2f\n",pack_tran_fee);
    printf("所有的费用总额$%-15.2f\n",total_cost);
    //订单信息

    return 0;
}
