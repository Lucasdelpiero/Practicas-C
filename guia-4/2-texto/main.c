#include <stdio.h>
#include <stdlib.h>
#include "textoest.h"

int main()
{
    char ingreso1[MAX_TEXT], ingreso2[MAX_TEXT];
    Ttexto texto1, texto2, texto3;
    printf("Ingrese texto 1:\n");
    gets(ingreso1);
    texto1 = crear(ingreso1);
    printf("Ingrese texto 2:\n");
    gets(ingreso2);
    texto2 = crear(ingreso2);
    printf("Tamanio: %d\n", tam(texto1));
    printf("Imprimiendo:\n");
    imprimir(texto1);

    texto3 = concatenar(texto1, texto2);
    printf("Concatenados:\n");
    imprimir(texto3);

    return 0;
}
