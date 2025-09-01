#include <stdio.h>
#include <stdlib.h>

#define MAX 32

void generarBinario();
void leerBinario();

int main()
{
    generarBinario();
    leerBinario();

    return 0;
}

void generarBinario(){
    FILE *archtxt, *archbin;
    float value;
    archtxt = fopen("datos.txt", "rt");
    if (archtxt == NULL) {
        printf("datos.txt no se encontro\n");
        fclose(archtxt);
    } else {
        archbin = fopen("datos.dat", "wb");
        if(archbin == NULL){
            printf("datos.dat no se encontro\n");
            fclose(archtxt);
        } else {
            fscanf(archtxt, "%f", &value);
            while (!feof(archtxt)){
                fwrite(&value , sizeof(float), 1, archbin);
                fscanf(archtxt, "%f", &value);
            }
            fclose(archtxt); fclose(archbin);
        }
    }






}

void leerBinario(){
    FILE *archbin;
    float value, min, max, total;
    int cantMediciones = 0;
    archbin = fopen("datos.dat", "rb");
    fread(&value, sizeof(float), 1, archbin);
    min = value; max = value; total = 0;

    while (!feof(archbin)){
        cantMediciones += 1;
        if (value < min) {
            min = value;
        } else if (value > max) {
            max = value;
        }
        total += value;
        fread(&value, sizeof(float), 1, archbin);
    }

    printf("Min temp: %5.2f\n", min);
    printf("Max temp: %5.2f\n", max);
    printf("Prom temp: %5.2f\n", total / cantMediciones);
}


