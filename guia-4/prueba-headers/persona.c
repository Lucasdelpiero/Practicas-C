#include <stdio.h>
#include <string.h>
#include "persona.h"

persona NuevaPersona(char nombre[MAX_LONG_NOMBRE], char apellido[MAX_LONG_NOMBRE])
{
    persona P;
    strcpy(P.nombre, nombre);
    strcpy(P.apellido, apellido);
    return P;
}

void MostrarNombreCompleto(persona P)
{
    printf("%s %s", P.nombre, P.apellido);
}
