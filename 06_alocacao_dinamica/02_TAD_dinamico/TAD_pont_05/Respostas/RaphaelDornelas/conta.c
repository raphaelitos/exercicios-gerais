#include "usuario.h"
#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tConta *CriaConta(){
    tConta* pconta = (tConta*) malloc(sizeof(tConta));
    /*scanf("%*[^0-9");
    pconta.numero = numero;
    pconta.user = user;
    pconta.saldo = 0.0;*/
    if(pconta == NULL){
        printf("erro na alocacao [pconta]");
        exit(0);
    }

    pconta->numero = -1;
    pconta->saldo = -1;
    pconta->user = (tUsuario*)malloc(sizeof(tUsuario));
    if(pconta->user == NULL){
        printf("erro na alocacao [pconta->user]");
        exit(0);
    }

    return pconta;
}

void ImprimeConta(tConta conta){
    printf("Conta: %d\n", conta.numero);
    printf("Saldo: R$ %.2f\n", conta.saldo);
    ImprimeUsuario(conta.user);
}

int VerificaConta(tConta conta, int numero){
    return(conta.numero == numero);
}

tConta SaqueConta(tConta conta, float valor){
    if(conta.saldo >= valor){
        conta.saldo -= valor;
    }
    else{
        printf("voce nao tem esse dinheiro :(");
    }
    return conta;
}

tConta DepositoConta(tConta conta, float valor){
    conta.saldo += valor;
    return conta;
}