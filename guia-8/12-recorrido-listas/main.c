#include <stdio.h>
#include <stdlib.h>
#include "../../librerias/pilas.h"
#include "../../librerias/colas.h"
#include "../../librerias/grafos.h"

#define MAXM 20

void cargaDatos(int mat[][MAXM]);
void cargarListaTeoria(ListaAdy L, int n);
void mostrarListaTeoria(ListaAdy L, char nom[MAXM], int n);
void recorridoProfundidad(ListaAdy L, char nom[MAXM], int n, int * compConexas);    // a
void recorridoAmplitud(ListaAdy L, char nom[MAXM], int n, int * compConexas);       // b
int todosVisitados(int vec[N], int n);


int main()
{
    ListaAdy L;
    char nom[MAXM] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    int n = 12;
    int compConexas = 0;
    cargarListaTeoria(L, n);
    mostrarListaTeoria(L, nom, n);
    recorridoProfundidad(L, nom, n, &compConexas);
    recorridoAmplitud(L, nom, n, &compConexas);
    printf("El grafo tiene %d componentes conexas\n", compConexas);

    return 0;
}

// a FALTA PARA COMPONENTES NO CONEXAS
void recorridoProfundidad(ListaAdy L, char nom[MAXM], int n, int * compConexas) {
    int vv[MAXM] = {0};
    TpilaE pila;
    int INI = 0;
    int i=0;
    iniciaPe(&pila);
    TelemP vertice;
    int ady;

    vv[INI] = 1;
    printf("\nRecorrido en profundidad:\n");
    printf("%c ", nom[INI]);
    ponePe(&pila, INI);

    while (i != n ){
        vertice = consultaPe(pila);
        ady = adyacenteNoVisitado(L, n, vv, vertice);
        if (ady != -1){
            ponePe(&pila, ady);
            printf("%c ", nom[ady]);
            vv[ady] = 1;
        } else
            sacaPe(&pila, &vertice);
        i++;
    }
}

int adyacenteNoVisitado(ListaAdy L, int n, int vv[], int x) {
    int enco = 0;
    NodoL * aux = L[x];
    while (aux != NULL && !enco){
        if (aux->destino != x && vv[aux->destino] == 0 )
            enco = 1;
        else
            aux = aux->sig;
    }
    if (enco)
        return aux->destino;
    else
        return -1;
}

// b
void recorridoAmplitud(ListaAdy L, char nom[MAXM], int n, int * compConexas){
    NodoL * aux;
    int vv[MAXM] = {0};
    TcolaE cola;
    int INI = 0;
    int vertice, i, ady;
    *compConexas = 0;
    iniciaCe(&cola);
    printf("\n\nRecorrido en amplitud:\n");

    while(!todosVisitados(vv, n)){
        while (INI < n && vv[INI] == 1)
            INI++;

        if (INI < n){
            (*compConexas)++;
            poneCe(&cola, INI);
            vv[INI] = 1;
            printf("%c ", nom[INI]);

            while (!vaciaCe(cola)){
                sacaCe(&cola, &vertice);
                aux = L[vertice];
                while (aux != NULL) {
                    if (vv[aux->destino] == 0 ){ // && aux->destino != vertice
                        poneCe(&cola, aux->destino);
                        vv[aux->destino] = 1;
                        printf("%c ", nom[aux->destino]);
                    }
                    aux = aux->sig;
                }
            }
            if (!todosVisitados(vv, n))
                printf("--- ");
        }
    }
    printf("\n");
}

int todosVisitados(int vec[N], int n){
    int i = 0;
    while (i < n && vec[i] != 0)
        i++;

    return (i == n);
}


// Carga automática de lista de adyacencia con datos predefinidos
void cargarListaTeoria(ListaAdy L, int n) {
    // Matriz base (0 y 1) para indicar las aristas
    int mat[MAX][MAX] = {0};
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

    // Inicializa todas las listas vacías
    for (int i = 0; i < n; i++)
        L[i] = NULL;

    // Recorre la matriz y agrega nodos donde hay aristas
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) { // inverso para mantener orden ascendente al insertar al inicio
            if (mat[i][j] == 1) {
                NodoL* nuevo = nuevoNodo(j);
                nuevo->sig = L[i];
                L[i] = nuevo;
            }
        }
    }
}

void mostrarListaTeoria(ListaAdy L, char nom[MAXM], int n) {
    printf("Lista de adyacencia del grafo:\n\n");
    for (int i = 0; i < n; i++) {
        printf("Vertice %c -> ", nom[i]);
        NodoL* aux = L[i];
        if (!aux) printf("(sin adyacencias)");
        while (aux != NULL) {
            printf("%c ", nom[aux->destino]);
            aux = aux->sig;
        }
        printf("\n");
    }
}
