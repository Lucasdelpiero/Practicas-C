#include "pilad.h"
#include <stdio.h>
#include <stdlib.h>

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
