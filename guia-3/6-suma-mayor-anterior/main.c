#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int mayorFilaAnterior(int mat[MAX][MAX], int i, int j, int n, int m, int suma, int sumaAnt);

int main()
{
    int mat1[MAX][MAX] = {
    {2, 4, 6},    // suma = 12 (par)
    {5, 5, 5},    // suma = 15 > 12
    {7, 7, 7},    // suma = 21 > 15
    {8, 8, 10},   // suma = 26 > 21
    {12, 12, 12}  // suma = 36 > 26
    };
    int mat2[MAX][MAX] = {
    {1, 2, 3},    // suma = 6 (par)
    {2, 2, 2},    // suma = 6 (NO > 6)
    {3, 3, 3},    // suma = 9
    {4, 4, 4},    // suma = 12
    {5, 5, 5}     // suma = 15
    };
    int n = 5, m = 3;

    if (mayorFilaAnterior(mat1, 0, 0, n-1, m-1, 0, 0)) {
        printf("mat1 cumple\n");
    } else {
        printf("mat1 no cumple\n");
    }

    if (mayorFilaAnterior(mat2, 0, 0, n-1, m-1, 0, 0)) {
        printf("mat2 cumple\n");
    } else {
        printf("mat2 no cumple\n");
    }

    return 0;
}

int mayorFilaAnterior(int mat[][MAX], int i, int j, int n, int m, int suma, int sumaAnt) {
    if (i > n) {
        return 1;
    }
    else
        if (j <= m){ // Avanza sumando fila a fila
            if (j == 0) {
                suma = mat[i][j];
            } else {
                suma += mat[i][j];
            }
            return mayorFilaAnterior(mat, i, j + 1, n, m, suma, sumaAnt);
        }
    else { // j > m     Comprueba si cumple o no la condicion
        if(i == 0) {
            if(suma % 2 == 0) { // Primera fila es o no par
                sumaAnt = suma;
                return mayorFilaAnterior(mat, i + 1, 0, n, m, suma, sumaAnt);
            } else {
                return 0;
            }
        } else { // Suma es o no mayor a la suma anterior
            if (suma > sumaAnt){
                sumaAnt = suma;
                return mayorFilaAnterior(mat, i + 1, 0, n, m, suma, sumaAnt);

            } else { // suma <= sumaAnt
                return 0;
            }
        }
    }
}



/*
6. Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par.
*/
