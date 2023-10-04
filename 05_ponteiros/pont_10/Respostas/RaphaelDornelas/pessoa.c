#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief verifica se uma pessoa existe, ou seja, se ela foi inicializada
/// @param pessoa ponteiro para a pessoa a ser analisada
/// @return 1 caso a pessoa exista, 0 caso contrário
int ExistePessoa(tPessoa* pessoa){
    return pessoa != NULL;
}

/// @brief Imprime msg de quando um parente nao foi informado
void NoInfMsg(){
    printf("NAO INFORMADO\n");
}

int TemIrmaoPessoa(tPessoa* pessoa){
    return(pessoa->irmao != NULL);
}

tPessoa CriaPessoa(){  
    tPessoa pessoatemp;
    
    pessoatemp.nome[0] = '\0';
    pessoatemp.pai = NULL;
    pessoatemp.mae = NULL;
    pessoatemp.irmao = NULL;

    return pessoatemp;
}

void LePessoa(tPessoa *pessoa){
    *pessoa = CriaPessoa();
    scanf("%*[^A-Za-z]");
    scanf("%[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    return(ExistePessoa(pessoa->pai) || ExistePessoa(pessoa->mae));
}

void ImprimePessoa(tPessoa *pessoa){
   
    if(!VerificaSeTemPaisPessoa(pessoa)){
        return;
    }
    
    printf("NOME COMPLETO: %s\n", (*pessoa).nome);
    
    printf("PAI: ");
    if(ExistePessoa(pessoa->pai)) printf("%s\n", pessoa->pai->nome);
    else NoInfMsg();  
    
    printf("MAE: "); 
    if(ExistePessoa(pessoa->mae)) printf("%s\n", pessoa->mae->nome);
    else NoInfMsg();
    
    printf("IRMAO: ");
    if(ExistePessoa(pessoa->irmao)) printf("%s\n", pessoa->irmao->nome);
    else NoInfMsg();
   
    printf("\n");
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    return((pessoa1->pai == pessoa2->pai) && (pessoa1->mae == pessoa2->mae));
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int numAssociacoes = 0;
    scanf("%d", &numAssociacoes);
    scanf("%*[^\n]");
    int mae = 0, pai = 0, filho = 0;

    for(int a = 0; a < numAssociacoes; a++){

        scanf("\nmae: %d, ", &mae);
        scanf("pai: %d, filho: %d", &pai, &filho);

        if(mae != -1)
            pessoas[filho].mae = &pessoas[mae];
        if(pai != -1)
            pessoas[filho].pai = &pessoas[pai];
    }//familiar association
    
    for(int i = 0; i < numPessoas - 1; i++){
        for(int v = i + 1; v < numPessoas; v++){
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[v])){
                pessoas[i].irmao = &pessoas[v];
                pessoas[v].irmao = &pessoas[i];
            }
        }
    }//bro verification
}
