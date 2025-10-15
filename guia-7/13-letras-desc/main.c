#include <stdio.h>
#include <stdlib.h>
#define MAX 32

typedef char TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
void genvec(arbol a, char vec[MAX], int *n);

int main(){
    arbol a;
    char vec[MAX];
    int n=0, i;
    addnodo(&a, 'h');
    addnodo(&a->izq, 'c');
    addnodo(&a->izq->izq, 'a');
    addnodo(&a->izq->der, 'd');

    addnodo(&a->der, 'z');
    addnodo(&a->der->izq, 'i');
    addnodo(&a->der->izq->der, 'j');

    genvec(a, vec, &n);

    for (i=0; i < n; i++)
        printf("%c", vec[i]);
    printf("\n");

 return 0;

}

void genvec(arbol a, char vec[], int *n){
    if (a != NULL){
        genvec(a->der, vec, n);
        vec[(*n)] = a->dato;
        (*n)++;
        genvec(a->izq, vec, n);
    }
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

/*
Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente.
*/

