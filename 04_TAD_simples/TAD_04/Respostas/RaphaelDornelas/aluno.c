#include "aluno.h"
#include <stdio.h>
#include <string.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
    tAluno aluno;

    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno(){
    char* nome[50];
    int matricula = 0, n1 = 0, n2 = 0, n3 = 0;
    scanf("%*[^\n][\n]"); //limpeza.
    scanf("%s", nome);
    scanf("%3d", &matricula);
    scanf("%d %d %d", &n1, &n2, &n3);

    tAluno aluno = CriaAluno(nome, matricula, n1, n2, n3);

    return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2){
    if(aluno1.matricula > aluno2.matricula) return 1;
    if(aluno1.matricula < aluno2.matricula) return -1;
    return 0;
}

int CalculaMediaAluno(tAluno aluno){
    int media = 0;
    media = (aluno.n1 + aluno.n2 + aluno.n3)/3;
    return media;
}

int VerificaAprovacao(tAluno aluno){
    return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno aluno){
    printf("%s\n", aluno.nome);
}