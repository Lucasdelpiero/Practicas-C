#include <stdio.h>
#include <stdlib.h>


#define N 5   // cantidad de vértices

// Nodo de lista simple para las adyacencias
typedef struct Nodo {
    int destino;
    struct Nodo *sig;
} Nodo;

// Vector de listas (una lista por cada vértice)
typedef Nodo *ListaAdy[N];

Nodo* nuevoNodo(int destino);
void cargarLista(ListaAdy L);
void mostrarLista(ListaAdy L);
void liberarLista(ListaAdy L);
int gradoEntrada(ListaAdy L, int vert, int n);
int gradoSalida(ListaAdy L, int vert);
int grado(ListaAdy L, int vert, int n);


int main() {
    ListaAdy L;
    int x, gre, grs, gr;
    cargarLista(L);
    mostrarLista(L);
    printf("Ingrese vertice a ver grados:\n");
    scanf("%d", &x);
    gre = gradoEntrada(L, x, N);
    grs = gradoSalida(L, x);
    gr = grado(L, x, N);
    printf("GrE: %d, GrS: %d, Gr: %d\n", gre, grs, gr);
    liberarLista(L);
    return 0;
}

int gradoEntrada(ListaAdy L, int vert, int n) {
    int i, cont = 0;
    for(i = 0; i < n; i++){
        Nodo *nod = L[i] ;
        while (nod != NULL){
            if (nod->destino == vert)
                cont++;
            nod = nod->sig;
        }
    }
    return cont;
}

int gradoSalida(ListaAdy L, int vert) {
    int cont = 0;
    Nodo *nod = L[vert];
    while (nod != NULL){
        cont++;
        nod = nod->sig;
    }
    return cont;
}
int grado(ListaAdy L, int vert, int n){
    int cantBucles = 0;
    Nodo *nod = L[vert];
    while (nod != NULL){
        if (nod->destino == vert)
            cantBucles++;
        nod = nod->sig;
    }
    return gradoEntrada(L, vert, n) + gradoSalida(L, vert) - cantBucles;
}

// Crea un nuevo nodo
Nodo* nuevoNodo(int destino) {
    Nodo* aux = (Nodo*) malloc(sizeof(Nodo));
    aux->destino = destino;
    aux->sig = NULL;
    return aux;
}

// Carga automática de lista de adyacencia con datos predefinidos
void cargarLista(ListaAdy L) {
    // Matriz base (0 y 1) para indicar las aristas
    int datos[N][N] = {
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0}
    };

    // Inicializa todas las listas vacías
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
    printf("Lista de adyacencia del dígrafo:\n\n");
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
