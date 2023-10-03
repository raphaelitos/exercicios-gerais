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

    AssociaFamiliasGruposPessoas(pessoas, numPessoas);

    for(int p = 0; p < numPessoas; p++){
        ImprimePessoa(&pessoas[p]);
    }

    return 0;
}