#include <stdio.h>
#include <stdlib.h>
#include "../../librerias/grafos.h"

void gradosMatriz(int mat[MAX][MAX], int n, int i, int j, int vec[MAX], int cont); // a
void mostrarVec(int vec[MAX], int n);

int main()
{
    int mat[MAX][MAX] = {0};
    int vec[MAX] = {0};
    int n = 5;
    cargarMatrizGrafo(mat, n);
    mostrarMatriz(mat, n);
    gradosMatriz(mat, n - 1, n - 1, n - 1, vec, 0); // a
    printf("\n");
    mostrarVec(vec, n);


    return 0;
}

// a
void gradosMatriz(int mat[MAX][MAX], int n, int i, int j, int vec[MAX], int cont){
    if (j >= 0 ){
        gradosMatriz(mat, n, i, j - 1, vec, cont + (mat[i][j] != 0) );
    }
    else
        if (i >= 0){
            vec[i] = cont;
            gradosMatriz(mat, n, i - 1, n, vec, 0);
        }
}

void mostrarVec(int vec[MAX], int n) {
    int i;
    printf("Grados de los vertices:\n");
    for(i=0; i < n; i++)
        printf("%d : %d\n", i, vec[i]);
    printf("\n");
}




/*
8. Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.
b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.
*/




