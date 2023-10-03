#include "vetor.h"
#include <stdio.h>

int soma(int n1, int n2){
    return(n1 + n2);
}

int multiplicacao(int n1, int n2){
    return(n1 * n2);
}

int main(){
    
    Vetor vet;
    LeVetor(&vet);
    
    int somatorio = 0, produtorio = 0;

    Operation op = soma;
    somatorio = AplicarOperacaoVetor(&vet, op);
    op = multiplicacao;
    produtorio = AplicarOperacaoVetor(&vet, op);

    printf("Soma: %d\n", somatorio);
    printf("Produto: %d\n", produtorio);

    return 0;
}