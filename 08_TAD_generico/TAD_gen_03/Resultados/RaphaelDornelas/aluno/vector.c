#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

struct Vector{
    data_type* vetor;
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

void VectorPushBack(Vector *v, data_type val){
    // Realocar para aumentar o tamanho do vetor
    v->vetor = (data_type*)realloc(v->vetor, (v->numElem + 1) * sizeof(data_type));
    if (v->vetor == NULL) {
        printf("Falha ao alocar nova posicao do vetor\n");
        exit(0);
    }

    v->vetor[v->numElem] = val;
    (v->numElem)++;
}

data_type VectorGet(Vector *v, int i){
    if((i > (v->numElem - 1)) || i < 0){
        printf("Indice invalido!\n");
        return NULL;
    }

    return(v->vetor[i]);
}

int VectorSize(Vector *v){
    if(v) return(v->numElem);
    return NULL;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){
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