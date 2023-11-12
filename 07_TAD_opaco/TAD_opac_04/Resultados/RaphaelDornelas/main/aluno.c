#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_NOTAS 3
#define MEDIA_MIN 7

struct Aluno
{
    char* nome;
    int matricula;
    float n1, n2, n3;
};

tAluno* CriaAluno(){
    tAluno* alunoTemp = (tAluno*)malloc(sizeof(tAluno));

    alunoTemp->matricula = -1;
    alunoTemp->n1 = -1;
    alunoTemp->n2 = -1;
    alunoTemp->n3 = -1;
    alunoTemp->nome = NULL;

    return alunoTemp;
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno){
    char nome[1001];
    scanf("%*[^A-Za-z]");
    scanf("%s", nome);
    aluno->nome = (char*) malloc((strlen(nome) + 1) * sizeof(char));
    if(aluno->nome == NULL){
        printf("Falha em alocar nome de aluno\n");
        exit(0);
    }
    strcpy(aluno->nome, nome);
    scanf("%d", &aluno->matricula);
    scanf("%f %f %f", &(aluno->n1), &(aluno->n2), &(aluno->n3));
    
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula){
        return 1;
    }
    if(aluno1->matricula < aluno2->matricula){
        return -1;
    }
    return 0;
}

int CalculaMediaAluno(tAluno* aluno){
    return((int)((aluno->n1 + aluno->n2 + aluno->n3)/QTD_NOTAS));
}

int VerificaAprovacao(tAluno* aluno){
    return(CalculaMediaAluno(aluno) >= MEDIA_MIN);
}

void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
    //printf("%d\n", aluno->matricula);
}   