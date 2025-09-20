#ifndef HEADER_88C6FDAC4E61971E
#define HEADER_88C6FDAC4E61971E
#endif // header guard

#define MAX_CE 50

// Cola estatica

typedef struct {
    char apellido[MAX_CE];
    char nombre[MAX_CE];
} TelemC;

typedef struct {
    TelemC datos[MAX_CE];
    int pri, ult;
} TcolaE;

void iniciaCe(TcolaE *c);
int vaciaCe(TcolaE c);
void poneCe(TcolaE *c, TelemC x);
void sacaCe(TcolaE *c, TelemC *x);
TelemC consultaCe(TcolaE c);
TelemC creaC(char * apellido, char * nombre);
char inicialC(TelemC * elem);


// Cola dinamica

typedef struct nodo {
    TelemC dato;
    struct nodo * sig;
} nodo;

typedef struct {
    nodo *pri, *ult;
} TcolaD;

void iniciaCd(TcolaD *c);
int vaciaCd(TcolaD c);
void poneCd(TcolaD *c, TelemC x);
void sacaCd(TcolaD *c, TelemC *x);
TelemC consultaCd(TcolaD c);

// Cola circular
void poneCc (TcolaE*C, TelemC X);
void sacaCc (TcolaE *C, TelemC *X);


