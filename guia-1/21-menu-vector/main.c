#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Para el getche()
#define MAX 20



void muestraImpares(int v[MAX], int n);
void genVecDiv(int v[MAX], int vn,int newv[MAX], int *newn, int k);
void mostrarVec(int v[MAX], int n);
int buscaVec(int v[MAX], int n,int x);

int main()
{
    int vec[MAX] = {2, 4, 5, 15, 8, 27, 4, 235, 40, 50, 36, 50, 60, 32, 42, 63, 24, 18, 25, 30}, newvec[MAX];
    int i, newn, pos, k, x;
    char menu;

    for(i = 0; i < MAX; i++){
        printf("%d  ", vec[i]);
    }
    printf("\nIngrese que quiere hacer con el array\n");
    printf("1- Muestra posiciones impares\n2- Genera otro vector con los datos divisibles por k\n3- Busca posicion de valor x\n");
    menu = getche(); printf("\n");

    switch(menu){
    case '1':
        muestraImpares(vec, MAX);
        break;

    case '2':
        printf("Ingrese K divisor de elementos de nuevo vector\n");
        scanf("%d", &k);
        genVecDiv(vec, MAX, newvec, &newn, k);
        printf("El nuevo vector es:\n");
        mostrarVec(newvec, newn);
        break;

    case '3':
        printf("Ingrese X a buscar en el vector\n");
        scanf("%d", &x);
        pos = buscaVec(vec, MAX, x);
        if (pos != -1){
            printf("Pos: %d\n", pos);
        } else {
            printf("No existe X en el vector\n");
        }
        break;

    default: printf("No se eligio una opcion valida");
    }

    return 0;
}

void muestraImpares(int v[MAX], int n){
    int i;
    printf("Los valores de las posicines impares son: \n");
    for(i=1; i< n; i += 2){
        printf("%d ", v[i]);
    }
    printf("\n");
}            //*newn++  HACE QUE AVANCE EL PUNTERO por la precedencia


void genVecDiv(int v[MAX], int vn,int newv[MAX], int *newn, int k){
    *newn = 0;
    signed int i;
    for(i=0; i < vn; i++){
        if(v[i] % k == 0){
            newv[*newn] = v[i];
            (*newn)++;
        }
    }
}



void mostrarVec(int v[MAX], int n){
    int i;
    for(i=0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int buscaVec(int v[MAX], int n, int x){
    int i = n - 1;
    while (i >= 0 && v[i] != x){
        i--;
    }
    return i;
}


