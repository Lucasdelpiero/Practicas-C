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
void mostrarGanador(arbol a);
void mostrarFinalistas(arbol a);
void mostrarSemifinalistas(arbol a, int nivelAct);
void mostrarTodos(arbol a);

int main(){
 arbol a;
 int x;
 /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, "Nadal");
    addnodo(&a->izq, "Nadal");
    addnodo(&a->izq->izq, "Nadal");
    addnodo(&a->izq->der, "Nalbandian");

    addnodo(&a->der, "Federer");
    addnodo(&a->der->izq, "Federer");
    addnodo(&a->der->der, "Ruso");
    addnodo(&a->der->izq->der, "Federer");
    addnodo(&a->der->izq->izq, "Pan");
    addnodo(&a->der->der->der, "Ruso");
    addnodo(&a->der->der->izq, "Anonimo");

    mostrarGanador(a);
    mostrarFinalistas(a); printf("\n");
    printf("Los semifinalistas son:\n");
    mostrarSemifinalistas(a, 1); printf("\n");
    printf("Todos los participantes son:\n");
    mostrarTodos(a);



 return 0;

}

void mostrarGanador(arbol a) {
    if (a != NULL)
        printf("El ganador es: %s\n",a->dato);
}

void mostrarFinalistas(arbol a){
    if (a != NULL){
        printf("Los finalistas son %s y %s\n", a->izq->dato, a->der->dato);
    }
}

void mostrarSemifinalistas(arbol a, int nivelAct){
    if (a != NULL){
        if (nivelAct < 3) { // Asi es mas solido  que simplemente buscar su pos en memoria desde la raiz directamente
            mostrarSemifinalistas(a->izq, nivelAct +1);
            mostrarSemifinalistas(a->der, nivelAct +1);
        } else
            printf("%s\n", a->dato);
    }
}

void mostrarTodos(arbol a){
    if(a != NULL){
        if (a->izq == NULL && a->der == NULL)
            printf("%s\n", a->dato);
        else {
            mostrarTodos(a->izq);
            mostrarTodos(a->der);
        }
    }
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    strcpy((*a)->dato, e);
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
