#include "pilas.h"
#include <stdlib.h>

TelemP creaP( char * nombre) {
    TelemP temp;
    strcpy(temp.nombre, nombre);
    return temp;
}

char inicialP(TelemP * elem){
    return (*elem).nombre[0];
}

void escribeNombre(TelemP elem) {
    printf("%s\n", elem.nombre );
}


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

void ponePd(TpilaD *p, TelemP x){
    TpilaD n;
    n = (TpilaD) malloc(sizeof(nodop));
    n->dato = x;
    n->sig = *p;
    *p = n;
}

void sacaPd(TpilaD *p, TelemP *x){
    TpilaD n;
    if (*p){ // *p != NULL;
        n = *p;
        *x = (*p)->dato;
        *p = (*p)-> sig;
        free(n);
    }
}
TelemP consultaPd(TpilaD p){
    if (p)
        return p->dato;
}

int vaciaPd(TpilaD p) {
    return (p == NULL);
}
void iniciaPd(TpilaD *p) {
    *p = NULL;
}
