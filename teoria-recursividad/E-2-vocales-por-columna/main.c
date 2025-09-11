#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 32

void vocalesPorColumna(char mat[MAX][MAX], int i, int j, int m,int cant);

int main()
{
    int m, cant;
    char mat[MAX][MAX] = {  {'A','5','F'},
                            {'4','4','A'},
                            {'F','3','A'} };
    m = 3;
    printf("COL VOC:\n");
    vocalesPorColumna(mat, m -1, m - 1, m -1, cant);
    return 0;
}

void vocalesPorColumna(char mat[][MAX], int i, int j, int m, int cant){
    if (mat[i][j]=='a' || mat[i][j]=='A' || mat[i][j]=='e' || mat[i][j]=='E' || mat[i][j]=='i' || mat[i][j]=='I' ||
        mat[i][j]='o' || mat[i][j]=='O' || mat[i][j]=='u' ||mat[i][j]=='U' ) {
            cant++;
    }

    if (i > 0) {
        vocalesPorColumna(mat, i - 1, j, m, cant);
    }
    else
        if (j > 0) {
        printf("%d  %d \n", j + 1 , cant);
        vocalesPorColumna(mat, m, j - 1, m, 0);
    } else {
       printf("%d  %d \n", j + 1, cant);
    }
}

