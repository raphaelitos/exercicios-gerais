#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

struct generic{
    int tipo;
    int numElemem;
};

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric* genI = (tGeneric *)malloc(numElem * sizeof(type));
    if(genI == NULL){
        printf("Erro ao alocar novo vetor!\n");
        exit(0);
    }
    return genI;
}

void DestroiGenerico(tGeneric* gen){
    free(gen);
}

void LeGenerico(tGeneric* gen){
    if(gen->tipo == FLOAT){
        for(int i = 0; i < gen->numElemem; i++){
            scanf("%f", &gen[i]);
        }
    }
    else if(gen->tipo == INT){
        for(int i = 0; i < gen->numElemem; i++){
            scanf("%d", &gen[i]);
        }
    }
    else{
        printf("Nao eh um tipo valido!");
    }
}

void ImprimeGenerico(tGeneric* gen){
    if(gen->tipo == FLOAT){
        for(int i = 0; i < gen->numElemem; i++){
            printf("%d", gen[i]);
        }
    }
    else if(gen->tipo == INT){
        for(int i = 0; i < gen->numElemem; i++){
            printf("%.2f", gen[i]);
        }
    }
    else{
        printf("Nao eh um tipo valido!");
    }
}