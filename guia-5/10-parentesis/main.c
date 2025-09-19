#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void ingresaDatos(TpilaD *p);

int main()
{
    TpilaD p;
    iniciaPd(&p);
    ingresaDatos(&p);
    return 0;
}

void ingresaDatos(TpilaD *p){
    char dato;
    char ultimoPila;
    do {
        printf("Ingrese dato o 0 para terminar\n");
        gets(&dato);
        if (dato == '(') {
            ponePd(p, dato);
        } else
            if (dato == ')') {
                if (!vaciaPd(*p) ){
                    if (consultaPd(*p) != dato) // ')' se encuentra un '('
                        sacaPd(p, &dato);
                } else { // Hay primero mas ')' que '(', imposible que no falten por izquierda
                    ponePd(p, &dato);
                    dato = '0'; // sale del ciclo
                    }
            }
    } while (dato != '0');

    if (!vaciaPd(*p))
        if (consultaPd(*p) == '(')
            printf("Faltan parentesis por derecha\n");
        else
            printf("Faltan parentesis por izquierda\n");
    else
        printf("No faltan parentesis\n");
}
