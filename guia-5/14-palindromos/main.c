#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "colas.h"

void palindromo(TcolaD * cola, TpilaD * pila, int n,int * esPal);

int main()
{
    TcolaD cola;
    TpilaD pila;
    int n=5, esPal;
    iniciaCd(&cola);
    iniciaPd(&pila);

    poneCd(&cola, 's');
    poneCd(&cola, 'a');
    poneCd(&cola, 'l');
    poneCd(&cola, 'a');
    poneCd(&cola, 's');

    palindromo(&cola, &pila, n, &esPal);

    if (esPal)
        printf("Es palindromo\n");
    else
        printf("No es palindromo\n");

    return 0;
}

void palindromo(TcolaD * cola, TpilaD * pila, int n, int * esPal) {
    int i ,mitad = n / 2;
    char car, temp1, temp2;
    *esPal = 1;         // Fijarse bien de asignar al entero y no al puntero
    for (i=0; i < mitad; i++){
        sacaCd(cola, &car);
        ponePd(pila, car);
    }
    if (n % 2 != 0 ) // saca el elemento impar de la cola
        sacaCd(cola, &car);

    while(!vaciaPd(*pila) && (*esPal) ){
        sacaCd(cola, &temp1);
        sacaPd(pila, &temp2);
        if (temp1 != temp2)
            *esPal = 0;
    }
}
