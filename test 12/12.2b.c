#include <stdio.h>
static int last_mode;
static double distance;
static double fuel;

void set_mode(int mode)
{
    if(mode != 0 && mode != 1)
        printf("Invalid mode specified. Mode %s used.\n",
               last_mode == 0? "0(metric)" : "1(US)");
    else
        last_mode=mode;
}
void get_info(void)
{
    printf("Enter distance traveled in %s: ",
        last_mode == 0 ? "kilometers" : "miles");
    scanf("%lf", &distance);

    printf("Enter fuel consumed in %s: ",
        last_mode == 0 ? "liters" : "gallons");
    scanf("%lf",&fuel);
}
void show_info(void)
{
    if(last_mode ==0)
        printf("Fuel consumption is %.2lf liters per 100 km.\n",
               fuel/(distance/100));
    else
        printf("Fuel consumption is %.1lf miles per gallon.\n",
               distance/fuel) ;
}

