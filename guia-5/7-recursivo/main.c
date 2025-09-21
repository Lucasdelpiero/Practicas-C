#include <stdio.h>
#include <stdlib.h>
#include "../../librerias/pilas.h"
#include "../../librerias/colas.h"

void mostrarInv(TpilaD * p);
void mostrarOrd(TpilaD * p);

int main()
{
    TpilaD p1, p2;
    iniciaPd(&p1);
    iniciaPd(&p2);
    int n;
    do{
        printf("Ingrese dni\n");
        scanf("%d", &n);
        if (n != 0){
            ponePd(&p1, n);
            ponePd(&p2, n);
        }

    } while (n != 0);

    mostrarInv(&p1);
    mostrarInv(&p1);
    printf("===========\n");
    mostrarOrd(&p2);
    mostrarOrd(&p2);
    return 0;
}

void mostrarInv(TpilaD * p){
    TelemP elem;
    if (!vaciaPd(*p)){
        sacaPd(p, &elem);
        printf("%d\n", elem);
        if (!vaciaPd(*p)){
            mostrarInv(p);
        }
        ponePd(p, elem);
    }
}

void mostrarOrd(TpilaD * p){
    TelemP elem;
    if (!vaciaPd(*p)){
        sacaPd(p, &elem);
        if (!vaciaPd(*p)){
            mostrarOrd(p);
        }
        ponePd(p, elem);
        printf("%d\n", elem);
    }
}


