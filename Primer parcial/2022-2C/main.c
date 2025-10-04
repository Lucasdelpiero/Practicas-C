#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilas.h"

#define MAX_COD 6
#define MAX_OPT 26

typedef struct nodoCorr {
    char cod[MAX_COD];
    struct nodoCorr * sig;
} nodoCorr;
typedef nodoCorr * TScorr;

typedef struct nodoAs {
    char cod[MAX_COD];
    char opt[MAX_OPT];
    int cuatri;
    unsigned int cred;
    TScorr correlativas;
    struct nodoAs * sig;
} nodoAs;
typedef nodoAs * TLas;

typedef struct nodoD{
    int cuatri;
    TpilaD pila;
    struct nodoD *ant,*sig;
} nodoD;
typedef nodoD * Pnodo;

typedef struct nodoLD {
    Pnodo pri, ult;
} nodoLD;
typedef struct nodoLD * TLD;

void cargaDatos(TLas *L);
void mostrarDatos(TLas L);
void creaArchivo(TLas L, char A[]);
void creaLD(TLas L, TLD *LD);
void mostrarLD(TLD LD);
void elimAsig(TLas *L, TLD LD, char B[]);
void eliminaDePila(TpilaD * P, char B[]);

int main()
{
    TLas Lasig = NULL;
    TLD LDasigOblig = NULL;
    char A[MAX_COD], B[MAX_COD];
    cargaDatos(&Lasig);
    //mostrarDatos(Lasig);
    //printf("Ingrese A:\n"); scanf("%s", A);
    //creaArchivo(Lasig, A);
    creaLD(Lasig, &LDasigOblig);
    //mostrarLD(LDasigOblig);
    printf("Ingrese B:\n"); scanf("%s", B);
    elimAsig(&Lasig, LDasigOblig, B);
    mostrarDatos(Lasig);

    return 0;
}


void cargaDatos(TLas *L) {
    TLas actL, antL;
    TScorr actCorr, antCorr, primerCorr;
    FILE *arch = fopen("datos.txt", "rt");
    char cod[MAX_COD];
    int cantCorr, cuatri, i;
    unsigned int cred;

    if (arch != NULL) {
        *L = NULL;
        antL = NULL;

        while (fscanf(arch, "%s %u %d %d", cod, &cred, &cuatri, &cantCorr) == 4) {
            actL = (TLas)malloc(sizeof(nodoAs));
            strcpy(actL->cod, cod);
            actL->cred = cred;
            actL->cuatri = cuatri;
            actL->sig = NULL;

            // --- Cargar sublista de correlativas ---
            if (cantCorr == 0) {
                actL->correlativas = NULL;
            } else {
                primerCorr = NULL;
                antCorr = NULL;

                for (i = 0; i < cantCorr; i++) {
                    actCorr = (TScorr)malloc(sizeof(nodoCorr));
                    fscanf(arch, "%s", cod);
                    strcpy(actCorr->cod, cod);
                    actCorr->sig = NULL;

                    if (primerCorr == NULL)
                        primerCorr = actCorr;
                    else
                        antCorr->sig = actCorr;

                    antCorr = actCorr;
                }

                actL->correlativas = primerCorr;
            }

            // --- Enlazar nodo en lista principal ---
            if (*L == NULL)
                *L = actL;
            else
                antL->sig = actL;

            antL = actL;
        }

        fclose(arch);
    } else {
        printf("Error al abrir archivo\n");
    }
}

