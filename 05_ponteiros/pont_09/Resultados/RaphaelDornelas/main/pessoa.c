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

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    return(ExistePessoa(pessoa->pai) || ExistePessoa(pessoa->mae));
}

/// @brief Imprime msg de quando um parente nao foi informado
void NoInfMsg(){
    printf("NAO INFORMADO\n");
}

tPessoa CriaPessoa(){  
    tPessoa pessoatemp;
    
    pessoatemp.nome[0] = '\0';
    pessoatemp.pai = NULL;
    pessoatemp.mae = NULL;

    return pessoatemp;
}

void LePessoa(tPessoa *pessoa){
    //*pessoa = CriaPessoa();
    scanf("%*[^A-Za-z]");
    scanf("%[^\n]", pessoa->nome);
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

    printf("\n");
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
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
       
    }
}
