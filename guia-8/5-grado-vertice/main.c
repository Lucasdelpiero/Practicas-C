#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void cargarMatriz(int mat[MAX][MAX], int N);
void mostrarMatriz(int mat[MAX][MAX], int N);
int gradoEntrada(int mat[MAX][MAX], int N, int vert);
int gradoSalida(int mat[MAX][MAX], int N, int vert);
int grado(int mat[MAX][MAX], int N, int vert);


int main()
{
    int mat[MAX][MAX] = {};
    int N = 5;
    int x, gre , grs ,gr;
    cargarMatriz(mat, N);
    mostrarMatriz(mat, N);
    printf("Ingrese vertice a buscar grados: \n");
    scanf("%d", &x);
    gre = gradoEntrada(mat, N, x);
    grs = gradoSalida(mat, N, x);
    gr = grado(mat, N, x);
    printf("Gre: %d, Grs: %d, Gr: %d", gre, grs, gr);

    return 0;
}

int gradoEntrada(int mat[MAX][MAX], int N, int vert) {
    int cont = 0, i, j;

    for (i = 0; i < N; i++){
        if (mat[i][vert] != 0)
            cont++;
    }
    return cont;
}

int gradoSalida(int mat[MAX][MAX], int N, int vert) {
    int cont = 0, i, j;

    for (j = 0; j < N; j++){
        if (mat[vert][j] != 0)
            cont++;
    }
    return cont;
}


int grado(int mat[MAX][MAX], int N, int vert) {
    return gradoEntrada(mat, N, vert) + gradoSalida(mat, N, vert) - (mat[vert][vert] != 0);
}

// Carga automática de la matriz de adyacencia (0 y 1)
void cargarMatriz(int mat[MAX][MAX], int N) {
    int datos[MAX][MAX] = {
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = datos[i][j];
}

// Muestra la matriz
void mostrarMatriz(int mat[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
