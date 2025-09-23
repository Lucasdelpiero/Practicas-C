#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo {
    char dato;
    struct nodo *sig;
} nodo;

typedef nodo * Tlista;

void insertaL(Tlista * L, char x);
void mostrarL(Tlista L); // a
int cantVocales(Tlista L); // b
int estaOrdenada(Tlista L); // c
void elimina(Tlista * L, int p); // d


int main()
{
    Tlista L = NULL;
    insertaL(&L, 'a');
    insertaL(&L, 'c');
    insertaL(&L, 'e');
    insertaL(&L, 'f');
    insertaL(&L, 'i');

    mostrarL(L);
    printf("La cant de vocales es: %d\n", cantVocales(L));
    if (estaOrdenada(L))
        printf("La lista esta ordenada\n");
    else
        printf("La lista NO esta ordenada\n");

    elimina(&L, 3);
    elimina(&L, 0);
    mostrarL(L);

    return 0;
}

void insertaL(Tlista * L, char x){
    Tlista aux;
    aux = (Tlista) malloc(sizeof(nodo));
    aux->dato = x;

    aux->sig = *L;
    *L = aux;
}

// a
void mostrarL(Tlista L){
    Tlista aux = L;
    while(aux != NULL){
        printf("%c ", aux->dato);
        aux = aux->sig;
    } printf("\n");
}

// b
int cantVocales(Tlista L){
    Tlista aux = L;
    int cant = 0;
    char letra;
    while(aux != NULL){
        letra = tolower(aux->dato);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
            cant++;
        aux = aux->sig;
    }
    return cant;
}

// c
int estaOrdenada(Tlista L){
    Tlista aux = L;
    int ordenada = 1;
    char letra, letraAnt;

    if (aux != NULL) {
        letraAnt = aux->dato;
        aux = aux->sig;
    }

    while(aux != NULL && ordenada){
        letra = tolower(aux->dato);
        if (letraAnt < letra)
            ordenada = 0;
        letraAnt = letra;
        aux = aux->sig;
    }

    return ordenada;
}

// d
void elimina(Tlista * L, int p){
    Tlista act = * L, ant;
    int cont = 0;

    while(act != NULL && cont < p){
        ant = act;
        act = act->sig;
        cont++;
    }

    if (act != NULL) {
        if (p != 0) {
            ant->sig = act->sig;
            free(act);
        }
        else {
            *L = act->sig;
            free(act);
        }
    }
}
