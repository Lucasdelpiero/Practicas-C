#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 32

int esvocal(char c);
int todasConVocal(char mat[MAX][MAX], int i,int j, int n);

int main()
{
    char mat[MAX][MAX] = {
                            {'A','5','F'},
                            {'6','5','E'},
                            {'5','5','U'},
                            };
    int n = 3;
    if (todasConVocal(mat, n-1, n-1, n-1)){
        printf("Todas las filas tienen vocal\n");
    } else {
        printf("Hay al menos una fila sin vocal\n");
    }

    return 0;
}

int todasConVocal(char mat[][MAX], int i, int j,int n){
    if (i < 0)
        return 1;
     else
        if (j < 0 )
            return 0;
     else
        if (esvocal(mat[i][j]))
            return todasConVocal(mat, i - 1, n, n);

        else
            return todasConVocal(mat, i , j - 1, n);

}


int esvocal(char c) {
    c = tolower(c);

    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
}
