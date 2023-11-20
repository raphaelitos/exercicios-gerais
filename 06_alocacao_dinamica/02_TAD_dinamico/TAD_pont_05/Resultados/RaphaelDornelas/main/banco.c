#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_INICIAL_CONTAS 5

tBanco *CriaBanco(){
    tBanco* bancoi = (tBanco*)malloc(sizeof(tBanco));
    if(bancoi == NULL){
        printf("erro ao criar banco!");
        exit(0);
    }
    bancoi->contas = (tConta**) malloc(NUM_INICIAL_CONTAS * sizeof(tConta*));
    if(bancoi->contas == NULL){
        printf("Erro ao alocar contas no banco criado!");
        exit(0);
    }

    bancoi->contasAlocadas = 0;
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
    (banco->contasAlocadas)++;
    if(banco->qtdContas > NUM_INICIAL_CONTAS){
        banco->contas = realloc(banco->contas, sizeof(tConta*));
        if(banco->contas == NULL){
            printf("Falha em incrementar espaço no vetor!");
            exit(0);
        }
    }
    banco->contas[banco->qtdContas - 1] = CriaConta();
    LeConta(banco->contas[(banco->qtdContas - 1)]);
}

void SaqueContaBanco(tBanco *banco){
    int numConta = 0;
    float valor;
    scanf("%d %f\n", &numConta, &valor);
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
    scanf("%d %f\n", &numConta, &valor);
    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], numConta)){
            DepositoConta(banco->contas[i], valor);
            break;
        }
    }
}

void TransferenciaContaBanco(tBanco *banco){
    int n1, n2, dest = -1, orgm = -1, flag = 0;
    float valor;
    scanf("%d %d %f\n", &n1, &n2, &valor);
    for(int i = 0; i < banco->qtdContas; i++){
        if(VerificaConta(banco->contas[i], n1)){
            dest = i;
        }
        else if(VerificaConta(banco->contas[i], n2)){
            orgm = i;
        }
        if(orgm != -1 && dest != -1){
            flag = 1;
            break;
        }
    }
    if(flag && banco->contas[orgm] != NULL && banco->contas[dest] != NULL){
        TransferenciaConta(banco->contas[dest], banco->contas[orgm], valor);
    }
    else{
        printf("Algo deu errado durante a transferencia :/");
    }
}

void ImprimeRelatorioBanco(tBanco *banco){
    printf("===| Imprimindo Relatorio |===\n");
    for(int i = 0; i < banco->qtdContas; i++){
        ImprimeConta((banco->contas[i]));
    }
}