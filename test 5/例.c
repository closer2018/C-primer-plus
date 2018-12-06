#include<stdio.h>
void Temperatures(const double temperature)
{
    const double Fahrenheit_val = 32.0;
    const double Kelvin_val = 273.16;
    const double Fahrenheit_temp = 5.0 / 9.0 * (temperature - Fahrenheit_val);
    const double Kelvin_temp = temperature + Kelvin_val;

    printf("Celsius: %.2lf  Fahrenheit:%.2lf  Kelvin:%.2lf\n", temperature, Fahrenheit_temp, Kelvin_temp);
    return;
}
void p5_9(void)
{
    double temperature = 0.0;
    printf("please enter the temperature (q to quit):");
    while (scanf("%lf", &temperature) == 1)
    {
        getchar();
        Temperatures(temperature);
        printf("please enter the temperature (q to quit):");
    }

    return;
}


int main(int argc, char **argv)
{
    p5_9();

    getchar();

    return 1;
}
