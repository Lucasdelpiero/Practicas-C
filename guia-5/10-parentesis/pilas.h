#ifndef HEADER_AE0A9576659FE0BB
#define HEADER_AE0A9576659FE0BB

// Pila estatica
#define MAX_PE 50

typedef char TelemP;

typedef struct {
    TelemP datos[MAX_PE];
    int tope;
} TpilaE;

void ponePe(TpilaE *p, TelemP x);
void sacaPe(TpilaE *p, TelemP *x);
TelemP consultaPe(TpilaE );
int vaciaPe(TpilaE p);
void iniciaPe(TpilaE *p);

// Pila dinamica


typedef struct nodop {
    TelemP dato;
    struct nodop *sig;
} nodop;

typedef nodop *TpilaD;

void ponePd(TpilaD *p, TelemP x);
void sacaPd(TpilaD *p, TelemP *x);
TelemP consultaPd(TpilaD );
int vaciaPd(TpilaD p);
void iniciaPd(TpilaD *p);
#endif // header guard 

