#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b)?a:b
#define esalf(car) (car>='A' && car<='z' ) ? 1:0

int a, b;
char car='b', menu;
/*  Para usar menus conviene usar caracteres, ya que esto admite cualquier tecla presionada, incluso si no es opcion
    Si se usan enteros, cualquier cosa que no sea numero, va a romper el codigo */

int main()
{
    printf("Bienvenido al programa de macros\n");
    printf("Puede averiguar el maximo entre 2 numeros y si la tecla pulsada es caracter\n");
    do {
        printf("1-Mayor entre 2 numeros\n");
        printf("2-Saber si es alfabetico\n");
        printf("Cualquier otra tecla para abandonar el programa\n");
        menu = getch();

        if (menu == '1'){
            printf("Ingrese a y luego b\n");
            scanf("%d %d", &a, &b);
            printf("El mayor es %d\n", max(a,b));
        }
        else if (menu == '2'){
            printf("Ingrese el caracter\n");
            car = getch(); // Forma correcta de leer del teclado

            //scanf("%c", &car); // %c lee absolutamente el siguiente carácter disponible en el buffer
            //                      por lo que el "2 \n" se queda con el \n al apretar enter y hace pasar a la siguiente linea de codigo
            //scanf("%s", &car); // Manera incorrecta de leer caracteres de teclado

            if (esalf(car)){
                printf("%c es alfabetico\n", car);
            } else {
                printf("%c no es alfabetico\n", car);
            }

        }

    } while (menu =='1' || menu == '2');

    printf("Gracias vuelva prontos\n");

    return 0;
}
