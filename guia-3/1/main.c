#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int producto(int a, int b);
void division(int num, int denom, int *coc, int *resto);
void maxvoid(int vec[MAX], int n, int *val);
int maxint(int vec[MAX], int n);

int main()
{
    int a = 4, b = 3, coc=0, resto=0;
    int vec[MAX] = {4,3,5,67,8,1,2,5,6,9}, n = 10, val = 0;

    printf("El producto entre %d y %d es: %d\n", a, b, producto(a,b));
    a = 25; b = 2;
    division(a,b,&coc,&resto);
    printf("El cociente y el resto entre la division entre %d y %d es: coc = %d, resto = %d\n",a,b,coc,resto);
    maxvoid(vec, n, &val);
    printf("El mayor del vector void es: %d\n", val);
    printf("El mayor del vector int es: %d\n", maxint(vec,n));
    return 0;
}

int producto(int a, int b){
    if (b == 1) {
        return a;
    } else {
        return a * (producto(a, b-1));
    }
}

void division(int num, int denom, int *coc, int *resto){
    if (num < denom){
        *resto = num;
    } else {
        *coc += 1;
        num -= denom;
        division(num, denom, coc, resto);
    }
}

void maxvoid(int vec[MAX], int n, int *val){
    if(n > 0) {
        if (vec[n] > *val){
            *val = vec[n];
        }
        maxvoid(vec, n - 1,val);
    }
}

int maxint(int vec[MAX], int n){
    int aux;
    if (n == 0) {
        return vec[0];
    } else {
        aux = maxint(vec, n-1);
    }
    if (aux > vec[n]) {
        return aux;
    } else {
        return vec[n];
    }
}

/*
1. Desarrollar funciones (algunas pueden ser void) para:
a) calcular el producto de dos números enteros positivos a partir de sumas sucesivas.
b) calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas
c) hallar el máximo elemento de un vector de enteros (realizar una versión void y otra int)
*/
