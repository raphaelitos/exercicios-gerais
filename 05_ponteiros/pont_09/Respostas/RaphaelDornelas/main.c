#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int numPessoas = 0;
    scanf("%d", &numPessoas);

    tPessoa pessoas[numPessoas];

    for(int i = 0; i < numPessoas; i++){
        CriaPessoa(&pessoas[i]);
    }

    return 0;
}