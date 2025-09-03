#include <stdio.h>
#include <stdlib.h>

#define MAX 32

typedef int Tmat[MAX][MAX];
typedef int Tvec[MAX][MAX];

int mincuadrada(Tmat mat,int i,int j,int n); // c
void maxfilas(int mat[MAX][MAX],int i, int j, int n,int m,int vec[MAX], int *mayor); //d
void leevec(int vec[MAX], int n);
void mezcla(int vec1[MAX], int n1,int vec2[MAX], int n2, int i, int j,int vec3[MAX], int *n3); //e

int main()
{
    int vec[MAX] = {0};
    Tmat matnm = {
        {1, 3, 5, 6},
        {7, 9, 11, 3},
        {13, 15, 17, 2}
    };
    Tmat mat1 = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    } ;
    Tmat mat2 = {
        {2, 4, 6},
        {8, 9, 12},
        {14, 15, 18}
    };
    int vec1[MAX] = {1, 3, 5, 7, 9};
    int vec2[MAX] = {2, 4, 5, 6, 7, 10};
    int vec3[MAX] = {0};
    int n1 = 5, n2 = 6, n3 = 0;
    int n = 3, m = 3, mayor=0;

    printf("El menor de mat1 es: %d\n", mincuadrada(mat1, n-1, n-1, n-1 ));
    m = 4;
    printf("maxfilas: \n");
    maxfilas(matnm,0, 0,n - 1, m - 1, vec, &mayor);
    leevec(vec, n);
    printf("mezcla: \n");
    mezcla(vec1, n1, vec2, n2, 0, 0, vec3, &n3);
    leevec(vec3, n3);
    return 0;
}

int mincuadrada(Tmat mat,int i,int j,int n){
    int aux;
    if (i == 0 && j == 0) {
        aux = mat[0][0];
    } else
        if (j > 0) {
            aux = mincuadrada(mat, i, j - 1, n);
    } else
        if (i > 0){
            aux = mincuadrada(mat, i - 1, n, n);
    }

    if (mat[i][j] < aux) {
        return mat[i][j];
    } else {
        return aux;
    }
}


void maxfilas(int mat[][MAX],int i, int j, int n,int m,int vec[], int *mayor){
    if (j == 0) {
        *mayor = mat[i][j];
    }
    if (mat[i][j] > (*mayor) ) {
        *mayor = mat[i][j];
    }

    if (j < m) {
        maxfilas(mat, i, j + 1, n, m, vec, mayor);
    } else {
        vec[i] = *mayor;
        if (i < n){
            maxfilas(mat, i + 1, 0, n, m, vec, mayor);
        }
    }
}

void mezcla(int vec1[], int n1,int vec2[], int n2, int i, int j,int vec3[], int *n3) {
    if (i < n1 && j < n2) {
        if (vec1[i] <= vec2[j]) {
            if (vec1[i] != vec3[(*n3) - 1 ]) { // Agrega solo si no esta repetido
                vec3[*n3] = vec1[i];
                (*n3)++;
            }
            mezcla(vec1, n1, vec2, n2, i + 1, j, vec3, n3);
        } else
            if (vec2[j] < vec1[i] ) {
                if (vec2[j] != vec3[(*n3) - 1 ]){
                    vec3[*n3] = vec2[j];
                    (*n3)++;
                }
                mezcla(vec1, n1, vec2, n2, i , j + 1, vec3, n3);
            }
    } else // Un array que queda sin recorrer
        if (i < n1){
            if (vec1[i] != vec3[(*n3) - 1 ]) {
                vec3[*n3] = vec1[i];
                (*n3)++;
            }
            mezcla(vec1, n1, vec2, n2, i + 1, j, vec3, n3);

    } else
        if (j < n2){
            if (vec2[j] != vec3[(*n3) - 1 ]){
                vec3[*n3] = vec2[i];
                (*n3)++;
                }
                mezcla(vec1, n1, vec2, n2, i , j + 1, vec3, n3);
    }
}

void leevec(int vec[MAX], int n) {
    int i;
    for (i=0; i<n; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
}



/*
c) Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada.
d) Desarrollar un procedimiento recursivo que devuelva en un arreglo los máximos de cada fila
de una matriz de MxN.
e) Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
otro C manteniendo el orden pero sin pasar los elementos repetidos.
*/
