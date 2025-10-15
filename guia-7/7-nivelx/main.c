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
int sumaNivelx(arbol a, int nivelAct, int x);

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

    printf("Ingrese X\n");
    scanf("%d", &x);
    printf("La suma del nivel %d es %d\n", x, sumaNivelx(a,1, x));

 return 0;

}

int sumaNivelx(arbol a, int nivelAct, int x){
    if(a != NULL){
        if (nivelAct < x) {
            return sumaNivelx(a->izq, nivelAct + 1, x) + sumaNivelx(a->der, nivelAct + 1, x);
        } else
            if (nivelAct == x) {
                if( (a->izq == NULL && a->der != NULL) || (a->izq != NULL && a->der == NULL) )
                    return a->dato;
                else
                    return 0;
            }
    } else
        return 0;
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

/*
Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato.
*/
