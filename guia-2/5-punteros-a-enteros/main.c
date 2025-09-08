#include <stdio.h>
#include <stdlib.h>

#define MAX 32

void cargaNumeros(int *vec[MAX], int *n);
void mostrarPositivos(int *vec[MAX], int n);
void liberaMemoria(int *vec[MAX], int *n);

int main()
{
    int *vec[MAX], n;
    cargaNumeros(vec, &n);
    mostrarPositivos(vec, n);
    liberaMemoria(vec, &n);
    return 0;
}

void cargaNumeros(int *vec[], int *n){
    int value;
    int i;
    FILE *archt;
    *n = 0;
    archt = fopen("datos.txt", "rt");
    if (archt == NULL){
        printf("Hubo un error en la carga del archivo\n");
    } else {
        fscanf(archt, "%d", &value);
        while (!feof(archt)) {
            vec[*n] = (int *) malloc(sizeof(int)); // vec es el puntero al array
            *(vec[*n]) = value;                      // *vec es el contenido del lugar al que apunta el puntero del array
            //printf("valor del puntero %d\n", *(vec[*n]));
            (*n)++;
            fscanf(archt, "%d", &value);
        }
        printf("valores cargados:\n");
        for(i=0; i<(*n); i++){
            printf("%d ", *vec[i]);
        }
        printf("\n");

        fclose(archt);
    }
}

void mostrarPositivos(int *vec[], int n) {
    int i, value;
    printf("Los positivos son:\n");
    for(i=0; i < n; i++){
        value = *vec[i];
        if (value > 0){
            printf("%d ", value);
        }
    }
    printf("\n");
}

void liberaMemoria(int *vec[], int *n) {
    int i;
    printf("Liberando memoria:\n");
    for(i=0; i < *n; i++){
        printf("Libera el valor %4d del puntero %p\n", *vec[i], vec[i]);
        free(vec[i]);
    }
    *n = 0;
}

