#ifndef HEADER_D17A238C2445D1AA
#define HEADER_D17A238C2445D1AA
#endif // header guard

typedef int TelemCd;

typedef struct nodo {
    TelemCd dato;
    struct nodo * sig;
} nodo;

typedef struct {
    nodo *pri, *ult;
} TcolaD;

void iniciaCd(TcolaD *c);
int vaciaCd(TcolaD c);
void poneCd(TcolaD *c, TelemCd x);
void sacaCd(TcolaD *c, TelemCd *x);
TelemCd consultaCd(TcolaD c);
