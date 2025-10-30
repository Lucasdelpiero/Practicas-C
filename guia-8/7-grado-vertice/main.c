#include <stdio.h>
#include <stdlib.h>
#include "../../librerias/grafos.h"


int gradoMat(int mat[MAX][MAX], int n , int vert);
int gradoLista(ListaAdy L, int n, int vert);
int gradoMediaMatriz(int mat[MAX][MAX], int n, int vert);

int main()
{
    int mat[MAX][MAX] = {0};
    ListaAdy L;
    int n = 5, x;
    int grMat, grLista, grMediaMat;
    cargarMatrizGrafo(mat, n);
    mostrarMatriz(mat, n);
    cargarLista(L);
    mostrarLista(L);
    printf("Ingrese vertice a buscar grados:\n");
    scanf("%d", &x);
    grMat = gradoMat(mat, n, x);
    grLista = gradoLista(L, n, x);
    grMediaMat = gradoMediaMatriz(mat, n, x);

    printf("GrMat: %d, GrLista: %d, GrMediaMat: %d\n", grMat, grLista, grMediaMat);


    return 0;
}

int gradoMat(int mat[MAX][MAX], int n, int vert) {
    int cont = 0, i;

    for(i = 0; i < n; i++){
        if (mat[i][vert] != 0)
            cont++;
    }
    return cont;
}

int gradoLista(ListaAdy L,  int n, int vert) {
    Nodo *nodoAct = NULL;
    int cont = 0, bucles = 0, i;

    nodoAct = L[vert];
    while (nodoAct != NULL){
        if (nodoAct->destino != vert)
            cont++;
        else
            bucles++;
        nodoAct = nodoAct->sig;
    }
    return cont - bucles;
}

int gradoMediaMatriz(int mat[MAX][MAX], int n, int vert) {
    int cont = 0, i, j;

    for(i = 0; i < vert; i++)
        if (mat[i][vert] != 0)
            cont++;
    for(j = vert + 1; j < n; j++)
        if (mat[vert][j] != 0)
            cont++;

    return cont;
}
