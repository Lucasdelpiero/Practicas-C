#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int sumaV(int A[], int i, int n);

int main()
{
    int A[MAX] = {4,3,2,5,6,1,4,6,6,4}, n;
    n = 10;
    printf ("la suma de los elementos de A es %d", sumaV(A,0,n-1));
    return 0;
}

int sumaV(int A[],int i, int n) {
    if (i>n){
        return A[n];
    }
    else
        return A[i]+sumaV(A, i+1, n);
}

/* Al llegar al ultimo elemento del array como no finaliza ahi la recursividad y hace que se llame una vez mas, hace que el ultimo valor
se sume 2 veces
*/

