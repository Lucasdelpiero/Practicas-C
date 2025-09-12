#include <stdio.h>
#include <stdlib.h>
#include "textoest.h"
#include "textodin.h"

int main()
{
    char ingreso1[MAX_TEXT], ingreso2[MAX_TEXT];
    TextD texto1, texto2, texto3;
    printf("Ingrese texto 1:\n");
    gets(ingreso1);
    texto1 = crearD(ingreso1);
    printf("Ingrese texto 2:\n");
    gets(ingreso2);
    texto2 = crearD(ingreso2);
    destruirD(&texto2);
    printf("Tamanio 2: %d\n", tamD(texto2));
    printf("Tamanio 1: %d\n", tamD(texto1));
    //printf("Imprimiendo:\n");
    //imprimir(texto1);

    //texto3 = concatenar(texto1, texto2);
    //printf("Concatenados:\n");
    //imprimir(texto3);

    return 0;
}
