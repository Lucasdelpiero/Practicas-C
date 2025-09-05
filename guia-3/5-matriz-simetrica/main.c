#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int simetrica(int mat[MAX][MAX], int i, int j, int n);

int main()
{
    int A[MAX][MAX] = {
        {1, 2, 3, 4, 5},
        {2, 6, 7, 8, 9},
        {3, 7, 10, 11, 12},
        {4, 8, 11, 13, 14},
        {5, 9, 12, 14, 15}
    };

    int B[MAX][MAX] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int n = 5;


    if (simetrica(A, n-1, n-1, n-1)) {
        printf("A es simetrica\n");
    } else {
        printf("A no es simetrica\n");
    }

    if (simetrica(B, n-1, n-1, n-1)) {
        printf("B es simetrica\n");
    } else {
        printf("B no es simetrica\n");
    }

    return 0;
}


int simetrica(int mat[MAX][MAX], int i, int j, int n){
    if (i == n && j == n){ // Hace mas facil ingresar el primer llamado con todo n - 1
        return simetrica(mat, i - 1, j, n);
    } else
        if (j < 0) {
            return 1;
        }
        else
            if(i < 0) {
                return simetrica(mat, n - 1, n - 1, n - 1);
            }
            else
                if (mat[i][j] == mat[j][i]) {
                    return simetrica(mat, i - 1, j, n);
                }
                else {
                    return 0;
                }
}






