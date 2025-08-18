#include <stdio.h>
#include <stdlib.h>

#define MAX 20

unsigned int num=1, nums[MAX], cant= 0, i,j, res;

int main(){
    printf("Se va a calcular cierto numero de factorales\n");
    printf("Ingrese numeros, escriba 0 para terminar la carga\n");
    while (cant < MAX && num !=0){
        scanf("%u", &num);
        if (num != 0) {
            ++cant;
            nums[cant] = num;
        }
    }

    for(i=1; i<=cant; i++){
        printf("El factorial de %u es: ", nums[i]);
        res = 1;
        for (j=1; j<=nums[i]; j++){
            res *= j;
        }
        printf("%u\n", res);
    }

    return 0;
}
