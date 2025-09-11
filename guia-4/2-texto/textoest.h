#ifndef HEADER_2228B98D7434A73E
#define HEADER_2228B98D7434A73E
#endif // header guard

#define MAX_TEXT 100


typedef struct {
    char texto[MAX_TEXT];
    int tam;
} Ttexto;


Ttexto crear(char *c);
void destruir(Ttexto t);
int tam(Ttexto t);
void imprimir(Ttexto t);
//void imprimirArch(Ttexto t, FILE * arch);
char caracterEn(Ttexto t, int pos);
Ttexto concatenar(Ttexto t1, Ttexto t2);
Ttexto reemplazar(Ttexto t, char c, char nc);
Ttexto subTexto(Ttexto t, int deste, int hasta);
int comienzaCon(Ttexto t, Ttexto pref);
int terminaCon(Ttexto t, Ttexto suf);
