#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>

struct mult{
    float n1, n2;
};

tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult* m = (tMult*)malloc(sizeof(tMult));
    if(m == NULL){
        printf("Falha na criacao de tmult!\n");
        exit(0);
    }
    m->n1  = n1;
    m->n2 = n2;

    return m;
}

void ExecutaTarefaMultiplicar(void *mult){
    tMult *copia = (tMult*) mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", copia->n1, copia->n2, (copia->n1*copia->n2));
}

void DestroiTarefaMultiplicar(void *mult){
    if(mult) free(mult);
}