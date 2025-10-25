#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef char TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
int cantAlturaK(arbol a, int k);    // a
int alturaArbol(arbol a);           // a
void genVec(arbol a, int vec[], int *n); // b
char maxArbol(arbol a); // b
int todosGradoK(arbol a, int k); // c
int tieneGradoK(arbol a, int k);

int main(){
    arbol a;
    int k;
    int mayorArbol[MAX] = {'\0'};
    int cantArboles = 0, i;

    addnodo(&a, 'A');

    addnodo(&a->der, 'B');
    addnodo(&a->der->izq, 'C');
    addnodo(&a->der->izq->der, 'D');
    addnodo(&a->der->izq->der->izq, 'E');
    addnodo(&a->der->izq->der->izq->der, 'F');

    // Debajo de la F
    addnodo(&a->der->izq->der->izq->der->izq, 'I');
    addnodo(&a->der->izq->der->izq->der->izq->der, 'J');
    addnodo(&a->der->izq->der->izq->der->izq->der->der, 'K');

    addnodo(&a->der->izq->der->izq->der->der, 'G');
    addnodo(&a->der->izq->der->izq->der->der->der, 'H');

    addnodo(&a->der->der, 'L');
    addnodo(&a->der->der->izq, 'M');
    addnodo(&a->der->der->izq->der, 'N');
    addnodo(&a->der->der->izq->der->izq, 'O');

    printf("Ingrese k\n");
    //scanf("%d", &k)
    k = 0;
    printf("La cantidad de arboles de altura %d son: %d\n", k, cantAlturaK(a, k));
    genVec(a , mayorArbol, &cantArboles);
    printf("\nEl mayor de cada arbol es: \n");
    for(i = 0; i < cantArboles; i++){
        printf("%c ", mayorArbol[i]);
    } printf("\n");
    printf("\nEl arbol tiene a todos de grado %d\n\n", k);

    // Para que sean todos de grado 2
    k = 2;
    addnodo(&a->izq, 'A');
    addnodo(&a->izq->der, 'A');
    if (todosGradoK(a, k))
        printf("Todos los subarboles tienen al menos un subarbol de grado %d\n", k);
    else
        printf("No todos los subarboles tienen al menos un subarbol de grado %d\n", k);


 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

// a
int cantAlturaK(arbol a, int k){
    int altura, cant = 0;
    char dato;
    if (a != NULL){
        while (a != NULL){
            dato = a->dato;
            altura = alturaArbol(a->izq) + (a->izq != NULL);
            if (altura == k)
                cant++;
            a = a->der;
        }
    }
    return cant;
}

// a
int alturaArbol(arbol a){
    if (a == NULL)
        return 0;
    else
        return (a->izq != NULL) + alturaArbol(a->izq) + alturaArbol(a->der) ;
}

// b
void genVec(arbol a, int vec[], int *n) {
    char max;
    while(a != NULL){
        vec[*n] = a->dato;
        max = maxArbol(a->izq);
        if (max > a->dato)
            vec[*n] = max;
        else
            max = a->dato;
        (*n)++;
        a = a->der;
    }
}

// b
char maxArbol(arbol a){
    int aux, maxI, maxD;
    if (a != NULL){
        aux = a->dato;
        maxI = maxArbol(a->izq);
        maxD = maxArbol(a->der);

        if (aux > maxI && aux > maxD)
            return aux;
        else
            if (maxI > aux && maxI > maxD)
                return maxI;
            else
                return maxD;
    } else
        return NULL;
}

// c
int todosGradoK(arbol a, int k){
    int todos = 1;
    while (a != NULL && todos){ // Preguntar por el recorrido del arbol si esta bien
        todos = tieneGradoK(a->izq, k);
        a = a->der;
    }

    return todos;
}

// c
int tieneGradoK(arbol a, int k) {
    int grado = 0;
    int tiene = 0;

    while (a != NULL && !tiene) {
        grado++;
        tiene = tieneGradoK(a->izq, k);
        a = a->der;
    }
    if (grado == k)
        tiene = 1;

    return tiene;
}



/*
Dado un árbol binario que proviene de la transformación de un bosque,
a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada)
b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada).
*/
