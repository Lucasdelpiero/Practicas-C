#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;

typedef struct nodo{
        TElememtoA dato;
} NODO;
typedef NODO * arbol;

typedef arbol pos;

int vacio(arbol a);
int nulo(pos p);
pos hijoMasIzq(pos p, arbol a);
pos hermanoDer(pos p, arbol a);
TElememtoA info(pos p, arbol a);
pos raiz(arbol a);
pos padre(arbol a);

int cantNodos(arbol a, pos p); // a
float porcentajePares(arbol a, pos p, int *total, int *pares); // b
int grado(arbol a, pos p); // c
int grYnivImpar(arbol a, pos p,int nivel); // d
void numEhijos(arbol a, pos p, int * cumple); // e
int numEhijosI(arbol a, pos p); // e
void promNivelK(arbol a, pos p, int k, int nivelAct, int *total, int *cant);

int main(){
    arbol a;


 return 0;

}

// a
int cantNodos(arbol a, pos p) {
    int cant = 0;
    pos aux;
    if (!nulo(p)){
        cant++;
        aux = hijoMasIzq(p, a);
        while (aux != NULL){
            cant+= cantNodos(a, p);
            aux = hermanoDer(p, a);
        }
    }
    return cant;

}

// b
float porcentajePares(arbol a, pos p, int *total, int *pares){
    pos aux;
    if (p != NULL){
        if (!nulo(p)){
            (*total)++;
            if (p->dato % 2 == 0)
                (*pares)++;
            aux = hijoMasIzq(p, a);

            while (aux != NULL){
                (*total)++;
                if (p->dato % 2 == 0)
                    (*pares)++;
                aux = hermanoDer(p, a);
            }

        }
    }
    if (p == a && (*total) > 0 )
        return *pares * 1.0 / *total;
    else
        return -1.0;
}

// c
int grado(arbol a, pos p) {
    int maxGrado = 0, gr = 0;;
    pos aux;
    if (p != NULL){
        aux = hijoMasIzq(p, a);
        while (aux != NULL){
            gr++;
            maxGrado = grado(p, a);
            aux = hermanoDer(p, a);
        }
    }
    if (gr >= maxGrado)
        return gr;
    else
        return maxGrado;
}

// d
int grYnivImpar(arbol a, pos p,int nivel){
    pos aux;
    int gr = 0, esImpar = 0;
    if (p != NULL){
        gr = grado(a, p);
        if (gr % 2 != 0 && nivel % 2 != 0 )
            esImpar = 1;
        return esImpar + grYnivImpar(a, hijoMasIzq(p, a), nivel + 1) + grYnivImpar(a, hermanoDer(p, a), nivel);
    } else
        return 0;
}

void numEhijos(arbol a, pos p, int * cumple) {
    pos aux;
    if (p != NULL) {
        aux = hijoMasIzq(p, a);
        while (aux != NULL && *cumple){
            numEhijos(a, p, cumple, gr, hijos);
            aux = hermanoDer(p, a);
        }
        gr = grado(a, p);
        if (p->dato != gr)
            *cumple = 0;
    }
}

// e
int numEhijosI(arbol a, pos p){
    if (p != NULL){
        return ( p->dato == grado(a, p) && numEhijosI(a, hijoMasIzq(p, a)) && numEhijosI(a, hermanoDer(p, a)) );
    } else
        return 1;
}

// f
void promNivelK(arbol a, pos p, int k , int nivelAct, int *total, int *cant){
    pos aux;
    if (p != NULL){
        if (k == nivelAct){
            *total += p->dato;
            (*cant)++;
        }

        aux = hijoMasIzq(p, a);
        promNivelK(a, aux, k, nivelAct + 1, total, cant);
        while (aux != NULL){
            if (k == nivelAct){
                *total += aux->dato;
                (*cant)++;
            }
            aux = hermanoDer(p, a);
        }

    }
}

/*
23. Dado un árbol N-ario de enteros, desarrollar funciones utilizando TDA N.ARIO para:
a) retornar la cantidad de nodos que posee.
b) hallar el porcentaje de claves pares
c) retornar su grado
d) hallar la cantidad de nodos de grado impar que hay en niveles impares.
e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
a la cantidad de hijos. (función int y función void)
f) obtener el promedio de las claves del nivel K (dato)
*/
