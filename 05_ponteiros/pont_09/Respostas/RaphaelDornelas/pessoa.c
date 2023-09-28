#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao existem pais???? (retorna se os pais existem e quem existe caso nao existam os dois)

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

int ExistePessoa(tPessoa pessoa){
    return strlen(pessoa.nome);
}

tPessoa CriaPessoa(){  
    tPessoa pessoatemp;
    
    scanf("%*[^A-Za-z]");
    scanf("%[^\n]", pessoatemp.nome);
    pessoatemp.pai = NULL;
    pessoatemp.mae = NULL;

    return pessoatemp;
}

void LePessoa(tPessoa *pessoa){
    *pessoa = CriaPessoa();
}

void ImprimePessoa(tPessoa *pessoa){
    if(!(ExistemPais(*pessoa))){
        return;
    }
    printf("NOME COMPLETO: %s\n", (*pessoa).nome);
    
    if(ExistemPais(*pessoa) == -1){
        printf("");
    }
    
}