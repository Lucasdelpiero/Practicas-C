#include "fraccion.h"
#define MIN(a,b) a < b ? a : b
#define MAX(a,b) a > b ? a : b

Tfraccion  crear(int num, int denom){
    Tfraccion f;
    f.num = num;
    f.denom = denom;
    return f;
}

int numerador(Tfraccion f){
    return f.num;
}

int denominador(Tfraccion f){
    return f.denom;
}

Tfraccion suma(Tfraccion f1, Tfraccion f2){
    Tfraccion f3;
    if (f1.denom == f2.denom)
        f3.denom = f1.denom;
    else
    {
        f3.denom = f1.denom * f2.denom;
        f1.num *= f2.denom;
        f2.num *= f1.denom;
    }
    f3.num = f1.num + f2.num;
    return f3;
}

Tfraccion restar(Tfraccion f1, Tfraccion f2) {
    Tfraccion f3;
    if (f1.denom == f2.denom)
        f3.denom = f1.denom;
    else
    {
        f3.denom = f1.denom * f2.denom;
        f1.num *= f2.denom;
        f2.num *= f1.denom;
    }
    f3.num = f1.num - f2.num;
    return f3;
}

Tfraccion multiplicar(Tfraccion f1, Tfraccion f2){
    Tfraccion f3;
    f3.num = f1.num * f2.num;
    f3.denom = f1.denom * f2.denom;
    return f3;
}

Tfraccion dividir(Tfraccion f1, Tfraccion f2){
    Tfraccion f3;
    f3.num = f1.num * f2.denom;
    f3.denom = f1.denom * f2.num;
    return f3;
}

Tfraccion simplificar(Tfraccion f){
    int numMultiplos[32] = {0}, denomMultiplos[32] = {0}, nNum = -1, nDenom = -1, temp, i;

    // Multiplos numeradores
    temp = f.num;
    i = 2;
    while(i <= temp ) {
        if (temp % i == 0) {
            nNum++;
            numMultiplos[nNum] = i;
            temp /= i;
        } else {
            i++;
        }
    }

    // Multuiplos denominadores
    temp = f.denom;
    i = 2;
    while(i <= temp ) {
        if (temp % i == 0) {
            nDenom++;
            denomMultiplos[nDenom] = i;
            temp /= i;
        } else {
            i++;
        }
    }

    while (nNum >= 0 && nDenom >= 0){
        if (numMultiplos[nNum] > denomMultiplos[nDenom] )
            nNum--;
        else
            if (numMultiplos[nNum] < denomMultiplos[nDenom] )
                nDenom--;

        else // numMultiplos[nNum] == denomMultiplos[nDenom]
            if (f.num % numMultiplos[nNum] ==  0  && f.denom % denomMultiplos[nDenom] == 0) {
            f.num /= numMultiplos[nNum];
            f.denom /= numMultiplos[nNum];
            nNum--;
            nDenom--;
        }
    }
    return f;
}

int iguales(Tfraccion f1, Tfraccion f2) {
    f1 = simplificar(f1);
    f2 = simplificar(f2);

    return (f1.num == f2.num && f1.denom == f2.denom);
}

