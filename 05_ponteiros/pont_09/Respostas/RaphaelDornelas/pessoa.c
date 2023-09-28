#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao existem pais???? (retorna se os pais existem e quem existe caso nao existam os dois)

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
    if(!(ExistePessoa(*pessoa->mae) && ExistePessoa(*pessoa->pai))){
        return;
    }
    printf("NOME COMPLETO: %s\n", (*pessoa).nome);
    
}