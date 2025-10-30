#include "grafos.h"
#include <stdlib.h>

// GRAFO ===============================================================================================================

void cargarMatrizGrafo(int mat[MAX][MAX], int n) {
    // Inicializa todo en 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;

    // Carga aristas (sim�tricas)
    mat[0][1] = mat[1][0] = 1;
    mat[0][3] = mat[3][0] = 1;
    mat[1][2] = mat[2][1] = 1;
    mat[1][4] = mat[4][1] = 1;
    mat[2][3] = mat[3][2] = 1;
}

void mostrarMatriz(int mat[MAX][MAX], int n) {
    printf("Matriz de adyacencia del grafo no dirigido:\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}


// DIGRAFO =============================================================================================================
// Carga autom�tica de la matriz de adyacencia (0 y 1)
void cargarMatrizDigrafo(int mat[MAX][MAX], int n) {
    int datos[MAX][MAX] = {
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = datos[i][j];
}


// LISTA ===============================================================================================================

// Crea un nuevo nodo
Nodo* nuevoNodo(int destino) {
    Nodo* aux = (Nodo*) malloc(sizeof(Nodo));
    aux->destino = destino;
    aux->sig = NULL;
    return aux;
}

// Carga autom�tica de lista de adyacencia con datos predefinidos
void cargarLista(ListaAdy L) {
    // Matriz base (0 y 1) para indicar las aristas
		int datos[MAX][MAX] = {0};
	    datos[0][1] = datos[1][0] = 1;
		datos[0][3] = datos[3][0] = 1;
		datos[1][2] = datos[2][1] = 1;
		datos[1][4] = datos[4][1] = 1;
		datos[2][3] = datos[3][2] = 1;

    // Inicializa todas las listas vac�as
    for (int i = 0; i < N; i++)
        L[i] = NULL;

    // Recorre la matriz y agrega nodos donde hay aristas
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) { // inverso para mantener orden ascendente al insertar al inicio
            if (datos[i][j] == 1) {
                Nodo* nuevo = nuevoNodo(j);
                nuevo->sig = L[i];
                L[i] = nuevo;
            }
        }
    }
}

// Muestra la lista de adyacencia
void mostrarLista(ListaAdy L) {
    printf("Lista de adyacencia del grafo:\n\n");
    for (int i = 0; i < N; i++) {
        printf("Vertice %d -> ", i);
        Nodo* aux = L[i];
        if (!aux) printf("(sin adyacencias)");
        while (aux != NULL) {
            printf("%d ", aux->destino);
            aux = aux->sig;
        }
        printf("\n");
    }
}

// Libera la memoria de todas las listas
void liberarLista(ListaAdy L) {
    for (int i = 0; i < N; i++) {
        Nodo* act = L[i];
        while (act != NULL) {
            Nodo* aux = act;
            act = act->sig;
            free(aux);
        }
        L[i] = NULL;
    }
}

