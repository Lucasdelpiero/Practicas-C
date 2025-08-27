#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> // Tiene el rand() para numeros random
#define MAX 32
#define SEED 4
#define CHANCE_CERO 10


void generaMat(int mat[MAX][MAX], int n, int m);
void leerMat(int mat[MAX][MAX], int n, int m);
int busca(int mat[MAX][MAX], int n, int m, int x); // a
void promCol(int mat[MAX][MAX], int n, int m); // b
void superanProm(int mat[MAX][MAX], int n, int m); // c
float promedioMatriz(int mat[MAX][MAX], int n, int m); // c
void forzarCeros(int mat[MAX][MAX], int n, int m);

int main()
{
    int n,m,i,j, x;
    int mat[MAX][MAX];
    char menu;
    srand(SEED);

    printf("Ingrese N filas\n");
    scanf("%d", &n);
    printf("Ingrese M columnas\n");
    scanf("%d", &m);

    generaMat(mat, n, m);
    forzarCeros(mat, n, m);
    leerMat(mat, n, m);

    printf("Ingrese opcion:\n1-Busca X en matriz\n2-Muestra el promedio de cada columna\n3-Fila supera promedio y tiene cero\n");
    menu = getche(); printf("\n");

    switch(menu){
        case '1':
            printf("Ingrese X a buscar: \n");
            scanf("%d", &x);
            busca(mat, n, m, x);
            break;
        case '2':
            promCol(mat, n, m);
            break;
        case '3':
            superanProm(mat, n, m);
            break;
        default:
            printf("No se eligio una opcion valida\n");
    }





    return 0;
}

void generaMat(int mat[MAX][MAX], int n, int m){
    unsigned int i,j;
    for(i=0; i < n; i++){
        for(j=0; j < m; j++){
            mat[i][j] = rand() % 100;
        }
    }
}

void leerMat(int mat[MAX][MAX], int n, int m) {
    unsigned int i,j;
    for(i=0; i < n; i++){
        for(j=0; j < m; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}

int busca(int mat[MAX][MAX], int n, int m, int x){
    unsigned int i = n, j = m - 1;
    while (i > 0 && mat[i][j] != x){
        i --;
        j = m - 1;
        while (j > 0 && mat[i][j] != x) {
            j--;
        }
    }
    if (mat[i][j] == x){
        printf("Encontrado %d en pos[%d][%d]\n", x,i, j);
    } else {
        printf("No se encontro x\n");
    }
}

void promCol(int mat[MAX][MAX], int n, int m) {
    unsigned int i,j;
    float prom;
    for(j = 0; j < m; j++){
        prom = 0.0;
        for(i = 0; i < n; i++){
            prom += (float)mat[i][j] /(float)n;
        }
        printf("Promedio para columna %u : %5.2f\n", j, prom);
    }
}

void superanProm(int mat[MAX][MAX], int n, int m){
    unsigned int i,j, cant, tieneCero;
    float prom = promedioMatriz(mat, n, m);
    printf("El promedio es %5.2f\n", prom);
    for(i = 0; i < n; i++){
        cant = 0;
        tieneCero = 0;
        for(j = 0; j < m; j++){
            if(mat[i][j] > prom){
                cant++;
            }
            else if(mat[i][j] == 0){
                tieneCero = 1;
            }
        }
        if (cant > 0 && tieneCero){
            printf("La fila %u tiene %u elementos mayores al promedio\n",i, cant);
        }
    }

}



float promedioMatriz(int mat[MAX][MAX], int n, int m){
    int i,j, cont = 0;
    float prom = 0.0;
    for(i=0; i < n; i++){
        for(j=0; j < m; j++){
            prom += mat[i][j];
            cont++;
        }
    }
    return prom / cont;
}

void forzarCeros(int mat[MAX][MAX], int n, int m){
    unsigned int i,j;
    for(i=0; i < n; i++){
        for(j=0; j < m; j++){
            if(rand() % 100 < CHANCE_CERO){
                mat[i][j] = 0;
            }
        }
    }
}

