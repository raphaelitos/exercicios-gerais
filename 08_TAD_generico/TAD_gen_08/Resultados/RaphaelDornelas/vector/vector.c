#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

struct Vector{
    DataType* vetor;
    int numElem;
};

Vector *VectorConstruct(){
    Vector *veti = (Vector*) malloc(sizeof(Vector));
    if(veti == NULL){
        printf("Falha na criacao de novo vector\n");
        exit(0);
    }
    veti->numElem = 0;
    veti->vetor = NULL;
    return veti;
}

void VectorPushBack(Vector *v, DataType val){
    // Realocar para aumentar o tamanho do vetor
    v->vetor = (DataType*)realloc(v->vetor, (v->numElem + 1) * sizeof(DataType));
    if (v->vetor == NULL) {
        printf("Falha ao alocar nova posicao do vetor\n");
        exit(0);
    }

    v->vetor[v->numElem] = val;
    (v->numElem)++;
}

DataType VectorPopFront(Vector *v){
    
    if(v->numElem == 0){
        printf("erro no pop: vetor vazio\n");
        return NULL;
    }
    
    DataType retorno = v->vetor[0];

    for(int p = 0; p < (v->numElem - 1); p++){
        v->vetor[p] = v->vetor[p + 1];
    }

    (v->numElem)--;

    v->vetor = (DataType*)realloc(v->vetor, (v->numElem) * sizeof(DataType));

    return retorno;
}

DataType VectorGet(Vector *v, int i){
    if((i > (v->numElem - 1)) || i < 0){
        printf("Indice invalido!\n");
        return NULL;
    }

    return(v->vetor[i]);
}

int VectorSize(Vector *v){
    if(v) return(v->numElem);
    return 0;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    if(v == NULL){
        return;
    }
    
    if(v->vetor){
        for(int i = 0; i < v->numElem; i++){
            destroy(v->vetor[i]);
        }
    
        free(v->vetor);
    }
    free(v);
}
