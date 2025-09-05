#include <stdio.h>
#include <stdlib.h>

#define MAX 32

void cantApaV(float mat[MAX][MAX], int i, int j, int m, int *cant, float x);
int cantApaI(float mat[MAX][MAX], int i, int j, int m, float x);

int main()
{
    float mat[MAX][MAX] =  {
        {3.0,     4.2,    3.1,    4.8},
        {9.0,   5.3,    3.0,    9.6},
        {3.0,   4.1,    0.4,    3.0}
    };
    int n = 3, m = 4, cant = 0;
    float x;
    printf("Ingrese X a buscar:\n");
    scanf("%f", &x);
    cantApaV(mat, n-1, m-1, m-1, &cant, x);

    printf("ApaV: %d\n", cant);
    printf("ApaI: %d\n", cantApaI(mat, n-1, m-1, m-1, x));

    return 0;
}

void cantApaV(float mat[MAX][MAX], int i, int j, int m, int *cant, float x){
    if (j < 0 ){
        cantApaV(mat, i - 1, m, m, cant, x);
    } else
       if (i >= 0){
            if (mat[i][j] == x) {
                (*cant) += 1;
            }
            cantApaV(mat, i, j - 1, m, cant, x);
        }
}



int cantApaI(float mat[MAX][MAX], int i, int j, int m, float x){
    if (i < 0) {
        return 0;
    } else
        if (j < 0){
            return cantApaI(mat, i - 1, m, m, x);
        }
        else {
            return (mat[i][j] == x) + cantApaI(mat, i, j - 1, m, x);
        }
}

// 4. Dada una matriz A de NxM float, retornar la cantidad de veces que un valor X aparece en A
//(realizar una versión void y otra int)
