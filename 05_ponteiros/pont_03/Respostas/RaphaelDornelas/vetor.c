//OBSERVAR EXEMPLOS SOBRE PONTEIROS P VETOR

#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam){
    for(int pos = 0; pos < tam; pos++){
        scanf("%d", &vet[pos]);
    }
}

void ImprimeDadosDoVetor(int * n, int tam){
    for(int pos = 0; pos < tam; pos++){
        printf("%d ", n[pos]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    for(int pos = 0; pos < tam; pos++){
        if(vet[pos] < *paraTrocar){
            *paraTrocar = vet[pos];
        }
    }
}

void OrdeneCrescente(int * vet, int tam){
    for(int pos = 0; pos < tam; pos++){

    }
}