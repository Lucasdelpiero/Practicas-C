#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int sumaM(int A[MAX][10], int i, int j, int, int m);

int main()
{
    int n,m;
    n = 10; m = 2;
    int A[MAX][10] = {{1,2},{3,4},{5,6},{7,8},{9,10},{11,12},{13,14},{15,16},{22,13},{17,18}};
    printf ("suma de los elementos %d", sumaM(A,0,0,n-1, m-1));
    return 0;
}


int sumaM(int A[][10], int i, int j, int n, int m){
    if (i==n && j==m)
        return A[i][j];
    else
        if (i==n)
            return A[i][j]+sumaM(A,0,j+1,n,m);
        else
            return A[i][j]+sumaM(A,i+1,j,n,m);
}

