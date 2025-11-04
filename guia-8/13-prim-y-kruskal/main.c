#include <stdio.h>
#include <stdlib.h>
#include "../../librerias/grafos.h"

#define MAX 20

void cargaMatriz(int mat[MAX][MAX], int n);
void prim(int mat[MAX][MAX], int arbolMin[MAX][MAX],int n, int ini); // a
void kruskal(int mat[MAX][MAX], int arbolMin[MAX][MAX],int n); // b
void buscaMin(int mat[MAX][MAX], int n, int cc[MAX], int * min, int *iMin, int *jMin);

int main()
{
    int grafoPond[MAX][MAX] = {0};
    int arbolMinPRIM[MAX][MAX] = {0}, arbolMinKruskal[MAX][MAX] = {0};;
    int n = 6, ini;
    cargaMatriz(grafoPond, n);
    do{
        printf("Ingrese valor desde donde quiere comenzar prim (1-6)\n");
        scanf("%d", &ini);
    } while (ini < 1 || ini > 6);
    mostrarMatriz(grafoPond, n); printf("\n");
    prim(grafoPond, arbolMinPRIM, n, ini - 1); printf("\n");
    //mostrarMatriz(arbolMinPRIM, n); printf("\n");

    kruskal(grafoPond, arbolMinKruskal, n);
    //mostrarMatriz(arbolMinKruskal, n);


    //primMartin(grafoPond, n, 0, arbolMinPRIM);
    //mostrarMatriz(arbolMinPRIM, n); printf("\n");
    return 0;
}


// a
void prim(int mat[MAX][MAX], int arbolMin[MAX][MAX], int n, int ini){
    int u[MAX] = {0}, i, iMin, j, jMin, min;
    int disp = n-1;

    int INI = ini; // Arranca desde el num 5 como en la teoria
    u[INI] = 1;
    printf("Arbol PRIM:\n");
    //printf("%d ", INI + 1);

    while (disp){
        min = 999;
        for(i = 0; i < n; i++){
            if (u[i]) {
                for (j = 0; j < n ; j++){ // Me quedo con la posicion y valor del menor
                    if (mat[i][j] != 0 && mat[i][j] < min && !u[j] ){ //!esta(u, n, i)
                        min = mat[i][j];
                        iMin = i;
                        jMin = j;
                    }
                }
            }
        }
        u[jMin] = 1; // El destino mas barato se agrega a los visitados para el proximo ciclo
        printf("(%d, %d): %d ", iMin + 1,jMin + 1, min);
        //printf("%d ", jMin + 1);
        arbolMin[iMin][jMin] = min;
        arbolMin[jMin][iMin] = min;
        disp--;
        if (disp > 0)
            printf("--- ");
    }
    printf("\n");
}

// Supuestamente un 20% mas eficiente
void primMartin(int mat[][MAX], int n, int ini, int arbolGen[][MAX]) { //verificado
    int u[MAX], nu = 0, j, k, vertice, VV[MAX], pesoMin;
    int Vmin, adyMin;

    for(j = 0; j < n; j++)
        VV[j] = 0;
    u[nu] = ini;
    nu++;
    VV[ini] = 1;

    while(nu < n) { //si n es la cantidad de vertices entonces la condicion es nu < n es decir hasta que nu = n
        pesoMin = 99999;
        for(k = 0; k < nu; k++) //recorre u[] (vector con todos los vertices)
            for(j = 0; j < n; j++)
                if(mat[u[k]][j] != 0 && VV[j] == 0 && mat[u[k]][j] < pesoMin) {  // == 0 es mas claro que != 1
                    pesoMin = mat[u[k]][j];
                    Vmin = u[k];
                    adyMin = j;
                }
                if(pesoMin != 99999) {//es decir si encontre un adyacente valido
                    u[nu] = adyMin;
                    nu++;
                    VV[adyMin] = 1; //marco el nuevo vertice como visitado
                    arbolGen[Vmin][adyMin] = pesoMin;
                    arbolGen[adyMin][Vmin] = pesoMin;
                }
    }
}

// b
void kruskal(int mat[MAX][MAX], int arbolMin[MAX][MAX],int n) {
    int cc[MAX] = {0};
    int i, j, k;
    int min, iMin, jMin, aristas = 0, reemplazar;
    for(i = 0; i < n; i++)
        cc[i] = i + 1;

    printf("Arbol Kruskal:\n");
    while (aristas < n - 1){
        buscaMin(mat, n, cc, &min, &iMin, &jMin);

        // Reemplaza todos los que tengan un valor de otra cc con el valor de la cc al que se unieron
        reemplazar = cc[jMin];
        for(k = 0; k < n; k++)
            if(cc[k] == reemplazar)
                cc[k] = cc[iMin];

        arbolMin[iMin][jMin] = min;
        arbolMin[jMin][iMin] = min;
        aristas++;
        printf("(%d, %d): %d ", iMin + 1, jMin + 1, min);
        if (aristas < n - 1)
            printf("--- ");
    }
    printf("\n");
}

void buscaMin(int mat[MAX][MAX], int n, int cc[MAX], int * min, int *iMin, int *jMin){
    int i, j;
    *min = 999;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if (mat[i][j] != 0 && mat[i][j] < *min && cc[i] != cc[j]){ // cc[i] != cc[j] evita que se formen ciclos
                    *min = mat[i][j];
                    *iMin = i;
                    *jMin = j;
            }
}

// Esto para que???
int esta(int vec[], int n, int x){
    int es = 0;
    int i = 0;
    while(i < n && vec[i] != x)
        i++;
    return vec[i] == x;
}

void cargaMatriz(int mat[MAX][MAX], int n){
    int dat[MAX][MAX] = {0};
    int i, j;

    dat[0][1] = dat[1][0]= 6;
    dat[0][2] = dat[2][0] = 1;
    dat[0][3] = dat[3][0] = 2;

    dat[1][2] = dat[2][1] = 5;
    dat[1][4] = dat[4][1] = 3;

    dat[2][3] = dat[3][2] = 5;
    dat[2][4] = dat[4][2] = 5;
    dat[2][5] = dat[5][2] = 4;

    dat[3][5] = dat[5][3] = 2;

    dat[4][5] = dat[5][4] = 6;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            mat[i][j] = dat[i][j];
    }

}

/*
13. Para el grafo del ejercicio 10:
a) encontrar el árbol abarcador de costo mínimo (AAM) mediante el algoritmo de Prim
b) encontrar el árbol abarcador de costo mínimo (AAM) mediante el algoritmo de Kruskal
*/
