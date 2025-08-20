#include <stdio.h>
#include <stdlib.h>

int a,b,c;

int consecutivos(int a, int b, int c) {
    return (a < b && b < c) ? 1 : 0;
}

int main()
{
    printf("Ingrese 3 numeros\n");
    scanf("%d %d %d", &a, &b, &c);
    if (consecutivos(a, b, c)){
        printf("Son consecutivos\n");
    } else {
        printf("No son consecutivos\n");
    }
    return 0;
}
