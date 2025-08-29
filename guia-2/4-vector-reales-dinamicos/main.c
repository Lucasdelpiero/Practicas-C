#include <stdio.h>
#include <stdlib.h>

float* crearArreglo(int *n);
void leerArreglo(float *ptr, int n);
void mostrarPositivos(float *ptr, int n);

int main()
{
    int n;
    float *ptr = crearArreglo(&n);
    leerArreglo(ptr, n);
    mostrarPositivos(ptr, n);
    free(ptr);

    return 0;
}

float* crearArreglo(int *n){
    unsigned int i;
    printf("Ingrese cantidad de elementos:\n");
    scanf("%d", n);
    printf("N: %d\n", *n);
    float *ptr = (float *) malloc(sizeof(float) * (*n) );
    for(i=0; i< *n; i++){ // Ojo que n es la direccion, *n es el valor
        printf("Ingrese el valor n: %d\n", i + 1);
        scanf("%f", (ptr + i)); // Ojo que (ptr + i) ya es la direccion
        // Scanf necesita solo %f para leer, no %5.2f o similares
    }
    return ptr;
}

void leerArreglo(float *ptr, int n){
    unsigned int i;
    printf("Los valores del arreglo son:\n");
    for(i=0; i<n; i++){
        printf("%5.2f\n", *(ptr + i));
    }
}


void mostrarPositivos(float *ptr, int n){
    unsigned int i;
    printf("Los positivos ingresados son:\n");
    for(i=0; i<n; i++){
        if ( *(ptr + i) > 0 ){
            printf("%5.2f\n", *(ptr + i));
        }
    }
}
