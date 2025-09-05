#include <stdio.h>
#include <stdlib.h>

#define MAX 32

float prom(float v[MAX], int i, int n);

int main()
{
    float v[MAX] = {2,3,5,7,3,1};
    int n = 6;
    printf("El prom del vec es : %5.2f\n", prom(v, 0, n - 1));
    return 0;
}

float prom(float v[], int i, int n){
    if (i > n) {
        return 0;
    } else {
        return v[i]/ n + prom(v, i+1, n);
    }
}

//3. Dado un vector A de N elementos, obtener el promedio de sus elementos
