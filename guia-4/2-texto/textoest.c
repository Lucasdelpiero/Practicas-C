#include "textoest.h"
#include <stdio.h>


Ttexto crear(char *c) {
    Ttexto texto;
    texto.tam = 0;
    char *ptr = c;

    while(*ptr != '\0') {
        texto.texto[texto.tam] = *ptr;
        texto.tam++;
        ptr++;
    }

    return texto;
}
/*
void destruir(Ttexto t) {
    t.tam = 0;
}
*/

int tam(Ttexto t) {
    return t.tam;
}
void imprimir(Ttexto t){
    int i;
    for(i=0; i < t.tam; i++){
        printf("%c", t.texto[i]);
    } printf("\n");
}
//void imprimirArch(Ttexto t, FILE * arch);

char caracterEn(Ttexto t, int pos){
    return t.texto[pos];
}

Ttexto concatenar(Ttexto t1, Ttexto t2) {
    Ttexto t3;
    int i;
    t3.tam = 0;
    for(i = 0; i < t1.tam; i++){
        t3.texto[i] = t1.texto[i];
        t3.tam++;
    };
    for(i = 0; i < t2.tam; i++){
        t3.texto[t3.tam] = t2.texto[i];
        t3.tam++;
    }
    return t3;
}
Ttexto reemplazar(Ttexto t, char c, char nc);
Ttexto subTexto(Ttexto t, int deste, int hasta);
int comienzaCon(Ttexto t, Ttexto pref);
int terminaCon(Ttexto t, Ttexto suf);
