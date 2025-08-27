#include <stdio.h>
#include <stdlib.h>

#define MAX 32
#define N 6
#define M 8
#define SEED 4

typedef int Tmat[MAX][MAX];
typedef struct{
    unsigned int fila;
    unsigned int col;
    int valor;
} Tdivisible;
typedef Tdivisible TvecDivisibles[MAX];

void generaMatriz(Tmat mat, unsigned int n, unsigned int m);
void leerMatriz(Tmat mat, unsigned int n, unsigned int m);
void generaVectorDivisibles(Tmat mat, unsigned int n, unsigned int m, TvecDivisibles vec, unsigned int *nvec);
void leeVectorDivisibles(TvecDivisibles vec, unsigned int n);

int main()
{
    TvecDivisibles vec;
    unsigned int nvec;
    Tmat mat;
    srand(SEED);
    printf("N: %d  M: %d\n", N, M);
    generaMatriz(mat, N, M);
    leerMatriz(mat, N, M);
    generaVectorDivisibles(mat, N, M, vec, &nvec);
    leeVectorDivisibles(vec, nvec);


    return 0;
}

void generaMatriz(Tmat mat, unsigned int n, unsigned int m){
    unsigned int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            mat[i][j] = rand() % 1000;
        }
    }
}

void leerMatriz(Tmat mat, unsigned int n, unsigned int m){
    unsigned int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%6d", mat[i][j]);
        }
        printf("\n");
    }
}

void generaVectorDivisibles(Tmat mat, unsigned int n, unsigned int m, TvecDivisibles vec, unsigned int *nvec){
    unsigned int i,j;
    *nvec = 0;
    printf("Generando vector con divisores de N+M: %d\n", n + m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(mat[i][j] % (n + m) == 0){
                vec[*nvec].valor = mat[i][j];
                vec[*nvec].fila = i;
                vec[*nvec].col = j;
                (*nvec)++;
            }
        }
    }
}

void leeVectorDivisibles(TvecDivisibles vec, unsigned int n){
    unsigned int i;
    for(i=0; i<n; i++){
            printf("[%d][%d]: %d\n", vec[i].fila, vec[i].col, vec[i].valor);
    }
}
