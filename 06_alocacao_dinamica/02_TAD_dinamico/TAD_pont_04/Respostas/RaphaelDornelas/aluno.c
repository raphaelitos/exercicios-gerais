#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tAluno* CriaAluno(){
    tAluno* paluno;

    paluno = (tAluno *) malloc(sizeof(tAluno));

    if(paluno == NULL){
        printf("falha na alocacao [paluno]");
        exit(0);
    }
    paluno->nome == NULL;
    paluno->n1 = -1;
    paluno->n3 = -1;
    paluno->n2 = -1;

    return paluno;
} 

void LeAluno(tAluno *aluno){
    char nome[50];
    scanf("%*[^A-Za-z]"); //limpeza.
    scanf("%s", nome);
    //printf("leitura: %s", nome);
    aluno->nome = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    if(aluno->nome == NULL){
        printf("Erro na alocacao [aluno->nome]\n");
        exit(0);
    }
    strcpy(aluno->nome, nome);
    scanf("%3d", &(aluno->matricula));
    scanf("%d %d %d", &(aluno->n1), &(aluno->n2), &(aluno->n3));
    //printf("\nnome: %s", aluno->nome);
    // printf("\nMatricula: %d", aluno.matricula);
    // printf("\nnotas: %d %d %d", aluno.n1, aluno.n2, aluno.n3);
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){

    if(aluno1->matricula > aluno2->matricula) 
        return 1;
    if(aluno1->matricula < aluno2->matricula) 
        return -1;
    return 0;
}

int CalculaMediaAluno(tAluno* aluno){
    int media = 0;
    media = (aluno->n1 + aluno->n2 + aluno->n3)/3;
    return media;
}

int VerificaAprovacao(tAluno* aluno){
    return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}