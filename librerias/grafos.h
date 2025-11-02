#ifndef HEADER_6D4F9E3189DEE0A1
#define HEADER_6D4F9E3189DEE0A1


#endif // header guard
#define MAX 20
#define N 5

void cargarMatrizGrafo(int mat[MAX][MAX], int n);
void mostrarMatriz(int mat[MAX][MAX], int n);
void cargarMatrizDigrafo(int mat[MAX][MAX], int n);


// Nodo de lista simple para las adyacencias
typedef struct Nodo {
    int destino;
    struct Nodo *sig;
} Nodo;

// Vector de listas (una lista por cada vértice)
typedef Nodo *ListaAdy[N];

void cargarLista(ListaAdy L);
void mostrarLista(ListaAdy L);
void liberarLista(ListaAdy L);

