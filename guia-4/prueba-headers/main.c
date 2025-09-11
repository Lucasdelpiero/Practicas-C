#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

int main()
{
    char nombre[MAX_LONG_NOMBRE], apellido[MAX_LONG_NOMBRE];
    persona P;
    printf("Ingrese su nombre:\n");
    gets(nombre);
    printf("Ingrese su apellido:\n");
    gets(apellido);
    P = NuevaPersona(nombre, apellido);
    MostrarNombreCompleto(P);

    return 0;
}
