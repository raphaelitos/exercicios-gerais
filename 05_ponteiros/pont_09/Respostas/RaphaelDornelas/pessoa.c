#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief verifica se uma pessoa existe
/// @param pessoa pessoa a ser analisada
/// @return 0 caso ela nao exista, valor maior que 0 caso contrário
int ExistePessoa(tPessoa pessoa){
    return strlen(pessoa.nome);
}

/// @brief verifica quantos pais uma pessoa tem.
/// @param pessoa pessoa que será analisada
/// @return -1 caso pessoa tenha apenas mae, 1 para apenas pai, 2 caso tenha os dois.
int ExistemPais(tPessoa pessoa){
    if(ExistePessoa(*pessoa.mae) && ExistePessoa(*pessoa.pai)){
        return 2;
    }
    if(ExistePessoa(*pessoa.pai) && !ExistePessoa(*pessoa.mae)){
        return 1;
    }
    if(!ExistePessoa(*pessoa.pai) && ExistePessoa(*pessoa.mae)){
        return -1;
    }
    return 0;
}

tPessoa CriaPessoa(){  
    tPessoa pessoatemp;
    
    pessoatemp.nome[0] = '\0';
    pessoatemp.pai = NULL;
    pessoatemp.mae = NULL;

    return pessoatemp;
}

void LePessoa(tPessoa *pessoa){
    *pessoa = CriaPessoa();
    scanf("%*[^A-Za-z]");
    scanf("%[^\n]", pessoa->nome);
}

void ImprimePessoa(tPessoa *pessoa){
    if(!(ExistemPais(*pessoa))){
        return;
    }
    printf("NOME COMPLETO: %s\n", (*pessoa).nome);
    
    tPessoa pai = *pessoa->pai;
    tPessoa mae = *pessoa->mae;

    if(ExistemPais(*pessoa) == 1){
        printf("PAI: %s\n", pai.nome);
        printf("MAE: NAO INFORMADO\n");
    }
    else if(ExistemPais(*pessoa) == -1){
        printf("PAI: NAO INFORMADO\n");
        printf("MAE: %s\n", mae.nome);
    }
    else{
        printf("PAI: %s\n", pai.nome);
        printf("MAE: %s\n", mae.nome);
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int mae = 0, pai = 0, filho = 0;
    scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);

    if(mae != -1)
        pessoas[filho].mae = &pessoas[mae];
    if(pai != -1)
        pessoas[filho].pai = &pessoas[pai];
}