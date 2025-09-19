#define MAX_CE 50

// Cola estatoca

typedef int TelemC;

typedef struct {
    TelemC datos[MAX_CE];
    int pri, ult;
} TcolaE;

void iniciaCe(TcolaE *c);
int vaciaCe(TcolaE c);
void poneCe(TcolaE *c, TelemC x);
void sacaCe(TcolaE *c, TelemC *x);
TelemC consultaCe(TcolaE c);


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

