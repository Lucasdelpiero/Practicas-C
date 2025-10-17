#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void inserta(arbol* a, TElememtoA e);
void inorder(arbol a);

int main(){
     arbol a = NULL;
     /* carga arbol ejemplo. Ej 1 */
     inserta(&a, 5);
     inserta(&a, 8);
     inserta(&a, 3);
     inserta(&a, 6);

     inserta(&a, 4);
     inserta(&a, 1);
     inserta(&a, 2);
     inorder(a);

 return 0;

}

void inserta(arbol* a, TElememtoA e) {
    arbol ant, act;
    arbol aux = (arbol)malloc(sizeof(NODO));
    (aux)->dato = e;
    (aux)->izq = NULL;
    (aux)->der = NULL;

    if (*a == NULL) {
        *a = aux;
    } else {
        act = *a;
        while(act != NULL){
            ant = act;
            if (e < act->dato){
                act = act->izq;
            } else
                act = act->der;
        }
        if (e < ant->dato)
            ant->izq = aux;
        else
            ant->der = aux;

    }
}

void inorder(arbol a) {
    if (a != NULL){
        inorder(a->izq);
        printf("%d ", a->dato);
        inorder(a->der);
    }
}
