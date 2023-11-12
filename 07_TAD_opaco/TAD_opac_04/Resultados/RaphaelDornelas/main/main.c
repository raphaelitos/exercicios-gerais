#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

void LeAlunos(tAluno** alunos, int qtdAlunos){
    for(int i = 0; i < qtdAlunos; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
        //ImprimeAluno(alunos[i]);
    }
}

void OrdenaAlunos(tAluno** alunos, int qtd){
    int troca = 0;
    for(int i = 0; i < qtd; i++){
        troca = 0;
        for(int j = 0; j < ((qtd -1) - i); j++){
            if(ComparaMatricula(alunos[j], alunos[j + 1]) == 1){
                tAluno* aux = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = aux;
                troca = 1;  
            }
        }
        if(!troca){
            break;
        }
    }
}

void ApagaAlunos(tAluno** alunos, int qtd){
    for(int i = 0; i < qtd; i++){
        ApagaAluno(alunos[i]);
    }
    //free(alunos);
}

int main(){
    int qtd = 0;
    scanf("%d", &qtd);

    tAluno* alunos[qtd];
    LeAlunos(alunos, qtd);
    /*for(int i = 0; i < qtd; i++){
        tAluno* aluno = CriaAluno();
        LeAluno(aluno);
    }*/

    OrdenaAlunos(alunos, qtd);

    for(int a = 0; a < qtd; a++){
        if(VerificaAprovacao(alunos[a])){
            ImprimeAluno(alunos[a]);
        }
    }

    ApagaAlunos(alunos, qtd);

    return 0;
}
