#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int total=0, n;
    FILE *arch;

    arch = fopen("datos.txt", "rt");
    if (arch == NULL){
        printf("Error al cargar datos.txt\n");
        fclose(arch);
    } else {
        fscanf(arch, "%d", &n);
        while(!feof(arch)){
            total += n;
            printf("%d leido del archivo\n", n );
            fscanf(arch, "%d", &n);
        }
    }

    printf("El resultado es: %u\n", total);

    return 0;
}