void mostrarDatos(TLas L) {
    TLas actL;
    TScorr actCorr;
    int i;

    if (L == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    actL = L;
    while (actL != NULL) {
        printf("--------------------------------------------------\n");
        printf("Asignatura: %s\n", actL->cod);
        printf("Creditos: %d\n", actL->cred);

        // Mostrar correlativas (sublista)
        if (actL->correlativas == NULL) {
            printf("Correlativas: (ninguna)\n");
        } else {
            printf("Correlativas: ");
            actCorr = actL->correlativas;
            while (actCorr != NULL) {
                printf("%s", actCorr->cod);
                if (actCorr->sig != NULL)
                    printf(" -> ");
                actCorr = actCorr->sig;
            }
            printf("\n");
        }

        actL = actL->sig;
    }

    printf("--------------------------------------------------\n");
}

void creaArchivo(TLas L, char A[]){
    FILE * arch;
    TLas Laux;
    TScorr corrAct;
    char nomArch[10];
    int cantCorr = 0, totCred = 0;

    if (L != NULL) {
        Laux = L;
        strcpy(nomArch, A);
        strcat(nomArch, ".TXT");
        arch = fopen(nomArch, "wt");

        if (arch != NULL) {
            int cuatri = Laux->cuatri;
            while (strcmp(Laux->cod, A) != 0)
                Laux = Laux->sig;

            fprintf(arch, "%s %d\n", Laux->cod, Laux->cuatri);

            if (Laux->correlativas != NULL){
                corrAct = Laux->correlativas;
                Laux = L;

                while (corrAct != NULL){
                    fprintf(arch, "%s ", corrAct->cod);

                    while (strcmp(Laux->cod, corrAct->cod) != 0)
                        Laux = Laux->sig;

                    totCred += Laux->cred;
                    cantCorr++;
                    corrAct = corrAct->sig;
                }
                fprintf(arch, "\n%.2f\n",(float)totCred/cantCorr);
            } else {
                printf("\nNO TIENE CORRELATIVAS ANTERIORES\n");
            }
            fclose(arch);
        } else {
            printf("Error al crear archivo\n");
        }
    }
}

void creaLD(TLas L, TLD *LD){
    TLas asAct;
    Pnodo cuatriAct, cuatriAnt;
    int i;
    TLD LdAct;
    TelemPd nuevo;

    if(L != NULL) {
        LdAct = (TLD) malloc(sizeof(nodoLD));
        *LD = LdAct;
        asAct = L;
        cuatriAnt = NULL;

        for(i=1; i<11; i++){
            cuatriAct = (Pnodo) malloc(sizeof(nodoD));
            cuatriAct->cuatri = i;
            iniciaPd(&(cuatriAct->pila));

            if (i == 1) {
                LdAct->pri = cuatriAct;
                cuatriAct->ant = NULL;
            } else
                if (i==10){
                    LdAct->ult = cuatriAct;
                    cuatriAct->sig = NULL;
                    cuatriAnt->sig = cuatriAct;
                } else {
                    cuatriAnt->sig = cuatriAct;
                }
            cuatriAnt = cuatriAct;
        }

        while (asAct != NULL){
            cuatriAct = LdAct->pri;

            while (cuatriAct->cuatri != asAct->cuatri)
                cuatriAct = cuatriAct->sig;

            strcpy(nuevo.cod, asAct->cod);
            nuevo.cred = asAct->cred;

            ponePd(&(cuatriAct->pila), nuevo);
            asAct = asAct->sig;
        }
    }
}

void mostrarLD(TLD LD) {
    Pnodo cuatriAct;
    nodop *auxPila;

    if (LD == NULL || LD->pri == NULL) {
        printf("\nLa lista doble está vacía.\n");
        return;
    }

    printf("\n========== CONTENIDO DE LA LISTA DOBLE ==========\n");

    cuatriAct = LD->pri;
    while (cuatriAct != NULL) {
        printf("\nCuatrimestre %d:\n", cuatriAct->cuatri);
        printf("-----------------------------\n");

        if (cuatriAct->pila == NULL) {
            printf("(sin asignaturas)\n");
        } else {
            auxPila = cuatriAct->pila;
            while (auxPila != NULL) {
                printf("Codigo: %-10s  Creditos: %d\n",
                       auxPila->dato.cod,
                       auxPila->dato.cred);
                auxPila = auxPila->sig;
            }
        }

        cuatriAct = cuatriAct->sig;
    }

    printf("=================================================\n");
}

/*

void elimAsig(TLas *L, TLD LD, char B[]){
    TLas asAct, asAnt;
    Pnodo ldNodo;
    TScorr corrAct, corrAnt;

    if (*L != NULL){
        asAct = *L;
        asAnt = NULL;

        while (asAct != NULL && strcmp(asAct->cod, B) < 0){
            asAnt = asAct;
            asAct = asAct->sig;
        }

        if (asAct == NULL || strcmp(asAct->cod, B) != 0)
            printf("No se encontro la asignatura\n");
        else {
            ldNodo = LD->pri;

            while (ldNodo-> cuatri != asAct->cuatri)
                ldNodo = ldNodo->sig;

            eliminaDePila(ldNodo->pila, B);
            corrAnt = NULL;
            corrAct = asAct->correlativas;

            while (corrAct != NULL && strcmp(corrAct->cod, B) != 0) {
                corrAnt = corrAct;
                corrAct = corrAct->sig;
            }

            if (asAct->correlativas == corrAct) // elim cabeza
                asAct->correlativas = corrAct->sig;
            else
                corrAnt->sig = corrAct->sig;

            free(corrAct);
            if (*L == asAct)
                *L = asAct->sig;
            else
                asAnt->sig = asAct->sig;

            free(asAct);
        }
    }
}

*/
void elimAsig(TLas *L, TLD LD, char B[]) {
    TLas asAct, asAnt;
    Pnodo ldNodo;
    TScorr corrAct, corrAnt;

    if (*L == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    asAct = *L;
    asAnt = NULL;

    // Buscar la asignatura por código
    while (asAct != NULL && strcmp(asAct->cod, B) < 0) {
        asAnt = asAct;
        asAct = asAct->sig;
    }

    if (asAct == NULL || strcmp(asAct->cod, B) != 0) {
        printf("No se encontró la asignatura '%s'.\n", B);
        return;
    }

    // Buscar cuatrimestre en lista doble
    ldNodo = LD->pri;
    while (ldNodo != NULL && ldNodo->cuatri != asAct->cuatri)
        ldNodo = ldNodo->sig;

    if (ldNodo != NULL)
        eliminaDePila(&(ldNodo->pila), B);

    // Eliminar correlativa (si existe)
    corrAnt = NULL;
    corrAct = asAct->correlativas;

    while (corrAct != NULL && strcmp(corrAct->cod, B) != 0) {
        corrAnt = corrAct;
        corrAct = corrAct->sig;
    }

    if (corrAct != NULL) { // se encontró
        if (corrAnt == NULL)
            asAct->correlativas = corrAct->sig;  // era cabeza
        else
            corrAnt->sig = corrAct->sig;
        free(corrAct);
    }

    // Eliminar asignatura de la lista principal
    if (asAnt == NULL)
        *L = asAct->sig;   // era cabeza
    else
        asAnt->sig = asAct->sig;

    free(asAct);

    printf("Asignatura '%s' eliminada correctamente.\n", B);
}


void eliminaDePila(TpilaD *P,char B[]){
    TelemPd elem;

    if (!vaciaPd(*P)) {
        sacaPd(P, &elem);
    }

    if (strcmp(elem.cod, B) != 0) {
        if (!vaciaPd(*P)){
            eliminaDePila(P, B);
        }
        ponePd(P, elem);
    }
}

