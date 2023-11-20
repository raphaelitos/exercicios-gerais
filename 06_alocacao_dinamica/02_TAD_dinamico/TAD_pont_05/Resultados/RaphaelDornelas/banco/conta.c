#include "usuario.h"
#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tConta *CriaConta(){
    tConta* pconta = (tConta*) malloc(sizeof(tConta));
    
    if(pconta == NULL){
        printf("erro na alocacao [pconta]");
        exit(0);
    }

    pconta->numero = -1;
    pconta->saldo = 0;
    pconta->user = CriaUsuario();

    return pconta;
}

void DestroiConta(tConta *conta){
    DestroiUsuario(conta->user);
    free(conta);
}

void LeConta(tConta *conta){
    LeUsuario(conta->user);
    scanf("%d", &(conta->numero));
}

void ImprimeConta(tConta* conta){
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta* conta, int numero){
    return((conta->numero) == numero);
}

void SaqueConta(tConta* conta, float valor){
    if(conta->saldo >= valor){
        conta->saldo -= valor;
    }
    else{
        printf("voce nao tem esse dinheiro :(");
    }
}

void DepositoConta(tConta* conta, float valor){
    (conta->saldo) += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor){
    if(valor > (origem->saldo)){
        printf("ERRO: saldo insuficiente para depósito");
        return;
    }
    (destino->saldo) += valor;
    (origem->saldo) -= valor;
}