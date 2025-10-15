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
void esabb(arbol a, int *es, int minVal, int maxVal);

int main(){
    arbol a;
    int es = 1;

    addnodo(&a, 5);
    addnodo(&a->izq, 3);
    addnodo(&a->izq->izq, 1);
    addnodo(&a->izq->der, 4);

    addnodo(&a->der, 9);
    addnodo(&a->der->izq, 6);
    addnodo(&a->der->izq->der, 7);

    esabb(a, &es, a->dato, a->dato);
    if (es)
        printf("Es ABB");
    else
        printf("No es ABB");

 return 0;

}

void esabb(arbol a, int *es, int minVal, int maxVal){
    if(a != NULL){
        // MOVIENDOSE A IZQ
        if (a->dato > maxVal || a->dato < minVal)
            *es = 0;

        if(a->izq != NULL){
            if (a->dato == minVal ) // Extiende el minimo al mas a la izq del arbol
                minVal = a->izq->dato;
            else
                if (a->izq->dato >= minVal && a->izq->dato <= maxVal) // El minimo esta entre min y max actual
                    minVal = a->izq->dato;
                else
                    *es = 0;

            if (*es == 1)
                esabb(a->izq, es, minVal, maxVal);
        }


        // MOVIENDOSE A DER
        if (*es == 1){  // Haciendo un segundo if me ahorro toda la parte derecha si ya sale por falso a la izquierda
            if (a->dato > maxVal || a->dato < minVal)
                *es = 0;

            if (a->der != NULL ){
                if (a->dato == maxVal)  // Extiende el minimo al mas a la der del arbol
                    maxVal = a->der->dato;
                else
                    if (a->der->dato >= minVal && a->der->dato <= maxVal) // El maximo esta entre min y max actual
                        maxVal = a->der->dato;
                    else
                        *es = 0;

                minVal = a->dato;
                if (*es == 1)
                    esabb(a->der, es, minVal, maxVal);
            }
        }

    }
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
