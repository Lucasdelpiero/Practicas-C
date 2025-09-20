#include "colas.h"
#include <stdlib.h>
#include <string.h>

TelemC creaC(char * apellido, char * nombre) {
    TelemC temp;
    strcpy(temp.apellido, apellido);
    strcpy(temp.nombre, nombre);
    return temp;
}

char inicialC(TelemC * elem){
    char apellido[50];
    TelemC copia = *elem;
    strcpy(apellido, (*elem).apellido );
    char caracter = (*elem).apellido[0];
    return (*elem).apellido[0];
}

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

// Cola circular

void poneCc (TcolaE*C, TelemC X) {
    if (!((*C).ult==MAX_CE-1 && (*C).pri==0 || (*C).ult+1==(*C).pri) ) {
        if ((*C).pri==-1){
            (*C).pri = 0;
            (*C).ult = 0;
        }
        else
            if ((*C).ult == MAX_CE-1)
                (*C).ult = 0;
    else
        (*C).ult += 1;
    (*C).datos[(*C).ult]=X;
    }
}

void sacaCc (TcolaE *C, TelemC *X) {
    if ((*C).pri != -1) {
        *X = (*C).datos[(*C).pri];
        if ((*C).pri == (*C).ult)
            iniciaCe(C);
        else
            if ((*C).pri == MAX_CE-1)
                (*C).pri = 0;
    else
        (*C).pri += 1;
    }
}


