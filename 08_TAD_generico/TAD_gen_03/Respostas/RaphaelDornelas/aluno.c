#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    char nome[51];
    char sexo;
    float nota;
};

tAluno *CriaAluno(){
    tAluno* alunoi = (tAluno*)malloc(sizeof(tAluno));
    alunoi->nome[0] = '\0';
    alunoi->sexo = '\0';
    alunoi->nota = 0.0;
    return alunoi;
}

void DestroiAluno(data_type aluno){
    tAluno* copia = NULL;
    if(aluno){
        copia = (tAluno*) aluno;
    }
    else return;

    free(copia);
}

void LeAluno(tAluno *aluno){
    scanf("%[^;]", aluno->nome);
    scanf(";%c;%f\n", &(aluno->sexo), &(aluno->nota));
}

char GetGeneroAluno(tAluno *aluno){
    if(aluno) return aluno->sexo;
    return '\0';
}

float GetNotaAluno(tAluno *aluno){
    if(aluno != NULL) return aluno->nota;
    return -1;
}