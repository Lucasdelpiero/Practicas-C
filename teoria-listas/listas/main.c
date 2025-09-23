#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    char dato;
    struct nodo *sig;
} nodo;

typedef nodo * Tlista;
int cantVocales(Tlista L, int k);


int main()
{
    printf("Hello world!\n");
    return 0;
}

//1
int cantVocales(Tlista L, int k) {
    int cont=0;
    int i= 0;
    Tlista aux;
    aux = L;
    while(aux != NULL && i < k){
        char car = lowercase(aux.dato);

        if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u')
            cont++:
        }
        i++;
        aux = lista.sig;
    return cont;
}

void destruirLista(Tlista *L) {
    Tlista act = *L, ant;
    while(act) {
        ant = act;
        act = aux->sig;
        free(ant);
    }
    *L = NULL;
}

void eliminaX(Tlista *L, int x) {
    Tlista act = *L, ant;
    while(act and act->dato < x) {

        if (act->dato == x) {
            ant.sig = act.sig;
            free(act);
            act = ant.sig;
        } else
            act = act.sig;
    }
}
