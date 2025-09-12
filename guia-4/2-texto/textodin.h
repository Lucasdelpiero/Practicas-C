#ifndef HEADER_34D5E0906C845B6F
#define HEADER_34D5E0906C845B6F
#endif // header guard
#include <stdio.h>
#define MAX_TEXT_D 100

typedef struct {
    char *texto;
    int tam;
} TextD;

TextD crearD(char *c);
void destruirD(TextD *t);
int tamD(TextD t);
void imprimirD(TextD t);
void imprimirArchD(TextD t, FILE * arch);
char caracterEnD(TextD t, int pos);
TextD concatenarD(TextD t1, TextD t2);
TextD reemplazarD(TextD t, char c, char nc);
TextD subTextoD(TextD t, int deste, int hasta);
int comienzaConD(TextD t, TextD pref);
int terminaConD(TextD t, TextD suf);
