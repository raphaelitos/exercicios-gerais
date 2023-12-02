#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define CHUNK 5

struct Vector{
    DataType* vetor;
    int alocated;
    int numElem;
};

Vector *VectorConstruct(){
    Vector *veti = (Vector*) malloc(sizeof(Vector));
    if(veti == NULL){
        printf("Falha na criacao de novo vector\n");
        exit(0);
    }
    
    veti->vetor = (DataType*)malloc(CHUNK * sizeof(DataType));
    if(veti->vetor == NULL){
        printf("Falha na criacao de vetor em novo vector\n");
        exit(0);
    }
    
    veti->alocated = CHUNK;
    veti->numElem = 0;
   
    return veti;
}

void VectorPushBack(Vector *v, DataType val){
    
    if(v->numElem == v->alocated){
        v->vetor = (DataType*)realloc(v->vetor, (v->alocated + CHUNK) * sizeof(DataType));
        if (v->vetor == NULL) {
            printf("Falha ao alocar nova chunk no vetor\n");
            exit(0);
        }
        (v->alocated) += CHUNK;
    }
    
    (v->numElem)++;
    v->vetor[(v->numElem) - 1] = val;
}

/*DataType VectorPopFront(Vector *v){
    
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
}*/

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