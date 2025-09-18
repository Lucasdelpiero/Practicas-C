#include "pilae.h"


void ponePe(TpilaE *p, TelemPe x) {
    if(p->tope != MAX_PE - 1){
        p->tope++;
        p->datos[p->tope] = x;
    }
}

void sacaPe(TpilaE *p, TelemPe *x){
    if (p->tope !=-1)
        *x = p->datos[p->tope--];
}

TelemPe consultaPe(TpilaE p){
    if (p.tope != -1)
        return p.datos[p.tope];
}

int vaciaPe(TpilaE p){
    return p.tope == -1;
}

void iniciaPe(TpilaE *p){
    p->tope = -1;
}
