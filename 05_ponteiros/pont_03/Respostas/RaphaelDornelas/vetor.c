#include "vetor.h"
#include <stdio.h>

int achaMenorVet(int vet[], int tam){
    int menor = vet[0];
    for(int i = 1; i < tam; i++){
        if(menor < vet[i]){
            menor = vet[i];
        }
    }
    return menor;
}

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
        if(vet[pos] > vet[pos + 1]){
            int aux = vet[pos];
            vet[pos] = vet[pos + 1];
            vet[pos + 1] =  aux;

            *paraTrocar = pos;
        
        }
    }
}

void OrdeneCrescente(int * vet, int tam){
    int idm = achaMenorVet(vet, tam);
    

    for(int i = 0; i < tam - 1; i++){
        TrocaSeAcharMenor(vet, tam-i-1, &idm);
    }
}