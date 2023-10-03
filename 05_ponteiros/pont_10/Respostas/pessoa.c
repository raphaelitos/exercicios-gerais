//VERIFICAR TESTAGEM DE IRMAOS E MODIFICAR TESTAGEM P VER SE PAI EXISTE

#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief verifica se uma pessoa existe
/// @param pessoa ponteiro para a pessoa a ser analisada
/// @return 0 caso ela nao exista, valor maior que 0 caso contrário
int ExistePessoa(tPessoa* pessoa){
    //printf("%c\n", pessoa->nome[0]);
    int tam = strlen(pessoa->nome);
    return tam;
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
    return(pessoa->pai != NULL || pessoa->mae != NULL);
}

void ImprimePessoa(tPessoa *pessoa){
   
    if((*pessoa).pai == NULL || (*pessoa).mae == NULL){
        return;
    }

    if(!ExistemPais(pessoa)){
        return;
    }
    printf("NOME COMPLETO: %s\n", (*pessoa).nome);

    if(ExistemPais(pessoa) == 1){
        printf("PAI: %s\n", (*(*pessoa).pai).nome);
        printf("MAE: NAO INFORMADO\n");
    }
    else if(ExistemPais(pessoa) == -1){
        printf("PAI: NAO INFORMADO\n");
        printf("MAE: %s\n", pessoa->mae->nome);
    }
    else{
        printf("PAI: %s\n", pessoa->pai->nome);
        printf("MAE: %s\n", pessoa->mae->nome);
    }
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
        
        tPessoa generic = CriaPessoa();
        
        pessoas[filho].mae = &generic; 
        pessoas[filho].pai = &generic;
        //ponteiros devidamente inicializados

        if(mae != -1)
            pessoas[filho].mae = &pessoas[mae];
        if(pai != -1)
            pessoas[filho].pai = &pessoas[pai];
    }
    
    for(int i = 0; i < numPessoas - 1; i++){
        for(int v = 0; v < numPessoas - i - 1; v++){
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[v])){
                pessoas[i].irmao = &pessoas[v];
                pessoas[v].irmao = &pessoas[i];
            }
        }
    }//bro verification
}
