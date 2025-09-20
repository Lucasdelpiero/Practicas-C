#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "colas.h"
#include "pilas.h"

void cargaNombres(TpilaD * pilasApellidos[30]);
void poneSegunInicial(TpilaD * p, TelemP competidor);
void consultaLetra(TpilaD pilaApellidos[30]);

int main()
{
    TpilaD pilasApellidos[30];
    int i;
    for(i = 0; i< 30; i++){
        iniciaPd(&pilasApellidos[i]);
    }
    cargaNombres(pilasApellidos);
    consultaLetra(pilasApellidos);
    return 0;
}

void consultaLetra(TpilaD pilaApellidos[30]){
    char letra='0';
    TelemP competidor;
    letra = toupper(letra);

    do {
        printf("Ingrese letra a buscar competidores u otro caracter para salir\n");
        scanf(" %c", &letra);
        letra = toupper(letra);
        if (isalpha(letra)){
            if (!vaciaPd(pilaApellidos[letra - 'A'])){
                printf("Comienzan con %c:\n", letra);
                while (!vaciaPd(pilaApellidos[letra - 'A'])) {
                    sacaPd(&pilaApellidos[letra - 'A'], &competidor);
                    escribeNombre(competidor);
                }
            } else {
                printf("Esta vacio para la letra %c\n", letra);
            }
        }

    } while (isalpha(letra));
}

void cargaNombres(TpilaD * pilaApellidos[30]){
    TpilaD competidores;
    TelemP competidor;
    iniciaPd(&competidores);
    char apellido[50];
    char nombre[50];
    FILE *arch;
    arch = fopen("competidores.txt", "r");

    if (arch == NULL) {
        printf("Error al cargar archivo\n");
    } else {
        fscanf(arch, "%s", &nombre);
        while (!feof(arch)){
            competidor = creaP(nombre);
            poneSegunInicial(pilaApellidos, competidor);
            fscanf(arch, "%s", &nombre);
        }
    }
}

void poneSegunInicial(TpilaD * pilaApellidos, TelemP competidor) {
    char inicial;
    TelemP test;
    inicial = inicialP(&competidor);
    inicial = toupper(inicial);
    ponePd(&pilaApellidos[inicial - 'A'], competidor); // A [0] , B [1] etc
}
