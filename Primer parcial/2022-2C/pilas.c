#include "pilas.h"
#include <stdlib.h>

// Pila estatica

void ponePe(TpilaE *p, TelemP x) {
    if(p->tope != MAX_PE - 1){
        p->tope++;
        p->datos[p->tope] = x;
    }
}

void sacaPe(TpilaE *p, TelemP *x){
    if (p->tope !=-1)
        *x = p->datos[p->tope--];
}

TelemP consultaPe(TpilaE p){
    if (p.tope != -1)
        return p.datos[p.tope];
}

int vaciaPe(TpilaE p){
    return p.tope == -1;
}

void iniciaPe(TpilaE *p){
    p->tope = -1;
}

// Pila dinamica

void ponePd(TpilaD *p, TelemPd x){
    TpilaD n;
    n = (TpilaD) malloc(sizeof(nodop));
    n->dato = x;
    n->sig = *p;
    *p = n;
}

void sacaPd(TpilaD *p, TelemPd *x){
    TpilaD n;
    if (*p){ // *p != NULL;
        n = *p;
        *x = (*p)->dato;
        *p = (*p)-> sig;
        free(n);
    }
}

TelemPd consultaPd(TpilaD p){
    if (p)
        return p->dato;
}

int vaciaPd(TpilaD p) {
    return (p == NULL);
}
void iniciaPd(TpilaD *p) {
    *p = NULL;
}
