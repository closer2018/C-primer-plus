#include <stdio.h>
#define A 3.785 //1 gasoline=3.785 liters
#define B 1.609 //1 mile=1.609 kilometers
int main(void)
{
    double mileage,gasoline,mg;

    printf("请输入旅行里程(英里)和消耗的汽油量(加仑):");
    scanf("%f%f",&mileage,&gasoline);

    mileage=(mileage*B);
    gasoline=gasoline*A;
    mg=gasoline/(mileage*100);

    printf("每升汽油行驶%.1f公里.\n",mg);
    printf("每1公里用%.1f升汽油.\n",1/mg);

    system("pause");
    return 0;
}
