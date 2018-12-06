#include <stdio.h>
int main(void){
    int i, j, k;
    printf("i j k\n");
    for (i=0; i<2; i++)
        for(j=0; j<2; j++)
            for(k=0; k<2; k++)
                printf("%d %d %d\n", i, j, k);
    return 0;
}
