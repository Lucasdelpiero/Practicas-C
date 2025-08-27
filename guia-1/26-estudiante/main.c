#include <stdio.h>
#include <stdlib.h>
#define MAX 32

struct estudiante {
    char nombre[MAX];
    char matricula[MAX];
    float promedio;
} est1;

void leerNombre(struct estudiante est);
void leerMatricula(struct estudiante est);
void leerPromedio(struct estudiante est);
void leerTodo(struct estudiante est);

int main()
{
    char menu;
    printf("Ingrese nombre\n");
    gets(est1.nombre);
    printf("Ingrese matricula\n");
    gets(est1.matricula);
    printf("Ingrese promedio\n");
    scanf("%f", &est1.promedio);

    printf("Que desea leer del estudiante\n1-Nombre\n2-Matricula\n3-Promedio\n4-Todo\n");
    menu = getche(); printf("\n");
    switch(menu){
        case '1':
            leerNombre(est1);
            break;
        case '2':
            leerMatricula(est1);
            break;
        case '3':
            leerPromedio(est1);
            break;
        case '4':
            leerTodo(est1);
            break;
        default:
            printf("No se ha elegido una opcion valida\n");
    }

    return 0;
}

void leerNombre(struct estudiante est){
    printf("Nombre: %s\n", est.nombre);
}

void leerMatricula(struct estudiante est){
    printf("Matricula: %s\n", est.matricula);
}

void leerPromedio(struct estudiante est){
    printf("Promedio: %5.2f\n", est.promedio);
}

void leerTodo(struct estudiante est){
    leerNombre(est);
    leerMatricula(est);
    leerPromedio(est);
}

