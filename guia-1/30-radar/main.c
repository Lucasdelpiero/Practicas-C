#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16

typedef struct {
    char patente[8];
    unsigned int velocidad;
    unsigned int velocidadMaxima;
    char fecha[17];
} Tvehiculo;

void generarArchivo();
void leerArchivo();

int main()
{
    generarArchivo();
    leerArchivo();

    return 0;
}

void generarArchivo(){
    FILE *archtxt, *archbin;
    char patente[8], fecha[17], hora[6];
    unsigned int velocidad, velocidadMaxima;
    Tvehiculo vehiculo;

    archtxt = fopen("datos.txt", "rt");
    archbin = fopen("datos.dat", "wb");
    fscanf(archtxt, "%s %u %u %s %s", patente, &velocidad, &velocidadMaxima, fecha, hora);

    printf("Autos leidos del archivo de texto:\n\n");

    while (strcmp(patente, "0000000")) {
        strcat(fecha, " ");
        strcat(fecha, hora);
        strcpy(vehiculo.patente, patente);
        strcpy(vehiculo.fecha, fecha);
        vehiculo.velocidad = velocidad;
        vehiculo.velocidadMaxima = velocidadMaxima;
        printf("PAT: %s, VEL: %3u, MAX_PERM: %3u, FECHA: %s\n",
              vehiculo.patente, vehiculo.velocidad, vehiculo.velocidadMaxima, vehiculo.fecha);

        if ((float)velocidad / velocidadMaxima > 1.2){
            fwrite(&vehiculo, sizeof(Tvehiculo), 1, archbin);
        }
        fscanf(archtxt, "%s %u %u %s %s", patente, &velocidad, &velocidadMaxima, fecha, hora);
    }
    printf("==============================================================\n");
    fclose(archtxt); fclose(archbin);
}

void leerArchivo(){
    FILE *archbin;
    archbin = fopen("datos.dat", "rb");
    Tvehiculo vehiculo;
    fread(&vehiculo, sizeof(Tvehiculo), 1, archbin);

    printf("Autos que superaron en un %s la velocidad maxima permitida:\n\n", "20%");
    while (feof(archbin) == 0){
        printf("PAT: %s, VEL: %3u, MAX_PERM: %3u, FECHA: %s\n",
              vehiculo.patente, vehiculo.velocidad, vehiculo.velocidadMaxima, vehiculo.fecha);
        fread(&vehiculo, sizeof(Tvehiculo), 1, archbin);
    }
    fclose(archbin);
}
