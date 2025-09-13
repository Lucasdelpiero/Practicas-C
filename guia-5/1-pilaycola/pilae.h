#ifndef HEADER_9DB877532C06BB84
#define HEADER_9DB877532C06BB84
#endif // header guard

#define MAX_PE 50

typedef int TelemPe;

typedef struct {
    TelemPe datos[MAX_PE];
    int tope;
} TpilaE;

void ponePe(TpilaE *p, TelemPe x);
void sacaPe(TpilaE *p, TelemPe *x);
TelemPe consultaPe(TpilaE );
int vaciaPe(TpilaE p);
void iniciaPe(TpilaE *p);
