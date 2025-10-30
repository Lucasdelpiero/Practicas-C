#include <stdio.h>
#include <stdlib.h>
#include "../../librerias/grafos.h"

void gradosMatriz(int mat[MAX][MAX], int n, int i, int j, int vec[MAX], int cont); // a
void mostrarVec(int vec[MAX], int n);

void verticeGrMasGrande(int mat[MAX][MAX], int j, int n, int maxGrado, int * vert); // b
int grado(int mat[MAX][MAX], int i, int j); // Utilidad para el b, lo hace menos eficiente

void verMejor(int mat[MAX][MAX], int i, int j, int n, int gradoAct, int maxGrado, int * vert); // b mejor pq es en una funcion

int mayorGradoEntrada(int mat[MAX][MAX], int j, int n); // No es lo que pide

int main()
{
    int mat[MAX][MAX] = {0};
    int vec[MAX] = {0};
    int n = 5;
    int vert = 0;
    //int maxGrE = 0;
    cargarMatrizGrafo(mat, n);
    mostrarMatriz(mat, n);

    gradosMatriz(mat, n - 1, n - 1, n - 1, vec, 0); // a
    printf("\n");
    mostrarVec(vec, n);

    // Es preferible la otra funcion porque hace todo en una funcion sola
    /*
    verticeGrMasGrande(mat, n, n, 0, &vert); // b
    printf("El vertice con el grado mayor es: %d\n", vert);
    */
    verMejor(mat, n, n, n, 0, 0, &vert);
    printf("El vertice con el grado mayor es: %d\n", vert);

    // Mal pq devuelve el grado mayor, no el vertice del grado mas grande
    /*
    maxGrE = mayorGradoEntrada(mat, n, n);
    printf("\nEl vertice de mayor grado de entrada es: %d\n", maxGrE);
    */

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

// a
void mostrarVec(int vec[MAX], int n) {
    int i;
    printf("Grados de los vertices:\n");
    for(i=0; i < n; i++)
        printf("%d : %d\n", i, vec[i]);
    printf("\n");
}

// b
void verticeGrMasGrande(int mat[MAX][MAX], int j, int n, int maxGrado, int * vert) {
    int gradoAct;
    if (j >= 0) {
        gradoAct = grado(mat, n, j);
        if (gradoAct > maxGrado) {
            *vert = j;
            verticeGrMasGrande(mat, j - 1, n, gradoAct, vert);
        } else
            verticeGrMasGrande(mat, j - 1, n, maxGrado, vert);
    }

}

// b mejorado
void verMejor(int mat[MAX][MAX], int i, int j, int n, int gradoAct, int maxGrado, int * vert){
    if (i < 0){
        if (gradoAct > maxGrado){
            maxGrado = gradoAct;
            *vert = j;
        }
        verMejor(mat, n, j - 1, n, 0, maxGrado, vert);
    } else
        if (j > 0)
            verMejor(mat, i - 1, j, n, gradoAct + (mat[i][j] != 0 ), maxGrado, vert);
}

int grado(int mat[MAX][MAX], int i, int j){
    if (i < 0)
        return 0;
    else
        return (mat[i][j] != 0) + grado(mat, i - 1, j);
}

// No es lo que se pide
int mayorGradoEntrada(int mat[MAX][MAX], int j, int n) {
    int gradoAct, gradoMax = 0;
    if (j >= 0){
        gradoAct = grado(mat, n, j);
        gradoMax = mayorGradoEntrada(mat, j - 1, n);

        if (gradoAct > gradoMax)
            return gradoAct;
        else
            return gradoMax;
    } else
        return 0;
}

/*
8. Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.
b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.
*/




