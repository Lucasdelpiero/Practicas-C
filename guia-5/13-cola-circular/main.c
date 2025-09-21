#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int Telem;

typedef struct {
    Telem datos[MAX];
    int pri, ult;
} Tcola;

void iniciaC(Tcola * cola);
void poneC(Tcola * cola, Telem elem);
void sacaC(Tcola * cola,Telem * elem);
Telem consultaC(Tcola cola);
int vaciaC(Tcola cola);

int main()
{
    Tcola cola;
    Telem elem;
    iniciaC(&cola);
    do {
        printf("Ingrese datos o 0 para salir\n");
        scanf("%d", &elem);
        if (elem != 0)
            poneC(&cola, elem);
    } while (elem != 0);

    printf("Los elementos ingresados en orden son:\n");
    while (!vaciaC(cola)) {
        sacaC(&cola, &elem);
        printf("%d\n", elem);
    }
    return 0;
}

void iniciaC(Tcola * cola) {
    (*cola).pri = -1;
    (*cola).ult = -1;
}

void poneC(Tcola * cola, Telem elem){
    if ( ((*cola).ult < MAX-1 && (*cola).pri == 0) || (*cola).ult + 1 != MAX) { // Corregido, faltaba ver el pri == 0;
        if ((*cola).pri == - 1){
            (*cola).pri = 0;
            (*cola).ult = 0;
        }
        else
            if ((*cola).ult < MAX - 1)
                (*cola).ult++;
            else
                (*cola).ult = 0;
        (*cola).datos[(*cola).ult] = elem;
    }
}

void poneCOriginal(Tcola * cola, Telem elem){
     if ((*cola).ult < MAX-1 || (*cola).ult + 1 != MAX){ // Hay espacio disponible (falto algo)
        if ((*cola).pri == - 1)
            (*cola).pri = 0;

        if ((*cola).ult < MAX - 1)
            (*cola).ult++;
        else
            (*cola).ult = 0;
        (*cola).datos[(*cola).ult] = elem;
    }
}

void sacaC(Tcola * cola,Telem * elem) {
    if ((*cola).pri != -1){ // Por que necesita comprobar eso, no deberia usarse antes el vaciaC() ????
        *elem = (*cola).datos[(*cola).pri];

        if ((*cola).pri == (*cola).ult)
            iniciaC(cola);
        else
            if((*cola).pri == MAX - 1)
                (*cola).pri = 0;
            else
                (*cola).pri++;
    }
}

void sacaCOriginal(Tcola * cola,Telem * elem) {
    *elem = (*cola).datos[(*cola).pri];
    if((*cola).pri < MAX - 1)
        (*cola).pri++;
    else
        (*cola).pri = 0;
    if ((*cola).pri == (*cola).ult)
        iniciaC(cola);
}


int vaciaC(Tcola cola) {
    return (cola.pri == -1 && cola.ult == -1);
}

Telem consultaC(Tcola cola){
    return cola.datos[cola.pri];
}
