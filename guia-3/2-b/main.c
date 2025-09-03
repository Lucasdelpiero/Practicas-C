#include <stdio.h>
#include <stdlib.h>

#define MAX 32

int buscaLineal(float v[MAX],int i, int n, float x);
int buscaBinaria(float v[MAX], int piso, int techo, int mitad, float x);

int main()
{
    float v[MAX] = {1.2, 3.0, 4.2, 5.0, 5.2, 6.3}, x;
    int n = 6;
    printf("Ingrese X a buscar: \n");
    scanf("%f", &x);
    printf("Busqueda lineal, pos: %d\n", buscaLineal(v, 0, n-1, x));
    printf("Busqueda binaria, pos %d\n", buscaBinaria(v,0, n-1, (n-1)/2, x));

    return 0;
}

int buscaLineal(float v[MAX],int i, int n, float x) {
    if (i > n) {
        return -1;
    } else
        if (v[i] == x) {
            return i;
    } else
        if (i <= n){
            return buscaLineal(v, i + 1, n, x);
    }
}

int buscaBinaria(float v[], int piso, int techo, int mitad, float x){
    if(v[mitad] == x) {
        return mitad;
    } else
        if( (v[mitad] != x) && (mitad == piso || mitad == techo)) {
            return -1;
        }
       else
        if(v[mitad] < x) {
            piso = mitad;
            mitad = (techo + piso) / 2;
            if (piso != techo) {
                buscaBinaria(v, piso, techo, mitad, x);
            } else {
                return - 1;
            }
        } else
            if (v[mitad] > x){
            techo = mitad;
            mitad = (techo + piso) / 2;
            if (piso != techo) {
                buscaBinaria(v, piso, techo, mitad, x);
            } else {
                return - 1;
            }
        }


}
/*
b) Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
que posición se encuentra la primera ocurrencia de X o -1 en caso de no encontrarlo.
Implementar:
I. Considerando el arreglo desordenado, una búsqueda lineal recursiva.
II. Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva
*/
