#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 32

void vocalesPorColumna(char mat[MAX][MAX], int i, int j, int m,int *cant);

int main()
{
    int m, cant;
    char mat[MAX][MAX] = {  {'A','5','F'},
                            {'4','4','A'},
                            {'F','3','T'} };
    m = 2;
    printf("Cant de vocales por columna:\n");
    vocalesPorColumna(mat, m, m, m, &cant);
    return 0;
}

void vocalesPorColumna(char mat[][MAX], int i, int j, int m, int *cant){
    //printf("mat[%d][%d] = %c\n",i, j, mat[i][j]);
    if (i == m) {
        *cant = 0;
    }

    if ( isalpha((int)mat[i][j]) ) {
        *cant += 1;
    }

    if (i > 0) {
        vocalesPorColumna(mat, i - 1, j, m, cant);
    }
    else
        if (j > 0) {
        printf("En la columna %d hay %d vocales\n", j , *cant);
        vocalesPorColumna(mat, m, j - 1, m, cant);
    } else {
       printf("En la columna %d hay %d vocales\n", j , *cant);
    }
}

