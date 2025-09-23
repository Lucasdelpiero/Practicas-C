#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct nodo {
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo * Tlista;

void insertaCabeza(Tlista *, int);
void insertaCola(Tlista *, int);
void insertaOrd(Tlista *, int);

int main()
{
    Tlista L1,L2,L3;
    L1 = L2 = L3 = NULL;
    int arreglo[N] = {4, 6, 8, 3, 6, 7, 1, 2, 1, 9};
    int i;

    for (i=0; i < N ; i++){
        //insertaCabeza(&L1, arreglo[i]);
        //insertaCola(&L2, arreglo[i]);
        insertaOrd(&L3, arreglo[i]);
        mostrarL(L3);
    }
    //mostrarL(L1);
    //mostrarL(L2);
    mostrarL(L3);

    return 0;
}

void insertaCabeza(Tlista * L, int x) {
    Tlista aux = (Tlista) malloc(sizeof(nodo));
    aux->dato = x;
    aux->sig = *L;
    *L = aux;
}

void insertaCola(Tlista * L, int x) {
    Tlista act = *L, ant = NULL;
    Tlista aux = (Tlista) malloc(sizeof(nodo));
    aux->dato = x;
    aux->sig = NULL;

    if (act == NULL)
        *L = aux;
    else{
        while(act != NULL){
            ant = act;
            act = act->sig;
        }
        ant->sig = aux;
    }
}

void insertaOrdMala(Tlista * L, int x) { // Preferible el de abajo que hizo la profe
    Tlista act = *L, ant = NULL;
    Tlista aux = (Tlista) malloc(sizeof(nodo));
    aux->dato = x;
    aux->sig = NULL;

    if (act == NULL){ // lista vacia
        *L = aux;
    } else {
        while(act != NULL && act->dato < x){ // hay contenido en la lista
            ant = act;
            act = act->sig;
        }
        if (act == NULL){ // Llega a final de lista
            ant->sig = aux;
        } else  { // Inserta entre 2 valores o al primero
            if (ant == NULL) { // Inserta al primero
                *L = aux;
                aux->sig = act;
            } else {           // Inserta entre 2 valores
                ant->sig = aux;
                aux->sig = act;
            }
        }
    }
}

void insertaOrd(Tlista *L, int x){ // El de la profe con una ligera modificacion
    Tlista aux, ant, act;
    aux = (Tlista) malloc(sizeof(nodo));
    aux->dato = x;

    if (*L == NULL || x < (*L)->dato) { // Junta el inserta al principio cuando esta vacio y cuando es el menor
        aux->sig = *L;
        *L = aux;
    } else {
        ant = NULL;
        act = *L;
        while(act != NULL && x >= act->dato){ // Requiere >= ya que sino si se inserta un valor igual al primero al principio, ant es NULL
            ant = act;                        // Sino hay que comprobar que ant != NULL y modificar la cabeza
            act = act->sig;
        }
        aux->sig = act;
        ant->sig = aux;
        // Da igual si llega al final de la lista o si se mete entre 2 valores
        // la diferencia es que en el aux->sig mete el NULL del act en vez de un nodo
    }
}

void mostrarL(Tlista L){
    Tlista aux = L;
    while(aux != NULL){
        printf("%d ", aux->dato);
        aux = aux->sig;
    } printf("\n");
}
