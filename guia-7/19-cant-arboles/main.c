#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
int cantArboles(arbol a);

int main(){
    arbol a;
    int x;
    /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, 5);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 6);

    addnodo(&a->der, 4);
    addnodo(&a->der->izq, 1);
    addnodo(&a->der->izq->der, 2);
    addnodo(&a->der->der, 58);


    printf("El arbol provenia de %d arboles\n", cantArboles(a));

 return 0;

}

int cantArboles(arbol a){
    arbol aux = a;
    int cant = 0;
    if (aux!= NULL){
        cant++;
        while(aux->der != NULL){
            aux = aux->der;
            cant++;
        }
    }
    return cant;
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
