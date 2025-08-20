#include <stdio.h>
#include <stdlib.h>


unsigned int tiempo, horas, minutos, segundos;

void hora_min_seg(unsigned int n){
    horas = n / 3600;
    n %= 3600;
    minutos = n / 60;
    n %= 60;
    segundos = n;
    printf("%02u:%02u:%02u", horas, minutos, segundos);
}

int main()
{
    printf("Ingrese tiempo en segundos\n");
    scanf("%u", &tiempo);
    hora_min_seg(tiempo);
    return 0;
}
