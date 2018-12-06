/* usehotel.c -- 房间费率程序 */
/* 与程序清单9.10一起编译  */
#include <stdio.h>
#include "hotel.h" /* 定义符号常量，声明函数 */
int main(void)
{
    int nights;
    double hotel_rate;
    int code;

    while ((code = menu()) != QUIT)
    {
    switch (code)
    {
        case 1: hotel_rate = HOTEL1;
            break;
        case 2: hotel_rate = HOTEL2;
            break;
        case 3: hotel_rate = HOTEL3;
            break;
        case 4: hotel_rate = HOTEL4;
            break;
        default: hotel_rate = 0.0;
            printf("Oops!\n");
            break;
    }
    nights = getnights();
    showprice(hotel_rate, nights);
    }
    printf("Thank you and goodbye.\n");

    return 0;
}



/* hotel.c -- 酒店管理函数 */
#include <stdio.h>
#include "hotel.h"
int menu(void)
{
    int code, status;

    printf("\n%s%s\n", STARS, STARS);
    printf("Enter the number of the desired hotel:\n");
    printf("1) Fairfield Arms       2) Hotel Olympic\n");
    printf("3) Chertworthy Plaza     4) The Stockton\n");
    printf("5) quit\n");
    printf("%s%s\n", STARS, STARS);
    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5))
        /*当code是不是整数数字的时候,status的值是0,0!=1为真,前面的表达式的值就是1;   就是说输入不是整数数字status = scanf("%d", &code)) != 1的值为1;
          code < 1,当输入<1的数字的时候, code < 1的值为1;
          code > 5,当输入>5的数字的时候, code > 5的值为1;
          或命题有一个为真,命题为真,就会进入while型循环;
          所以只有code的值是数字且大于等于1小于等于5的时候才会跳过这个while型循环,返还正确的code值;
          等价于这个命题   while (!((status = scanf("%d", &code)) == 1 && code >= 1 && code <= 5))  */
    {
        if (status != 1) //如code是数字但code不是整数数字的时候,status值为0,进入if语句
            scanf("%*s"); // scanf加%*s可以跳过读取前一段字符串,所以可以处理非整数输入,将它抛弃
        printf("Enter an integer from 1 to 5, please.\n");
    }

    return code;
}

int getnights(void)
{
    int nights;

    printf("How many nights are needed? ");
    while (scanf("%d", &nights) != 1)
    {
        scanf("%*s");   // 处理非整数输入
        printf("Please enter an integer, such as 2.\n");
    }

    return nights;
}

void showprice(double rate, int nights)
{
    int n;
    double total = 0.0;
    double factor = 1.0;

    for (n = 1; n <= nights; n++, factor *= DISCOUNT)
        total += rate * factor;
    printf("The total cost will be $%0.2f.\n", total);
}
