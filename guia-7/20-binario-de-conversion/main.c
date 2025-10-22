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
int cantNivImpares(arbol a, int nivel); // a
void totalK(arbol a, int k, int * total, int * cant); // b
int grado(arbol a);
void altura(arbol a, int actAlt,int *maxAlt);
int alturaInt(arbol a);
int maxGrado(arbol a);
void mGrado(arbol a, int *max);

int main(){
    arbol a;
    int k, total = 0, cant = 0, alt = 0, mGrad = 0;

    addnodo(&a, 13);
    addnodo(&a->izq, 1);
    addnodo(&a->izq->izq, 8);
    addnodo(&a->izq->der, 19);

    addnodo(&a->izq->der->izq, 12);
    addnodo(&a->izq->der->izq->izq, 14);
    addnodo(&a->izq->der->izq->der, 22);
    addnodo(&a->izq->der->izq->der->der, 26);
    addnodo(&a->izq->der->izq->der->der->izq, 24);
    addnodo(&a->izq->der->izq->der->der->izq->der, 44);
    addnodo(&a->izq->der->izq->der->der->izq->der->der, 54);

    addnodo(&a->izq->der->der, 40);
    addnodo(&a->izq->der->der->der, 70);
    addnodo(&a->izq->der->der->der->izq, 15);
    addnodo(&a->izq->der->der->der->izq->der, 38);

    printf("Cant en niv impares: %d\n", cantNivImpares(a, 1));
    do {
      printf("Ingrese K a buscar :\n");
      scanf("%d", &k);
    } while (k < 0);

    totalK(a, k, &total, &cant);
    if (cant == 0)
        printf("No hay ningun nodo de tal grado\n");
    else
        printf("El promedio era %.1f\n", total * 1.0 / cant );

    altura(a, 1, &alt);
    printf("La altura del arbol original era: %d\n", alt);
    printf("La altura del arbol original era: %d\n", alturaInt(a));

    mGrado(a, &mGrad);
    //printf("El grado del arbol original es: %d\n", mGrad);
    printf("El grado del arbol original es: %d\n", maxGrado(a));

    return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

// a
int cantNivImpares(arbol a, int nivel){
    if (a == NULL)
        return 0;
    else
        return  (nivel % 2 != 0) + cantNivImpares(a->izq, nivel + 1) + cantNivImpares(a->der, nivel);

}

// b
void totalK(arbol a, int k, int * total, int * cant){
    if (a != NULL) {

        if (k == grado(a) ) {
            (*total) += a->dato;
            (*cant)++;
            }

        totalK(a->izq, k, total, cant);
        totalK(a->der, k, total, cant);
        }
}


int grado(arbol a) {
    //int ini = a->dato;
    int cont = 0;
    if (a != NULL && a->izq != NULL){
        a = a->izq;
        while (a != NULL){
            cont++;
            a = a->der;
        }
    }
    //printf("El nodo %d tenia %d hijos\n", ini, cont);
    return cont;
}


// c
void altura(arbol a, int actAlt,int *maxAlt){
    if (a != NULL){
        if (actAlt > *maxAlt)
            *maxAlt = actAlt;
        if (a->izq != NULL) {
            altura(a->izq, actAlt + 1, maxAlt);
        }
        altura(a->der, actAlt, maxAlt);
    }
}

int alturaInt(arbol a) {
    int subIzq, subDer;
    if (a == NULL)
        return 0;
    else
        if (a->izq == NULL)
            return alturaInt(a->der);
        else {
            subIzq = alturaInt(a->izq) + 1;
            subDer = alturaInt(a->der);
            if (subIzq > subDer)
                return subIzq;
            else
                return subDer;
        }
}

// d
int maxGrado(arbol a) {
    int maxIzq, maxDer, gradoAct;
    if (a == NULL)
        return 0;
    else {
        maxIzq = maxGrado(a->izq);
        maxDer = maxGrado(a->der);
        gradoAct = grado(a);
        if (gradoAct > maxIzq && gradoAct > maxDer)
            return gradoAct;
        else
            if (maxIzq > maxDer)
            return maxIzq;
        else
            return maxDer;
    }
}

// d con void
void mGrado(arbol a, int *max) {
    int gr;
    if (a != NULL){
        mGrado(a->izq, max);
        mGrado(a->der, max);
        gr = grado(a);
        if (gr > *max)
            *max = gr;
    }
}

/*
20. Dado un árbol binario proveniente de la conversión de un árbol general:
a) hallar la cantidad de nodos que habia en niveles impares.
b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
c) obtener la altura del árbol original
d) determinar el grado del árbol original
*/
