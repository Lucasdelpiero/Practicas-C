#include <stdio.h>
#include <stdlib.h>
#include "../../librerias/grafos.h"
#include "../../librerias/colas.h"
#include "../../librerias/pilas.h"


#define MAXM 20
#define N 12

void cargaDatos(int mat[][MAXM]); // Datos de la matriz de la teoria
int todosVisitados(int vec[N], int n);
void recorridoProfundidad(int mat[][MAXM], int n, char nom[MAXM], int *compConexas); // a
void recorridoAmplitud(int mat[][MAXM], int n, char nom[MAXM], int * compConexas); // b
int adyacenteNoVisitado(int mat[][MAXM], int n, int vec[], int x);

int main()
{
    int grafo[MAXM][MAXM] = {0}, compConexas = 0;
    char nom[MAXM] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    cargaDatos(grafo);
    mostrarMatriz(grafo, N);
    recorridoAmplitud(grafo, N, nom, &compConexas);
    printf("El grafo tiene %d componentes conexas\n", compConexas);
    recorridoProfundidad(grafo, N, nom, &compConexas);
    printf("El grafo tiene %d componentes conexas\n", compConexas);

    return 0;
}


// Datos de la matriz de la teoria
void cargaDatos(int mat[][MAXM]) {
    mat[0][1] = 1;
    mat[0][3] = 1;

    mat[1][0] = 1;
    mat[1][2] = 1;
    mat[1][4] = 1;
    mat[1][5] = 1;

    mat[2][1] = 1;
    mat[2][3] = 1;

    mat[3][0] = 1;
    mat[3][2] = 1;
    mat[3][7] = 1;

    mat[4][1] = 1;
    mat[4][6] = 1;
    mat[4][7] = 1;

    mat[5][1] = 1;
    mat[5][6] = 1;

    mat[6][4] = 1;
    mat[6][5] = 1;

    mat[7][3] = 1;
    mat[7][4] = 1;

    mat[8][11] = 1;
    mat[9][10] = 1;
    mat[10][9] = 1;
    mat[11][8] = 1;
}


// a FALTA QUE FUNCIONE PARA MAS DE 1 COMP CONEXA Y DEVUELVA COMPONENTES CONEXAS
void recorridoProfundidad(int mat[][MAXM], int n, char nom[MAXM], int *compConexas){
    TpilaE pila;
    int vv[N] = {0};
    int INI;
    TelemP vertice;
    INI = 0;
    vv[INI] = 1;
    int ady;
    int i = 0;
    vv[11] = 1;
    vv[10] = 1;
    vv[9] = 1;
    vv[8] = 1;

    iniciaPe(&pila);
    ponePe(&pila, INI);
    printf("%c ", nom[INI]);
    i++;

    while (i != n ){
        vertice = consultaPe(pila);
        ady = adyacenteNoVisitado(mat, n, vv, vertice);
        if (ady != -1) {
            ponePe(&pila, ady);
            printf("%c ", nom[ady]);
            vv[ady] = 1;
        } else {
            if (!vaciaPe(pila))
                sacaPe(&pila, &vertice);
        }
        i++;
    }
    //*compConexas = i;
    printf("\n");
}

int adyacenteNoVisitado(int mat[][MAXM], int n, int vec[], int x){
    int i, enco = 0;
    while (i < n && !enco) {
        if (mat[x][i] == 1 && vec[i] != 1)
            enco = 1;
        else
            i++;
    }
    if (enco)
        return i;
    else
        return -1;
}

//b
void recorridoAmplitud(int mat[][MAXM], int n, char nom[MAXM], int *compConexas){
    TcolaE cola;
    iniciaCe(&cola);
    int vv[N] = {0};
    int INI = 0, i;
    TelemC elem;
    *compConexas = 0;

    printf("\nRecorrido en amplitud:\n\n");
    while(!todosVisitados(vv, n)){
        while (vv[INI] != 0) // Busco el primero que no haya sido visitado y arranco un nuevo recorrido desde ahi
            INI++;
        vv[INI] = 1;
        if (vaciaCe(cola))
            iniciaCe(&cola);
        poneCe(&cola, INI);
        printf("%c ", nom[INI]);

        (*compConexas)++;

        while(!vaciaCe(cola)){
            sacaCe(&cola, &elem);
            for(i = 0; i < n; i++){
                if (mat[elem][i] == 1 && vv[i] == 0){
                    if (vaciaCe(cola))
                        iniciaCe(&cola);
                    poneCe(&cola, i);
                    vv[i] = (*compConexas);
                    printf("%c ", nom[i]);
                }
            }
        }
        if (!todosVisitados(vv, n))
            printf("--- ");

    }
    printf("\n");
}

int todosVisitados(int vec[N], int n){
    int i = 0;
    while (i < n && vec[i] != 0)
        i++;

    return (i == n);
}
