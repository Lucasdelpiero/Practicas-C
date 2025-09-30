#include <stdio.h>
#include <stdlib.h>

typedef struct circ {
    int num;
    struct circ * sig;
} Tcirc;

int main()
{
    printf("Hello world!\n");
    return 0;
}

void muestra(Tlista LC) {
 Tlista aux;
 aux = LC;

 if (LC != NULL){
    printf("%d ", aux->num);
    while(aux != LC) {
        printf("%d ", aux->num);
        aux = aux->sig;
    }
 }
}

void borraDato(Tlista *LC, int x) {
    Tlista aux, ant = NULL;
    aux = *LC;

    if (aux != NULL){
        ant = aux;
        aux = aux->sig;
        while(aux->dato != x && aux!= *LC{
            if(aux->dato == x) {
                if(aux == *LC) { // cabecera FALTA CASO PARA 1 SOLO NODO
                    if (ant->dato == aux->dato) { // CASO 1 SOLO NODO
                        *LC = NULL
                    } else {
                        ant->sig = aux->sig;
                        *LC = ant->sig;
                    }
                } else { // no cabecera
                    ant->sig = aux->sig;
                }
                free(aux);
            }
            aux = aux->sig;
        }
    }
}


void eliminaSV(TLD *L) { // TODO MAL
    TLD aux, elim;

    if(*L != NULL) {
        aux = *L;
        while(aux != NULL){
            if (aux->ventas == 0) {
                if(aux == *L){ // cabecera
                    *L = aux->sig;
                } else
                    if(aux->sig == NULL{ // final
                        aux->ant = aux->sig;
                }
                else { // entre 2
                    aux->ant->sig = aux->sig;
                    aux->sig->ant = aux->ant;
                }
            }
            elim = aux;
            aux = aux->sig;
            free(elim);
        } else {
            aux = aux->sig;
        }

    }
}
