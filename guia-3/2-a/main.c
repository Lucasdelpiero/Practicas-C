#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int suma(int vec[MAX], int n);
void escribe(int vec[MAX], int n);
void escribeInv(int vec[MAX], int n);

int main()
{
    int vec[MAX] = {1,2,4,6,10}, n = 5;

    printf("Suma: %d\n", suma(vec, n - 1));
    escribe(vec, n - 1); printf("\n");
    escribeInv(vec, n - 1); printf("\n");
    return 0;
}

int suma(int vec[], int n){
    if (n == 0){
        return vec[n];
    } else {
        return vec[n] + suma(vec, n - 1);
    }
}

void escribe(int vec[], int n){
    if (n > 0) {
        escribe(vec, n - 1);
    }
    printf("%d ", vec[n]);
}


void escribeInv(int vec[MAX], int n){
    printf("%d ", vec[n]);
    if (n > 0) {
        escribeInv(vec, n - 1);
    }
}


/*
2. Recodificar en el lenguaje C los siguientes ejercicios de Programación I desarrollados en Pascal:
a) Sea V un arreglo de enteros, se pide:
I. Calcular e informar la suma de sus elementos.
II. Mostrar sus elementos.
III. Mostrar sus elementos en orden inverso.
*/
