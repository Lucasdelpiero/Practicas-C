#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 900
#define MAX_CAR 21

typedef struct {
    float min, max;
    int dia;
    char provincia[MAX_CAR];
}   Tmedicion;

void creaBinario();
void listado();

int main()
{
    creaBinario();
    listado();
    return 0;
}

void creaBinario(){
    FILE *archt, *archbn;
    Tmedicion medicion;

    archt = fopen("datos.txt", "rt");
    if(archt == NULL){
        printf("Error al cargar archivo de texto\n");
        fclose(archt);
    } else {
        printf("Valores leidos del archivo de texto:\n");
        fscanf(archt, "%s %d %f %f", medicion.provincia, &(medicion.dia),&(medicion.min), &(medicion.max) );
        archbn = fopen("datos.dat", "wb");
        while(!feof(archt)){
            fwrite(&medicion, sizeof(Tmedicion), 1, archbn);
            printf("%22s, dia: %2d, min: %4.1f, max: %4.1f\n", medicion.provincia, medicion.dia, medicion.min, medicion.max );
            fscanf(archt, "%s %d %f %f", medicion.provincia, &(medicion.dia),&(medicion.min), &(medicion.max) );
        }
        fclose(archbn); fclose(archt);
    }
}

void listado(){
    FILE *archbn;
    Tmedicion tempMedicion, resMedicion,menorMedicion;
    char actMedicion[MAX_CAR];
    archbn = fopen("datos.dat", "rb");
    if (archbn == NULL){
        printf("Error en la carga del archivo binario\n");
        fclose(archbn);
    } else {
        fread(&tempMedicion, sizeof(Tmedicion), 1, archbn);
        tempMedicion = tempMedicion;
        menorMedicion = tempMedicion;
        resMedicion = tempMedicion;
        strcpy(actMedicion, tempMedicion.provincia);
        fread(&tempMedicion, sizeof(Tmedicion), 1, archbn);
        printf("\n");
        printf("Listado de minimas y maximas temperaturas en el mes por provincia:\n");
        while(!feof(archbn)){
            if(strcmp(tempMedicion.provincia, actMedicion) != 0){
                printf("%20s, min: %4.1f, max: %4.1f\n",
                       resMedicion.provincia, resMedicion.min, resMedicion.max);
                strcpy(actMedicion, tempMedicion.provincia);
                resMedicion = tempMedicion;
                fread(&tempMedicion, sizeof(Tmedicion), 1, archbn);
            } else {
                if(tempMedicion.min < resMedicion.min) {
                    resMedicion.min = tempMedicion.min;
                }
                if(tempMedicion.max > resMedicion.max){
                    resMedicion.max = tempMedicion.max;
                }
                if(tempMedicion.min < menorMedicion.min) {
                    menorMedicion.min = tempMedicion.min;
                    menorMedicion.dia = tempMedicion.dia;
                }

                fread(&tempMedicion, sizeof(Tmedicion), 1, archbn);
            }
        }
        // Ultima provincia que falta
        printf("%20s, min: %4.1f, max: %4.1f\n",
                       resMedicion.provincia, resMedicion.min, resMedicion.max);

        printf("\nMenor medicion fue en %10s el dia %2d y hacia %4.1f C\n",
               menorMedicion.provincia, menorMedicion.dia, menorMedicion.min);
    }
    fclose(archbn);
}
