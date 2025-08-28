#include <stdio.h>
#include <stdlib.h>
#define CANT 3

void creaVars(int *ptr, int n);
void escribeVars(int *ptr, int n);
int* creaVarsPtr(int n);

int main()
{
    int *ptr;
    //ptr = (int *) malloc(sizeof(int) * CANT); // Opcion 1 asigna memoria en main
    //creaVars(ptr, CANT);                      // Opcion 1
    ptr = creaVarsPtr(CANT);                    // Opcion 2 devuelve puntero que apunta al lugar de memoria asignado en funcion
    escribeVars(ptr, CANT);                     // Preguntar cual es mejor y cual (creo que la 2)
    free(ptr);

    return 0;
}

void creaVars(int *ptr, int n){
    unsigned int i;
    int *ptrTemp = ptr;

    for(i=0; i < n; i++){
        printf("Ingrese el valor del valor n:%d\n", i+1);
        scanf("%d", ptrTemp);
        ptrTemp++;
    }
}

int* creaVarsPtr(int n){
    unsigned int i;
    int *ptr = malloc(sizeof(int)*n);
    int *ptrTemp = ptr;

    for(i=0; i < n; i++){
        printf("Ingrese el valor del valor n:%d\n", i+1);
        scanf("%d", ptrTemp);
        ptrTemp++;
    }

    return ptr;
}

void escribeVars(int *ptr, int n){
    unsigned int i;
    int *ptrTemp = ptr;

    for(i=0; i < n; i++){
        printf("Valor n:%d = %d\n", i+1, *ptrTemp);
        ptrTemp++;
    }
}


