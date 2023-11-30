#include "fila.h"
#include "movel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila{
    Vector *vetMoveis;
};

Fila *FilaConstruct(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f == NULL){
        printf("Falha na criacao de fila!\n");
        exit(1);
    }

    f->vetMoveis = VectorConstruct();

    return f;
}

void FilaDestroy(Fila *f, void (*destroy)(DataType)){
    if(f == NULL){
        printf("Fila nula enviada para o destroy!\n");
        return;
    }
    VectorDestroy(f->vetMoveis, destroy);
    free(f);
}

int FilaSize(Fila *f){
    if(f){
        return VectorSize(f->vetMoveis);
    }
    printf("Fila nulo mandado para o size!\n");
    return 0;
}

DataType FilaPop(Fila *f){
    if(f == NULL){
        printf("fila nula enviada para pop!\n");
        return NULL;
    }
    return(VectorPopFront(f->vetMoveis));
}

void FilaPush(Fila *f, DataType val){
    if(f == NULL){
        printf("fila nula enviada para push!\n");
        return;
    }
    VectorPushBack(f->vetMoveis, val);
}