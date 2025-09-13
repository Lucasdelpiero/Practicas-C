#ifndef HEADER_CD57F56CCD2B5FDE
#define HEADER_CD57F56CCD2B5FDE
#endif // header guard

#define MAX_CE 50

typedef int TelemCe;

typedef struct {
    TelemCe datos[MAX_CE];
    int pri, ult;
} TcolaE;

void iniciaCe(TcolaE *c);
int vaciaCe(TcolaE c);
void poneCe(TcolaE *c, TelemCe x);
void sacaCe(TcolaE *c, TelemCe *x);
TelemCe consultaCe(TcolaE c);
