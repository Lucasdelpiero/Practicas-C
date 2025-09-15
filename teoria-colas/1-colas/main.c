#include <stdio.h>
#include "colas.h";

int main() {
	int x;
	Tcola cola;
	cargaCola(&cola);
	printf("Ingrese x a buscar\n");
	scanf("%d", &x);
	aparece(&cola, x, &cont);
	printf("%d aparece %d veces\n", x, cont);
	return 0;
}


void aparece(TCola *C, int x, int *cont) {
	int dato;
	TCola aux;
	Inicia(&aux);
	*cont = 0;
	while (!VaciaC(*C)){
		sacaC(C, &dato);
		PoneC(&aux, dato);
		if (dato == x){
			(*cont)++;
		}
	}
	while (!VaciaC(aux)){
		sacaC(&aux, &dato);
		PoneC(C, dato);
	}
}

void aparece(TCola *C, int x, int *cont) {
	int dato;
	TCola aux;
	Inicia(&aux);
	*cont = 0;
	while (!VaciaC(*C)){
		sacaC(C, &dato);
		PoneC(&aux, dato);
		if (dato == x){
			(*cont)++;
		}
	}
	C = &aux;
}


/*
    TCola D;
    *C = D
    Esta mal porque si se pasa un puntero ahora la cola se puede modificar desde C o D, cosa que estaria mal que al
    modificar D se modifique C o biseversa
*/
