#include <stdio.h>
#include <string.h>
int main(void)
{
    char firstname[40],secondname[40];
    int a,b;
    printf("«Î ‰»Î√˚:");
    scanf("%s",firstname);

    printf("«Î ‰»Î–’:");
    scanf("%s",secondname);

    a=strlen(firstname);
    b=strlen(secondname);
    printf("%s %s\n",firstname,secondname);
    printf("%*d %*d\n",a,a,b,b);
    printf("%s %s\n",firstname,secondname);
    printf("%-*d %-*d\n",a,a,b,b);
    system("pause");
    return 0;
}
