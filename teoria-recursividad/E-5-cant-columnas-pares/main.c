#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int cantColPares(int mat[MAX][MAX], int i, int j, int n);

int main()
{
    int mat[MAX][MAX] = {
        {2,3,6},
        {4,6,12},
        {8,2,8}
    };
    int n = 2;
    printf("Cant de col pares es: %d\n", cantColPares(mat, n, n, n));
    return 0;
}

int cantColPares(int mat[MAX][MAX], int i, int j, int n) {
    int esPar = (mat[i][j] % 2 == 0);
    printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
    if (j < 0){
        return 0;
    }
    else
        if (i < 0){
            return 1 + cantColPares(mat, n, j - 1, n);
    } else {
        if (!esPar){
            return cantColPares(mat, i, j - 1, n);
        } else {
            return cantColPares(mat, i - 1, j, n);
        }
    }

}
