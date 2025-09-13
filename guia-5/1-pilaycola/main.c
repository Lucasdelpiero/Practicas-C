#include <stdio.h>
#include <stdlib.h>
#include "pilae.h"
#include "pilad.h"
#include "colae.h"
#include "colad.h"

int main()
{
    TpilaE Pe;
    TpilaD Pd;
    TcolaE Ce;
    TcolaD Cd;
    iniciaPe(&Pe);
    iniciaPd(&Pd);
    iniciaCe(&Ce);
    iniciaCd(&Cd);
    int num, x;
    do {
      printf("Ingrese num a agregar a la pila/cola o 0 pasa salir:\n");
      scanf("%d", &num);
      if (num != 0)
        poneCd(&Cd, num);
        //ponePd(&Pd, num);
        //ponePe(&Pe, num);

    } while (num != 0);

    do {
        printf("Si queres sacar un numero presiona 1, sino 0 y salis del menu\n");
        scanf("%d", &num);
        if (num){
            if (!vaciaCd(Cd)) {
                sacaCd(&Cd, &x);
                printf("Sacaste el num %d\n", x);
            } else {
                printf("La pila/cola esta vacia, no se pueden sacar elementos");
                num = 0;
            }
        }
    } while (num);

    return 0;
}
