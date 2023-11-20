#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_INICIAL_CONTAS 5

tBanco *CriaBanco(){
    tBanco* bancoi = malloc(sizeof(tBanco));
    if(bancoi == NULL){
        printf("erro ao criar banco!");
        exit(0);
    }
    bancoi->contas = (tConta**) malloc((NUM_INICIAL_CONTAS) * sizeof(tConta*));
    if(bancoi->contas == NULL){
        printf("Erro ao alocar contas no banco criado!");
        exit(0);
    }
    for(int b = 0; b < NUM_INICIAL_CONTAS; b++){
        bancoi->contas[b] = CriaConta();
    }

    bancoi->contasAlocadas = NUM_INICIAL_CONTAS;
    bancoi->qtdContas = 0;
}

void DestroiBanco(tBanco *banco){
    for(int i = 0; i < banco->contasAlocadas; i++){
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);
    free(banco);
}

void AbreContaBanco(tBanco *banco){
    (banco->qtdContas)++;
    if(banco->qtdContas > NUM_INICIAL_CONTAS){
        (banco->contasAlocadas)++;
        banco->contas = realloc(banco->contas, sizeof(tConta*));
        if(banco->contas == NULL){
            printf("Falha em incrementar espaço no vetor!");
            exit(0);
        }
    }
    LeConta(banco->contas[(banco->qtdContas - 1)]);
}

void SaqueContaBanco(tBanco *banco){
    int numConta = 0;
    float valor;
    scanf("%d %f", &numConta, &valor);
    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], numConta)){
            SaqueConta(banco->contas[i], valor);
            break;
        }
    }
}

void DepositoContaBanco(tBanco *banco){
    int numConta = 0;
    float valor;
    scanf("%d %f", &numConta, &valor);
    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], numConta)){
            DepositoConta(banco->contas[i], valor);
            break;
        }
    }
}

void TransferenciaContaBanco(tBanco *banco){
    //ISSO AQUI TA TUDO ERRADO
    int n1, n2, dest = -1, orgm = -1;
    float valor;
    scanf("%d %d %f", &n1, &n2, &valor);
    tConta *destino = NULL, *origem = NULL;
    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], n1)){
            orgm = i;
        }
        else if(VerificaConta(banco->contas[i], n2)){
            dest = i;
        }
    }
    if(dest != -1 && orgm != -1){
        TransferenciaConta(banco->contas[dest], banco->contas[orgm], valor);
    }
}