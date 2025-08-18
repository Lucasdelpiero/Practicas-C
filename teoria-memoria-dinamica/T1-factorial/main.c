#include <stdio.h>
#include <stdlib.h>

unsigned int num,i,res;

int main()
{
    printf("Vamos a ver el factorial del siguiente numero\n");
    printf("Ingrese el num: ");
    scanf("%u", &num);
    printf("El factorial de %u es:", num);
    res = 1;
    for (i=1; i<=num; i++){
        res *= i;
    }
    printf("%u\n", res);

    return 0;
}
