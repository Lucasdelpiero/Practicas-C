#include "colad.h"
#include <stdlib.h>
#include <stdio.h>

void iniciaCd(TcolaD *c) {
 c->pri = c->ult = NULL;
}

int vaciaCd(TcolaD c) {
    return c.pri == NULL;
}

void poneCd(TcolaD *c, TelemCd x) {
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

void sacaCd(TcolaD *c, TelemCd *x) {
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

TelemCd consultaCd(TcolaD c){
    if (c.pri != NULL)
        return c.pri->dato;
}
