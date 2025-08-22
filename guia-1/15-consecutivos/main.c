#include <stdio.h>
#include <stdlib.h>

int consecutivos(int a, int b, int c);

int main()
{
    int a,b,c;

    printf("Ingrese 3 numeros\n");
    scanf("%d %d %d", &a, &b, &c);
    if (consecutivos(a, b, c)){
        printf("Son consecutivos\n");
    } else {
        printf("No son consecutivos\n");
    }
    return 0;
}

// Compilador recomienda usar parentesis para abarcar los &&,
// preguntar si no es abuso usar () alrededor de las expresiones de comparacion
int consecutivos(int a, int b, int c) {
    if (
        ( (b == a + 1) && (c == b + 1) ) || // 1 2 3
        ( (b == a + 1) && (b == c + 1) ) || // 1 3 2
        ( (a == b + 1) && (c == a + 1) ) || // 2 1 3
        ( (a == c + 1) && (b == a + 1) ) || // 2 3 1
        ( (a == b + 1) && (b == c + 1) ) || // 3 2 1
        ( (a == c + 1) && (c == b + 1) )    // 3 1 2
          ){
        return 1;
    } else {
        return 0;
    }
}
