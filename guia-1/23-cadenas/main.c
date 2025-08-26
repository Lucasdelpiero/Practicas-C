#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cad1[20], cad2[20], cad3[30] = "nada";
    printf("%d\n", strcmp(cad1, cad2));
    if (strcmp(cad1, cad2) != 0) {
        strcpy(cad3, cad1);
    }
    printf(cad3);
    return 0;
}
