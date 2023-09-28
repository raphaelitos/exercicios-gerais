#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>

int main(){ 
    int numPessoas = 0;
    scanf("%d", &numPessoas);

    tPessoa pessoas[numPessoas];

    for(int i = 0; i < numPessoas; i++){
        LePessoa(&pessoas[i]);
    }

    int numAssociacoes = 0;
    scanf("%d", &numAssociacoes);

    for(int a = 0; a < numAssociacoes; a++){
        AssociaFamiliasGruposPessoas(pessoas);
    }

    for(int p = 0; p < numPessoas; p++){
        ImprimePessoa(pessoas);
    }

    return 0;
}