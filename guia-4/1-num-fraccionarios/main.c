#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

int main()
{
    Tfraccion f1, f2, f3;
    f1 = crear(5,2);
    f2 = crear(4,3);
    f3 = suma(f1, f2);
    printf("Operaciones con %d/%d y %d/%d\n", numerador(f1), denominador(f2), numerador(f2), denominador(f2));
    printf("res suma: %d/%d\n", numerador(f3), denominador(f3));
    f3 = restar(f1, f2);
    printf("res resta: %d/%d\n", numerador(f3), denominador(f3));
    f3 = multiplicar(f1, f2);
    printf("res mult: %d/%d\n", numerador(f3), denominador(f3));
    f3 = dividir(f1, f2);
    printf("res div: %d/%d\n", numerador(f3), denominador(f3));

    f3 = crear(50, 150);

    printf("res simp de %d/%d: ", numerador(f3), denominador(f3));
    f3 = simplificar(f3);
    printf("%d/%d\n", numerador(f3), denominador(f3));

    f1 = crear(1,3);
    f2 = crear(9,27);
    if (iguales(f1, f2))
        printf("Son iguales %d/%d y %d/%d\n", numerador(f1), denominador(f1), numerador(f2), denominador(f2));
    else
        printf("Son distintos %d/%d y %d/%d\n", numerador(f1), denominador(f1), numerador(f2), denominador(f2));


    return 0;
}
