#include "vetor.h"
#include <stdio.h>

void LeVetor(Vetor *vetor){
    int i = 0;
    scanf("%d", &vetor->tamanhoUtilizado);
    for(i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int resultado = vetor->elementos[0];
    for(int i = 1; i < vetor->tamanhoUtilizado; i++){
        resultado = op(resultado, vetor->elementos[i]);
    }
    return resultado;
}