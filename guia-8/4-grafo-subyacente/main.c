#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void cargarMatriz(int mat[MAX][MAX], int N);
void mostrarMatriz(int mat[MAX][MAX], int N);
void matrizSuby(int ady[MAX][MAX], int suby[MAX][MAX] , int N);

int main()
{
    int ady[MAX][MAX] = {}, suby[MAX][MAX] = {0};
    int N = 5;
    cargarMatriz(ady, N);
    printf("Matriz adyacencia digrafo:\n");
    mostrarMatriz(ady, N);
    matrizSuby(ady, suby, N);
    printf("\nMatriz adyacencia grafo subyacente:\n");
    mostrarMatriz(suby, N);
    return 0;
}

void matrizSuby(int ady[MAX][MAX], int suby[MAX][MAX], int N){
    int i = 0, j = 0;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (ady[i][j] == 1) {
                suby[i][j] = 1;
                suby[j][i] = 1;
            }
        }
    }
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
