#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int sumaV(int A[], int n);

int main()
{
    int A[MAX] = {4,3,2,5,6,1,4,6,6,4}, n;
    n = 10;
    printf ("la suma de los elementos de A es %d", sumaV(A,n));
    return 0;
}

int sumaV(int A[], int n) {
    if (n == 0){
        return A[n];
    }
    else
        return A[n]+sumaV(A, n-1);
}
