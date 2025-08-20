#include <stdio.h>
#include <string.h>

#define MAX_CHAR 32
#define CANT_MAT 3

char mejorPromNom[MAX_CHAR], nombre[MAX_CHAR], car;
float mejorProm=0, prom;
unsigned int nota, notaTotal, N, i,j;

int main(){
    printf("Ingrese cantidad de alumnos a evaluar: ");
    scanf("%u", &N);

    for (i=0; i<N; i++){
        printf("Ingrese nombre del alumno:\n");
        scanf("%s", &nombre);
        printf("Ingrese las 3 notas del %s\n", nombre);
        notaTotal= 0;
        for (j=0; j<CANT_MAT; j++){
            scanf("%u", &nota);
            notaTotal += nota;
        }

        // Antes de hacer la division el numero debe ser convertido a tipo float
        // Sino la division se hace entre enteros y redondea antes de asignar a un float
        prom = (float)notaTotal / CANT_MAT;
        printf("%s tiene un promedio de %5.2f \n", nombre, prom);
        if (prom > mejorProm){
            mejorProm = prom;
            // Procedimiento de <string.h>
            strcpy(mejorPromNom, nombre);
        }
    }
    printf("El mejor promedio lo tiene %s con %5.2f de promedio", mejorPromNom, mejorProm);

    return 0;
}
