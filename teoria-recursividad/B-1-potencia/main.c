#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int exp);

int main()
{
    int base, exp;
    printf("Ingrese base y potencia\n");
    scanf("%d %d", &base, &exp);
    printf("Res: %d", potencia(base, exp));
    return 0;
}

int potencia(int base, int exp){
    if(exp == 1 || exp == 0){
        return base;
    } else {
        return base * potencia(base, exp - 1);
    }
}
