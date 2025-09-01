#include <stdio.h>
#include <stdlib.h>

#define MAX 32

void sumaV(int A[], int n, int *res);

int main()
{
    int A[MAX] = {4,3,2,5,6,1,4,6,6,4}, n, res = 0;
    n = 10;
    sumaV(A, n, &res);
    printf ("la suma de los elementos de A es %d", res);
    return 0;
}

void sumaV(int A[],int n, int *res) {
    if (n == 0){
        (*res) += A[n];
    }
    else{
        (*res) += A[n];
        sumaV(A, n - 1, res);
    }
}
