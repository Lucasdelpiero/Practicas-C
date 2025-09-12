#include "textodin.h"
#include <stdlib.h>
#include <stdio.h>

TextD crearD(char *c){
    TextD t;
    t.tam = 0;
    while (*(c + t.tam) != '\0' ){
        (t.tam)++;
    }
    t.texto = (char *) malloc(sizeof(char) * t.tam);

    return t;
}

void destruirD(TextD *t){
    free((*t).texto);
    (*t).tam = 0;
}

int tamD(TextD t) {
    return t.tam;
}
void imprimirD(TextD t){
}
/*
void imprimirArchD(TextD t, FILE * arch);
char caracterEnD(TextD t, int pos);
TextD concatenarD(TextD t1, TextD t2);
TextD reemplazarD(TextD t, char c, char nc);
TextD subTextoD(TextD t, int deste, int hasta);
int comienzaConD(TextD t, TextD pref);
int terminaConD(TextD t, TextD suf);
*/
