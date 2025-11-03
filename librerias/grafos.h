#ifndef HEADER_6D4F9E3189DEE0A1
#define HEADER_6D4F9E3189DEE0A1


#endif // header guard
#define MAX 20
#define N 20

void cargarMatrizGrafo(int mat[MAX][MAX], int n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void cargarMatrizDigrafo(int mat[MAX][MAX], int n);


// Nodo de lista simple para las adyacencias
typedef struct NodoL {
    int destino;
    struct NodoL *sig;
} NodoL;

// Vector de listas (una lista por cada vértice)
typedef NodoL *ListaAdy[N];

void cargarLista(ListaAdy L);
void mostrarLista(ListaAdy L);
void liberarLista(ListaAdy L);

