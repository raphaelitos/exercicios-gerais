#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic{
    int tipo;
    int numElemem;
    void* vetor;
};


int RetornaTamanhoTipo(Type type){
    if(type == FLOAT){
        return((int)sizeof(float));
    }
    else{
        return((int)sizeof(int));
    }
}

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric* genI = (tGeneric*)malloc(sizeof(tGeneric));
    if(genI == NULL){
        printf("Erro ao alocar novo vetor!\n");
        exit(0);
    }
    genI->tipo = type;
    genI->numElemem = numElem;
    genI->vetor = malloc(numElem * RetornaTamanhoTipo(type));
    
    return genI;
}

void DestroiGenerico(tGeneric* gen){
    if(gen == NULL){
        return;
    }
    if(gen->vetor) free(gen->vetor);

    free(gen);
}

void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");
    if(gen->tipo == FLOAT){
        float* vet = (float*)gen->vetor;
        for(int i = 0; i < gen->numElemem; i++){
            scanf("%f", &vet[i]);
        }
    }
    else if(gen->tipo == INT){
        int* vet = (int*)gen->vetor;
        for(int i = 0; i < gen->numElemem; i++){
            scanf("%d", &vet[i]);
        }
    }
    else{
        printf("Nao eh um tipo valido!");
    }
}

void ImprimeGenerico(tGeneric* gen){
    if(gen->tipo == INT){
        int* vet = (int*)gen->vetor;
        for(int i = 0; i < gen->numElemem; i++){
            printf("%d ", vet[i]);
        }
    }
    else if(gen->tipo == FLOAT){
        float* vet = (float*)gen->vetor;
        for(int i = 0; i < gen->numElemem; i++){
            printf("%.2f ", vet[i]);
        }
    }
    
}