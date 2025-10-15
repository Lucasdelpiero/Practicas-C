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
void profundidad(arbol a, int profAct,int *prof);
int masLarga(arbol a);
void cantHijosDer(arbol a, int *cant);

int main(){
     arbol a;
     int prof = 0, largo, cantDer = 0;

     addnodo(&a, "Alf");
     addnodo(&a->izq, "Peso");
     addnodo(&a->izq->izq, "No");
     addnodo(&a->izq->der, "Supercalifragilistico");

     addnodo(&a->der, "Panqueque");
     addnodo(&a->der->izq, "Messi");
     addnodo(&a->der->izq->der, "Wesssa");

     profundidad(a, 0,&prof);
     printf("La prof es de %d\n", prof);
     masLarga(a);
     printf("La palabra mas larga es de %d caracteres\n", masLarga(a));
     cantHijosDer(a, &cantDer);
     printf("Hay %d hijos derechos\n", cantDer);

 return 0;

}

void profundidad(arbol a, int profAct, int *prof){
    if (a != NULL){
        profAct+=1;
        if (profAct > *prof);
            *prof = profAct;
        profundidad(a->izq, profAct , prof);
        profundidad(a->der, profAct , prof);
    }
}

int masLarga(arbol a){
    int auxizq, auxder, auxact, max;
    char palabra[MAX];
    if (a != NULL){
        strcpy(palabra, a->dato);
        int aux1 = masLarga(a->izq);
        int aux2 = masLarga(a->der);
        auxact = strlen(a->dato);
        if (auxact > aux1 && auxact > aux2)
            max = auxact;
        else
            if (aux1 > auxact && aux1 > aux2)
                max = aux1;
            else
                max = aux2;

        return max;
    } else {
        return 0;
    }
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    strcpy((*a)->dato, e);
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cantHijosDer(arbol a, int *cant){
    if (a != NULL){
        if (a->der != NULL)
            (*cant) +=1;
        cantHijosDer(a->izq, cant);
        cantHijosDer(a->der, cant);
    }
}

/*
Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario
*/
