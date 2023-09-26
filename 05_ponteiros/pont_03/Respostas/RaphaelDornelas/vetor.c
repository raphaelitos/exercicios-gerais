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
    for(int pos = *paraTrocar; pos < tam; pos++){
        if(vet[pos] < vet[*paraTrocar]){
            int aux = vet[pos];
            vet[pos] = vet[*paraTrocar];
            vet[*paraTrocar] =  aux;

            *paraTrocar = pos;
        
        }
    }
}

void OrdeneCrescente(int * vet, int tam){
    int i = 0;
    int *pos;
    pos = &i;
    for(i = 0; i < tam; i++){
        TrocaSeAcharMenor(vet, tam, pos);
    }
}