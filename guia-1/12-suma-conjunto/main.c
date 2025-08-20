#include <stdio.h>
#include <stdlib.h>

unsigned int total=0, n;

int main()
{
    printf("Ingrese numeros naturales para sumar, se muestra el resultado al ingresar 0\n");
    scanf("%u", &n);
    while(n != 0){
        total += n;
        printf("Siguiente numero o 0 para terminar\n");
        scanf("%u", &n);
    }
    printf("El resultado es: %u\n", total);

    return 0;
}
