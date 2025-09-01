#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32
#define NAC_L 4

typedef struct{
    char nombreYapellido[MAX];
    char nacionalidad[NAC_L];
    int puntaje;
} Ttenista;

void creaArchivo();
void buscaArchivo();
void leerBinario();

int main()
{
    creaArchivo();
    //leerBinario();
    buscaArchivo();

    return 0;
}

void creaArchivo(){
    FILE *archtxt, *archbin;
    char nombre[MAX], apellido[MAX], nombreYapellido[MAX], nacionalidad[NAC_L];
    int puntaje;
    Ttenista tenista;
    archtxt = fopen("datos.txt", "rt");
    fscanf(archtxt, "%s %s %s %d", nombre, apellido, nacionalidad, &puntaje);

    if(archtxt == NULL){
        printf("El archivo  datos.txt no existe\n");
    } else {
        archbin = fopen("datos.dat", "wb");
        if (archbin == NULL) {
            printf("El archivo datos.dat no existe\n");
            fclose(archtxt);
        } else {
            while(!feof(archtxt)){
                strcpy(nombreYapellido, "");
                strcat(nombreYapellido, apellido);
                strcat(nombreYapellido, " ");
                strcat(nombreYapellido, nombre);

                strcpy(tenista.nombreYapellido, nombreYapellido);
                strcpy(tenista.nacionalidad, nacionalidad);
                tenista.puntaje = puntaje;

                fwrite(&tenista, sizeof(Ttenista), 1, archbin);
                fscanf(archtxt, "%s %s %s %d", nombre, apellido, nacionalidad, &puntaje);
            }
            fclose(archtxt); fclose(archbin);
        }
    }
}

void buscaArchivo(){
    FILE *archbin;
    int pos;
    Ttenista tenista;
    printf("Ingrese la posicion en el ranking del tenis que quiere buscar:\n");
    scanf("%d", &pos);
    archbin = fopen("datos.dat", "rb");

    if (archbin == NULL){
        printf("Hubo un error con el archivo\n");
    } else {
        fseek(archbin, (pos - 1) * sizeof(Ttenista), SEEK_SET);
        fread(&tenista, sizeof(Ttenista), 1, archbin);
        printf("Nombre: %s, NAC: %s, Puntaje: %d\n", tenista.nombreYapellido, tenista.nacionalidad, tenista.puntaje);

        fclose(archbin);
    }

}

void leerBinario() {
    FILE *archbin;
    Ttenista tenista;
    archbin = fopen("datos.dat", "rb");

    if (archbin == NULL){
        printf("Hubo un error con el archivo\n");
    } else {
        fread(&tenista, sizeof(Ttenista), 1, archbin);

        while (!feof(archbin)) {
            printf("Nombre: %s, NAC: %s, Puntaje: %d\n", tenista.nombreYapellido, tenista.nacionalidad, tenista.puntaje);
            fread(&tenista, sizeof(Ttenista), 1, archbin);
        }


        fclose(archbin);
    }
}

