#include <stdio.h>
#include <stdlib.h>

unsigned int n, i, j;

int main()
{
    printf("Ingrese largo del cuadrado\n");
    scanf("%d", &n);
    for(j=1; j <= n; j++){
        for(i=1; i <= n; i++){
            if (i == 1 || i == n || j == 1 || j == n ){
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
