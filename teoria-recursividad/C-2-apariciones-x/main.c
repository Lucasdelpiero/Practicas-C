#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int apaX(int A[MAX], int n, int X); // Puede ser que solo necesite 3 arguementos? Preguntas

int main()
{
    int A[MAX] = {4,23,5,6,4,6,7,4}, X, n;
    X = 4;
    n = 8;
    printf ("la cantidad de apariciones de %d es %d", X ,apaX(A,n-1,X));
    return 0;
}

int apaX(int A[], int n, int X){
    int aparece = 0;
    if (A[n] == X){
        aparece = 1;
    }
    if(n==0){
        return aparece;
    } else {
        return aparece + apaX(A, n - 1, X);
    }

}
