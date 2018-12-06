/*7.编写一个程序，按照程序清单12.13输出示例后面讨论的内容，修改该
程序。使其输出类似：
Enter the number of sets; enter q to stop : 18
943
How many sides and how many dice? 6 3
Here are 18 sets of 3 6-sided throws.
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
13 8 14
How many sets? Enter q to stop: q*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void roll_count(int sets, int sides, int dice);

int main(void)
{
    int sets;
    int sides, dice;

    srand((unsigned int)time(0));
    printf("你要几个数？ q离开: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("几个面，几个筛子? ");
        scanf("%d%d", &sides, &dice);
        printf("总共%d个数，%d个筛子%d个面的点数合计投掷结果如下。\n",
                sets, dice, sides);
        roll_count(sets, sides, dice);
        printf("你要几个数？ q离开: ");
    }
    printf("Bye.\n");
}

void roll_count(int sets, int sides, int dice)
{
    int i, j;
    int roll;

    if (sides < 2)
    {
        printf("至少2个面\n");
        return;
    }
    if (dice < 1)
    {
        printf("至少1个筛子.\n");
        return;
    }
    srand((unsigned int)time(0));
    for (i = 0; i < sets; i++)
    {
        roll = 0;
        for (j = 0; j < dice; j++)
            roll += rand() % sides + 1;
        printf("%d ", roll);
    }
    printf("\n");
}
