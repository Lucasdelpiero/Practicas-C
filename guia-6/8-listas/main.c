#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Parte Lista doble

typedef struct nodoD {
    char dato;
    struct nodoD *sig, *ant;
} nodoD;

typedef nodoD * Pnodo;

typedef struct nodoLD {
    Pnodo pri, ult;
} nodoLD;

typedef nodoLD * TLD;

void insertaLD(TLD * L, char x);
void mostrarLD(TLD L);
int cantVocalesLD(TLD L);
int estaOrdenadaLD(TLD L);
void eliminaLD(TLD * L, int p);

// Parte Lista circular

typedef struct nodoC {
    char dato;
    struct nodoC *sig;
} nodoC;

typedef nodoC * TLC;

void insertaLC(TLC * L, char x);
void mostrarLC(TLC L);
int cantVocalesLC(TLC L);
int estaOrdenadaLC(TLC L);
void eliminaLC(TLC * L, int p);


int main()
{
    // Lista doble
    printf("Lista doble\n");
    TLD LD = NULL;

    insertaLD(&LD, 'a');
    insertaLD(&LD, 'c');
    insertaLD(&LD, 'e');
    insertaLD(&LD, 'f');
    insertaLD(&LD, 'i');

    mostrarLD(LD); // a
    printf("La cant de vocales es: %d\n", cantVocalesLD(LD)); // b
    if (estaOrdenadaLD(LD))
        printf("La lista esta ordenada\n");
    else
        printf("La lista NO esta ordenada\n");

    eliminaLD(&LD, 3);
    mostrarLD(LD);
    eliminaLD(&LD, 0);
    mostrarLD(LD);


    // Lista circular
    printf("\nLista circular\n");
    TLC LC = NULL;

    insertaLC(&LC, 'a');
    insertaLC(&LC, 'c');
    insertaLC(&LC, 'e');
    insertaLC(&LC, 'f');
    insertaLC(&LC, 'i');

    mostrarLC(LC); // a
    printf("La cant de vocales es: %d\n", cantVocalesLC(LC)); // b

    if (estaOrdenadaLC(LC))
        printf("La lista esta ordenada\n");
    else
        printf("La lista NO esta ordenada\n");


    eliminaLC(&LC, 3);
    mostrarLC(LC);
    eliminaLC(&LC, 0);
    mostrarLC(LC);



    return 0;
}

// Parte Lista doble

void insertaLD(TLD * L, char x){
    TLD Laux = *L, *Ltemp;
    Pnodo aux;
    aux = (Pnodo) malloc(sizeof(nodoD));
    aux->dato = x;

    if (*L == NULL) {
        Ltemp = (TLD) malloc(sizeof(nodoLD));
        *L = Ltemp;
        Laux = *L;
        aux->ant = NULL;
        aux->sig = NULL;
        Laux->pri = aux;
        Laux->ult = aux;
    } else {
        aux->sig = Laux->pri;
        aux->sig->ant = aux; // nueva linea
        aux->ant = NULL;
        (*L)->pri->ant = aux;
        (*L)->pri = aux;
    }
}


void mostrarLD(TLD L){
    TLD Laux = L;
    Pnodo aux = Laux->pri;
    while(aux != NULL){
        printf("%c ", aux->dato);
        aux = aux->sig;
    } printf("\n");
}

int cantVocalesLD(TLD L) {
    Pnodo aux = L->pri;
    char letra;
    int cant = 0;
    while (aux != NULL){
        letra = tolower(aux->dato);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
            cant++;
        aux = aux->sig;
    }
    return cant;
}

int estaOrdenadaLD(TLD L){
    TLD aux = L;
    Pnodo act = aux->pri;
    int ordenado = 1;
    if (act != NULL){
        act = act->sig;
        while(act != NULL && ordenado){
            if (act->ant->dato < act->dato)
                ordenado = 0;
            act = act->sig;
        }
    }
    return ordenado;
}

void eliminaLD(TLD * L, int p) {
    TLD Laux = *L;
    Pnodo aux = Laux->pri;
    int cont = 0;

    while(aux != NULL && cont < p){
        aux = aux->sig;
        cont++;
    }

    if (aux != NULL){
        if (aux == Laux->pri){ // Primero
            Laux->pri = aux->sig;
            Laux->pri->ant = NULL;

        } else
            if (aux == Laux->ult){ // Ultimo
                Laux->ult = Laux->ult->ant;
                Laux->ult->sig = NULL;
            }
        else {
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
            //printf("%p\n", &aux->sig->ant);
            //printf("%p\n" &aux->ant);
            //aux->sig->ant = aux->ant;

        }

        free(aux);
    }
}

// Parte Lista circular

void insertaLC(TLC * L, char x){
    TLC aux = *L;
    TLC nuevo = (TLC) malloc(sizeof(nodoC));
    nuevo->dato = x;
    nuevo->sig = NULL;
    if (*L == NULL){ // Vacio
        aux = nuevo;
        *L = nuevo;
        nuevo->sig = nuevo;
    } else { // No vacio
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
        aux = nuevo;
    }
}

void mostrarLC(TLC L) {
    TLC act ;
    if(L != NULL){
        act = L->sig;
        while(act != L){ // Preguntar si es mejor el while o el do while
            printf("%c ", act->dato);
            act = act->sig;
        }
        printf("%c ", act->dato);

        /*
        act = L;
        do{
            act = act->sig;
            printf("%c ", act->dato);
        } while(act != L);
        */
    }
    printf("\n");
}
int cantVocalesLC(TLC L) {
    TLC act = L;
    int cant = 0;
    char letra;
    if(act != NULL){
        do{
            act = act->sig;
            letra = tolower(act->dato);
            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
                cant++;
        } while(act != L);
    }
    return cant;
}

int estaOrdenadaLC(TLC L) {
    TLC ant, act = L;
    int ordenada = 1;
    if(act != NULL){
        act = L;
        ant = act->sig;      // CLAVEE
        act = act->sig->sig; // CLAVEEEEE

        /*
        El orden de la lista es:  i f e c [a] con a de cabecera
        Por eso el ANT debe darle al sig y
        el ACT debe ir a la f haciendo 2 sig;
        */
        while(act != L && ordenada ){
            if(ant->dato < act->dato)
                ordenada = 0;
            ant = act;
            act = act->sig;
        }
    }
    return ordenada;
}

void eliminaLC(TLC * L, int p){
    TLC ant, act, aux;
    int cont = 0;
    if(*L != NULL){
        act = *L;
        ant = act;
        act = act->sig;
        while(cont < p ){
            ant = act;
            act = act->sig;
            cont++;
        }
        if(act == act->sig ) {   // Queda vacio
            *L = NULL;
        } else {                // No queda vacio
            if (act == *L) {     // Modifico cabeza
                aux = act->sig;
                while(aux != act){
                    ant = aux;
                    aux = aux->sig;
                }
                ant->sig = act;
                *L = act->sig;
            }
            if (ant != NULL)
                ant->sig = act->sig;
        }

        free(act);
    }
}


