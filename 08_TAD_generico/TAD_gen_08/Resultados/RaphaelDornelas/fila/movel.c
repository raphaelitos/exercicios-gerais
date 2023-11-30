#include "movel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movel{
    char nome[31];
};

tMovel *CriaMovel(char *nome){
    tMovel* m = (tMovel*)malloc(sizeof(tMovel));
    if(m == NULL){
        printf("falha na criacao de movel\n");
        exit(1);
    }
    strcpy(m->nome, nome);

    return m;
}

void DestroiMovel(tMovel *m){
    free(m);
}

tMovel *LeMovel(){
    char nome[31];
    scanf("%*[^A-Za-z]");
    scanf("%s\n", nome);

    tMovel* mov = CriaMovel(nome);
    return mov;
}

void ImprimeMovel(tMovel *m){
    if(m == NULL){
        printf("movel invalido!\n");
        exit(1);
    }
    printf("%s\n", m->nome);
}