#ifndef HEADER_4189F4724BEC180C
#define HEADER_4189F4724BEC180C
#endif // header guard

typedef struct {
    int num;
    int denom;
} Tfraccion ;

Tfraccion crear(int num, int denom);
int numerador(Tfraccion f);
int denominador(Tfraccion f);
Tfraccion suma(Tfraccion f1, Tfraccion f2);
Tfraccion restar(Tfraccion f1, Tfraccion f2);
Tfraccion multiplicar(Tfraccion f1, Tfraccion f2);
Tfraccion dividir(Tfraccion f1, Tfraccion f2);
Tfraccion simplificar(Tfraccion f);
int iguales(Tfraccion f1, Tfraccion f2);

