#ifndef HEADER_500DEE12233244
#define HEADER_500DEE12233244
#endif // header guard

#ifndef HEADER_6DDC864E7A782E11
#define HEADER_6DDC864E7A782E11
#endif // header guard

// Pila estatica
#define MAX_PE 50

typedef int TelemP;

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
