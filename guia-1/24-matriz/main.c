#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> // Tiene el rand() para numeros random
#define MAX 32
#define SEED 4

void generaMat(int mat[MAX][MAX], int n, int m);
void leerMat(int mat[MAX][MAX], int n, int m);
int busca(int mat[MAX][MAX], int n, int m, int x); // a

int main()
{
    int n,m,i,j, x;
    int mat[MAX][MAX];
    srand(4);

    printf("Ingrese N filas\n");
    scanf("%d", &n);
    printf("Ingrese M columnas\n");
    scanf("%d", &m);
    generaMat(mat, n, m);
    leerMat(mat, n, m);

    printf("Ingrese X a buscar: \n");
    scanf("%d", &x);

    busca(mat, n, m, x);


    return 0;
}

void generaMat(int mat[MAX][MAX], int n, int m){
    unsigned int i,j;
    for(i=0; i < n; i++){
        for(j=0; j < m; j++){
            mat[i][j] = rand() % 100;
        }
    }
}

void leerMat(int mat[MAX][MAX], int n, int m) {
    unsigned int i,j;
    for(i=0; i < n; i++){
        for(j=0; j < m; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

int busca(int mat[MAX][MAX], int n, int m, int x){
    unsigned int i = n, j = m - 1;
    while (i > 0 && mat[i][j] != x){
        i --;
        j = m - 1;
        while (j > 0 && mat[i][j] != x) {
            j--;
        }
    }
    if (mat[i][j] == x){
        printf("Econtrado %d en pos[%d][%d]\n", x,i, j);
    } else {
        printf("No se encontro x\n");
    }
}


