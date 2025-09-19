#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "colas.h"

int main()
{
    TpilaD p;
    TcolaD c;
    iniciaPd(&p);
    iniciaCd(&c);
    int n;
    do{
        printf("Ingrese dni\n");
        scanf("%d", &n);
        if (n != 0){
            ponePd(&p, n);
            poneCd(&c, n);
        }

    } while (n != 0);

    printf("Orden inverso:\n");

    while(!vaciaPd(p)){
        sacaPd(&p, &n);
        printf("%d\n", n);
    }

    printf("=================\n");

    printf("Orden normal:\n");

    while(!vaciaCd(c)){
        sacaCd(&c, &n);
        printf("%d\n", n);
    }

    return 0;
}
