#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32
#define SEED 4
#define MAYORIA_EDAD 18

typedef struct {
        char nombre[MAX];
        unsigned int edad;
    } Persona;

void generaPersonas(Persona vec[MAX], unsigned int n, char nombres[MAX][MAX]);
void leerPersonas(Persona vec[MAX], unsigned int n);
void superaEdad(Persona vec[MAX], unsigned int n, unsigned int x);
float porcentajeMayores(Persona vec[MAX], unsigned int n);

int main()
{
    srand(SEED);
    unsigned int n, x;
    char nombres[MAX][MAX] = {"Jorge","Alf","Nico","Juan","Rigoberto","Lucia","Flipendo","Manolo","Goku","Naruto","Pedro","Bulma"};
    float porcMayores;

    Persona personas[MAX];

    printf("Cuantas personas quiere cargar\n");
    scanf("%u", &n);
    generaPersonas(personas, n, nombres);
    leerPersonas(personas, n);

    printf("Ingrese X de edad a superar\n");
    scanf("%u", &x);

    superaEdad(personas, n, x);
    porcMayores = porcentajeMayores(personas, n);
    printf("El porcentaje de mayores de edad es: %5.2f%c", porcMayores,'%');

    return 0;
}

void generaPersonas(Persona vec[MAX], unsigned int n, char nombres[MAX][MAX]){
    unsigned int i;
    for(i=0; i < n; i++){
        strcpy(vec[i].nombre, nombres[i]);
        vec[i].edad = rand() % 80;
    }
}

void leerPersonas(Persona vec[MAX], unsigned int n){
    unsigned int i;
    printf("%32s %12s\n","Nombre", "Edad");
    for(i=0; i < n; i++){
        printf("%32s  %10u\n", vec[i].nombre, vec[i].edad);
    }
}

void superaEdad(Persona vec[MAX], unsigned int n, unsigned int x){
    unsigned int i;
    printf("Lista de mayores de %u:\n",x);
    printf("%32s %12s\n","Nombre", "Edad");
    for(i=0; i < n; i++){
        if(vec[i].edad > x){
            printf("%32s  %10u\n", vec[i].nombre, vec[i].edad);
        }
    }
}

float porcentajeMayores(Persona vec[MAX], unsigned int n) {
    unsigned int i, cant=0;
    for(i=0; i<n; i++){
        if(vec[i].edad >= MAYORIA_EDAD){
            cant++;
        }
    }
    return ((float)cant / n) * 100;
}



