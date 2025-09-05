#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 32

int main()
{
    unsigned int n, coc=1,res, i= 0;
    int binario[MAX];
    printf("Ingrese un numero para pasarlo a binario\n");
    scanf("%u", &n);

    while(coc!=0){
        coc = n / 2;
        res = n % 2;
        n = coc;
        binario[++i] = res;
    }

    for(; i > 0; i--){
        printf("%d", binario[i]);
    }
    printf("\n");


    return 0;
}
