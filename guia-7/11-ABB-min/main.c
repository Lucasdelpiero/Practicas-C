#include <stdio.h>
#include <stdlib.h>

#define ERROR 9999

typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
int min(arbol a);

int main(){
    arbol a;
    int x;
    addnodo(&a, 5);
    addnodo(&a->izq, 3);
    addnodo(&a->izq->izq, 1);
    addnodo(&a->izq->der, 4);

    addnodo(&a->der, 8);
    addnodo(&a->der->izq, 6);
    addnodo(&a->der->izq->der, 7);

    printf("El valor min del arbol es: %d", min(a));

    return 0;

}

int min(arbol a){
    if (a != NULL){
        if(a->izq == NULL)
            return a->dato;
        else
            return min(a->izq);
    } else
        return ERROR;
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
