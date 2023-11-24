#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct impr{
    char *msg;
};

tImpr* CriaTarefaImprimir(char *msg){
    tImpr* t = (tImpr*)malloc(sizeof(tImpr));
    if(t == NULL){
        printf("Falha na alocacao de tImpr\n");
        exit(0);
    }
    t->msg = (char*)malloc((strlen(msg) + 1) * sizeof(char));
    if(t->msg == NULL){
        printf("Falha na alocacao de msg!\n");
        free(t);
        exit(0);
    }
    strcpy(t->msg, msg);
    return t;
}

void ExecutaTarefaImprimir(void *imp){
    tImpr *copia = (tImpr*) imp;
    printf("\n%s", copia->msg);
}

void DestroiTarefaImprimir(void *imp){
    tImpr *copia = (tImpr*) imp;

    if(copia != NULL){
        free(copia->msg);
        free(copia);
    }
}