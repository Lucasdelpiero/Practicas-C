#include <stdio.h>
#include <stdlib.h>

typedef int TElememtoA;
typedef struct nodo {
    TElememtoA dato;
    struct nodo *izq, *der;
} nodo;
typedef nodo *arbol;

void addnodo(arbol* a, TElememtoA e);
void sumaMult(arbol a, int num, int *suma);
int cantHojas(arbol a);
void estaX(arbol a, int x, int *esta);

int main()
{
    arbol a=NULL;
    int suma = 0, esta = 0, x;
    addnodo(&a, 5);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 6);

    addnodo(&a->der, 4);
    addnodo(&a->der->izq, 1);
    addnodo(&a->der->izq->der, 2);

    sumaMult(a, 3, &suma);
    printf("La suma de mult de 3 es: %d\n", suma);
    printf("La cant de hojas es de %d\n", cantHojas(a));
    printf("Ingrese X a buscar\n");
    scanf("%d", &x);
    estaX(a, x, &esta);
    if (esta)
        printf("El num %d esta\n", x);
    else
        printf("No esta %d\n", x);
    return 0;
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(nodo));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void sumaMult(arbol a, int num, int *suma){
    if (a != NULL){
        if (a->dato % num == 0)
            (*suma) += a->dato;
        sumaMult(a->izq, num, suma);
        sumaMult(a->der, num, suma);
    }
}

int cantHojas(arbol a){
    if (a == NULL)
        return 0;
    else
        if (a->izq == NULL && a->der == NULL)
            return 1;
        else {
            return cantHojas(a->izq) + cantHojas(a->der);
        }
}

void estaX(arbol a, int x, int *esta){
    if (a != NULL){
        if (a->dato == x)
            *esta = 1;
        if (*esta == 0){
            estaX(a->izq, x, esta);
            if (*esta == 0) // IMPORTANTE asi si lo encuentra a izq no vaya a buscarlo a derecha
                estaX(a->der, x, esta);
        }
    }
}

/*
3. Desarrollar funciones para:
a) devolver la suma de los elementos múltiplos de 3 de un árbol binario.
b) retornar la cantidad de hojas de un árbol binario.
c) informar si un valor recibido como parámetro se encuentra en un árbol binario.
*/
