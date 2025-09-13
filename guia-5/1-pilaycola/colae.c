#include "colae.h"

void iniciaCe(TcolaE *c) {
    c->pri = -1;
    c->ult = -1;
}

int vaciaCe(TcolaE c) {
    return c.pri == -1;
}
void poneCe(TcolaE *c, TelemCe x) {
    if (c->ult != MAX_CE - 1){
        if (c->pri == - 1)
            c->pri = 0;
        c->datos[++(c->ult)] = x;
    }
}
void sacaCe(TcolaE *c, TelemCe *x){
    if (c->pri != -1){ // !vaciaCe(*c)
        *x = c->datos[c->pri];
        if (c->pri == c->ult)
            iniciaCe(c);
        else
            c->pri +=1;
    }
}

TelemCe consultaCe(TcolaE c);
