#include <stdio.h>
#include <float.h>
int main(void)
{
    double a=1.0/3.0;
    float b=1.0/3.0;
    printf("double:%.6lf %.12lf %.16lf\n",a,a,a);
    printf("float:%.6lf %.12lf %.16lf\n",b,b,b);
    printf("FLT_DIG:%d\n",FLT_DIG);
    printf("DBL_DIG:%d\n",DBL_DIG);
    system("pause");
    return 0;
}
