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
    int resultado = 0;
    for(int i = 0; i < vetor->tamanhoUtilizado; i++){
        resultado += op(vetor->elementos[i], vetor->elementos[i + 1]);
    }
    return resultado;
}