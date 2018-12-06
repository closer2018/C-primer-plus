#include<stdio.h>

int main(void)
{
    float weight;
    float value;

    printf("Are you worth your weight in platinum?\n");
    printf(("Let's check it out.\n"));
    printf("Please enter your weight in pounds: ");

    scanf("%f",&weight);

    value=1700.0*weight*14.5833;

    printf("You weight in platinum is worth &%.2f.\n",value);
    printf("You are easily worth that! If platinum prices drop,\n");
    printf("eat more to maintain your value.\n");
    system("pause");
    return 0;
}
