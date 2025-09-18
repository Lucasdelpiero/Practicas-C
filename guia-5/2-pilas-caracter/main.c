#include <stdio.h>
#include <stdlib.h>
#include "pilae.h"
#include "pilad.h"

void leerArchivo();
void mostrarPe(TpilaE * pe);
void mostrarPd(TpilaD * pd);

int main()
{
    TpilaE pe;
    TpilaD pd;
    iniciaPe(&pe);
    iniciaPd(&pd);

    leerArchivo(&pe, &pd);
    mostrarPe(&pe);
    mostrarPd(&pd);

    return 0;
}

void leerArchivo(TpilaE *pe, TpilaD *pd){
    FILE * arch;
    char dato;
    arch = fopen("datos.txt", "r");

    if (arch != NULL) {
        while (!feof(arch)){
            fscanf(arch, "%c", &dato);
            printf("ingresa dato %c\n", dato);
            ponePe(pe, dato);
            ponePd(pd, dato);
        }
    }
    fclose(arch);
}

void mostrarPe(TpilaE * pe){
    TpilaE paux;
    TelemPe elem;
    iniciaPe(&paux);

    while (!vaciaPe(*pe)){
        sacaPe(pe, &elem);
        printf("%c", elem);
        ponePe(&paux, elem);
    }printf("\n");

    while(!vaciaPe(paux)){
        sacaPe(&paux, &elem);
        printf("%c", elem);
        ponePe(pe, elem);
    }printf("\n");
}

void mostrarPd(TpilaD * pd){
    TpilaD paux;
    TelemPd elem;
    iniciaPd(&paux);

    while (!vaciaPd(*pd)){
        sacaPd(pd, &elem);
        printf("%c", elem);
        ponePd(&paux, elem);
    }printf("\n");

    while(!vaciaPd(paux)){
        sacaPd(&paux, &elem);
        printf("%c", elem);
        ponePd(pd, elem);
    }printf("\n");

}
