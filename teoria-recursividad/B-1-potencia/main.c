#include <stdio.h>
#include <stdlib.h>

float potencia(int base, int exp);

int main()
{
    int base, exp;
    printf("Ingrese base y potencia\n");
    scanf("%d %d", &base, &exp);
    printf("Res: %6.3f", potencia(base, exp));
    return 0;
}

float potencia(int base, int exp){
    if(exp == 0) {
        return 1.0;
    } else
        if (exp > 0){
            return base * potencia(base, exp - 1);
        }
        else {
            return 1.0 / potencia(base, -exp);
        }
}
