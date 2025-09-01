#include <stdio.h>
#include <stdlib.h>

int fibo(int n);

int main()
{
    int n;
    printf("Ingrese el termino de fibonacci que desea saber \n");
    scanf("%d", &n);
    printf("El valor del termino numero %d es: %d", n, fibo(n));
    return 0;
}

int fibo(int n){
    if (n == 0){
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}
