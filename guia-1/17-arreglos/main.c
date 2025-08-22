#include <stdio.h>
#include <stdlib.h>

// Inicializar hace que todo espacio que no se asigna valor se inicialice en 0
int v1[4] = {0};        // 0 0 0 0
int v2[5] = {6};        // 6 0 0 0
int v3[] = {2, 4, 6};   // 2 4 6


// CADENA != ARREGLO DE CARACTERE
/*  Un arreglo de caracteres es un subconjunto de una cadena, la cadena REQUIERE, que al final tenga un \0
    para indicar que la cadena termina ahi.
    Las funciones que trabajan cadenas requieren que contengan \0 para funcionar
*/
char s1[4] = {'h', 'o', 'y'};           // Correcto, inicializar agrega \0;
char s2[] = {'h', 'o', 'y'};            // Incorrecto, toma solo 3 espacios y no deja espacio para el \0
char s3[4] = {'h', 'o', 'y', '\0'};     // Correcto

unsigned int i;

int main()

{
    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("%s\n", s3);

    return 0;
}
