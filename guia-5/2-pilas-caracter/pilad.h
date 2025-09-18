#ifndef HEADER_893DBDB74D1B19B4
#define HEADER_893DBDB74D1B19B4
#endif // header guard

typedef char TelemPd;

typedef struct nodop {
    TelemPd dato;
    struct nodop *sig;
} nodop;

typedef nodop *TpilaD;

void ponePd(TpilaD *p, TelemPd x);
void sacaPd(TpilaD *p, TelemPd *x);
TelemPd consultaPd(TpilaD );
int vaciaPd(TpilaD p);
void iniciaPd(TpilaD *p);
