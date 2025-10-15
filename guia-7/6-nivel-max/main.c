#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 32

typedef char TElememtoA[MAX];
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
int maxNivel(arbol a, int nivelAct, int *masLarga);

int main(){
    arbol a;
    int masLarga=0;
    addnodo(&a, "Alf");
    addnodo(&a->izq, "Peso");
    addnodo(&a->izq->izq, "No");
    addnodo(&a->izq->der, "Supercalifragilistico");

    addnodo(&a->der, "Pan");
    addnodo(&a->der->izq, "Azar");
    addnodo(&a->der->izq->der, "Aves");

    printf("El nivel maximo es: %d\n", maxNivel(a, 1, &masLarga));


    return 0;

}

int maxNivel(arbol a, int nivelAct, int *masLarga){
    int auxIzq, auxDer, nivel = 0, largoAct=0;
    if (a == NULL){
        return 0;
    } else {
        if (toupper((a->dato)[0]) == 'A')
            largoAct = strlen(a->dato);

        if (largoAct > *masLarga){
            *masLarga = largoAct;
            nivel = nivelAct;
        }

        auxIzq = maxNivel(a->izq, nivelAct + 1, masLarga);
        auxDer = maxNivel(a->der, nivelAct + 1, masLarga);

        if (auxIzq > nivel && auxIzq > auxDer)
            return auxIzq;
        else
            if(auxDer > nivel && auxDer > auxIzq)
                return auxDer;
            else
                return nivel;

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
