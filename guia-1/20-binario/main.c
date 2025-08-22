#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int n, coc=1,res;

int main()
{
    printf("Ingrese un numero para pasarlo a binario\n");
    scanf("%u", &n);

    while(coc!=0){
        coc = n / 2;
        res = n % 2;
        n = coc;
        printf("%u", res);
    }
    printf("\n");


    return 0;
}
