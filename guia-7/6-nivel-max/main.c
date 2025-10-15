#include <stdio.h>
#include <stdlib.h>

#define MAX 32

typedef char TElememtoA[MAX];
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
int maxNivel(arbol a, int nivelAct);

int main(){
    arbol a;
    addnodo(&a, "Alf");
    addnodo(&a->izq, "Peso");
    addnodo(&a->izq->izq, "No");
    addnodo(&a->izq->der, "Supercalifragilistico");

    addnodo(&a->der, "Panqueque");
    addnodo(&a->der->izq, "Messi");
    addnodo(&a->der->izq->der, "Wesssa");

    printf("El nivel maximo es: %d\n", maxNivel(a, 1));


    return 0;

}

int maxNivel(arbol a, int nivelAct){
    int auxIzq, auxDer, max;
    if (a == NULL){
        return 0;
    } else {
        auxIzq = maxNivel(a->izq, nivelAct + 1);
        auxDer = maxNivel(a->der, nivelAct + 1);
        if (nivelAct > auxIzq && nivelAct > auxDer)
            max = nivelAct;
        else
            if (auxIzq > nivelAct && auxIzq > auxDer)
                max = auxIzq;
            else
                max = auxDer;
        return max;
    }
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    strcpy((*a)->dato, e);
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

/*
 Dado un árbol binario de cadenas de caracteres retornar el nivel en el que se encuentra la
cadena más larga que comienza con A
*/
