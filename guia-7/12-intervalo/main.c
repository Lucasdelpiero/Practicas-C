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
void cantIntervalo(arbol a, int A, int B, int *cant);

int main(){
    arbol a;
    int A, B, cant = 0;
    /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, 5);
    addnodo(&a->izq, 3);
    addnodo(&a->izq->izq, 1);
    addnodo(&a->izq->der, 2);

    addnodo(&a->der, 8);
    addnodo(&a->der->izq, 6);
    addnodo(&a->der->izq->der, 9);
    printf("Ingrese A\n");
    scanf("%d", &A);
    printf("Ingrese B\n");
    scanf("%d", &B);
    cantIntervalo(a, A, B, &cant);
    printf("La cantidad dentro del intervalo (%d, %d) es: %d\n", A, B, cant);

    return 0;

}

void cantIntervalo(arbol a, int A, int B, int *cant){
    if(a != NULL){
        if (a->dato > A && a->dato < B)
            (*cant)++;
        cantIntervalo(a->izq,A,B,cant);
        cantIntervalo(a->der,A,B,cant);
    }
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
