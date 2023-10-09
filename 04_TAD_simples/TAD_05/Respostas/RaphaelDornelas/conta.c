#include "usuario.h"
#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tConta CriaConta(int numero, tUsuario user){
    tConta newcont;
    //scanf("%*[^0-9");
    newcont.numero = numero;
    newcont.user = user;
    newcont.saldo = 0.0;

    return newcont;
}

void ImprimeConta(tConta conta){
    printf("conta: %d\n", conta.numero);
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