#include <stdio.h>
#include <stdlib.h>
#define CANT 3

void creaVars(int *ptr, int n);
void escribeVars(int *ptr, int n);

int main()
{
    int *ptr;
    ptr = (int *) malloc(sizeof(int) * CANT);
    creaVars(ptr, CANT);
    escribeVars(ptr, CANT);
    free(ptr);

    return 0;
}

void creaVars(int *ptr, int n){
    unsigned int i;
    int *ptrTemp = ptr;

    for(i=0; i < n; i++){
        printf("Ingrese el valor del valor n:%d\n", i+1);
        scanf("%d", ptrTemp);
        ptrTemp++;
    }
}

void escribeVars(int *ptr, int n){
    unsigned int i;
    int *ptrTemp = ptr;

    for(i=0; i < n; i++){
        printf("Valor n:%d = %d\n", i+1, *ptrTemp);
        ptrTemp++;
    }
}


