#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

struct soma{
    float n1, n2;
};

tSoma* CriaTarefaSoma(float n1, float n2){
    tSoma* s = (tSoma*)malloc(sizeof(tSoma));
    if(s == NULL){
        printf("Falha na alocacao de tSoma!\n");
        exit(0);
    }
    s->n1 = n1;
    s->n2 = n2;

    return s;
}

void ExecutaTarefaSoma(void *sum){
    tSoma *copia = (tSoma*) sum;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", copia->n1, copia->n2, (copia->n1 + copia->n2));
}

void DestroiTarefaSoma(void *sum){
    if(sum) free(sum);
}