#include <stdio.h>
#include <stdlib.h>
#define CANT 3

void crearEnteroDinamico(int* *ptr);

int main()
{
    int *ptr1, *ptr2, *ptr3;
    crearEnteroDinamico(&ptr1);
    crearEnteroDinamico(&ptr2);
    crearEnteroDinamico(&ptr3);
    printf("Su suma es: %d\n", *ptr1 + *ptr2 + *ptr3);
    printf("Su producto es: %d\n", (*ptr1) * (*ptr2) * (*ptr3) );

    free(ptr1); free(ptr2); free(ptr3);

    return 0;
}

void crearEnteroDinamico(int **ptr){
    // ptr apunta a direccion de memoria de la variable tipo puntero
    // *ptr es el contenido del puntero(direccion que guarda la variable)
    *ptr = (int *) malloc(sizeof(int));
    printf("Ingrese valor\n");
    scanf("%d", *ptr);
}










