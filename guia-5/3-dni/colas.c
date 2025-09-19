#include "colas.h"
#include <stdlib.h>

void iniciaCe(TcolaE *c) {
    c->pri = -1;
    c->ult = -1;
}

int vaciaCe(TcolaE c) {
    return c.pri == -1;
}
void poneCe(TcolaE *c, TelemC x) {
    if (c->ult != MAX_CE - 1){
        if (c->pri == - 1)
            c->pri = 0;
        c->datos[++(c->ult)] = x;
    }
}
void sacaCe(TcolaE *c, TelemC *x){
    if (c->pri != -1){ // !vaciaCe(*c)
        *x = c->datos[c->pri];
        if (c->pri == c->ult)
            iniciaCe(c);
        else
            c->pri +=1;
    }
}

TelemC consultaCe(TcolaE c);

// Cola dinamica

// Cola dinamica
void iniciaCd(TcolaD *c) {
 c->pri = c->ult = NULL;
}

int vaciaCd(TcolaD c) {
    return c.pri == NULL;
}

void poneCd(TcolaD *c, TelemC x) {
    nodo *aux;
    aux = (nodo *) malloc(sizeof(nodo));
    aux->dato = x;
    aux->sig = NULL;
    if (c->pri == NULL)
        c->pri = aux;
    else
        c->ult->sig = aux;
    c->ult = aux;
}

void sacaCd(TcolaD *c, TelemC *x) {
    nodo *aux;
    if (c->pri != NULL) {
        aux = c->pri;
        *x = aux->dato;
        c->pri = c->pri->sig;
        if (c->pri == NULL)
            c->ult == NULL;
        free(aux);
    }
}

TelemC consultaCd(TcolaD c){
    if (c.pri != NULL)
        return c.pri->dato;
}


