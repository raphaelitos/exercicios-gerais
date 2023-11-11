#include "aluno.h"
#include <stdio.h>

void LeAlunos(tAluno** alunos, int qtdAlunos){
    for(int i = 0; i < qtdAlunos; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
        //ImprimeAluno(alunos[i]);
    }
}

void TrocaAlunos(tAluno* a, tAluno* b){
    tAluno* temp = a;
    a = b;
    b = temp;
}

void OrdenaAlunos(tAluno** alunos){
    
    int tam = sizeof(alunos)/sizeof(alunos[0]);
    int troca = 1;

    if(alunos == NULL){
        return;
    }

    while (troca)
    {
        troca = 0;
        for(int i = 0; i < (tam - 1); i++){
            if(ComparaMatricula(alunos[i], alunos[i+1]) == 1){
                troca = 1;
                TrocaAlunos(alunos[i], alunos[i + 1]);
            }
        }
    }
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

    OrdenaAlunos(alunos);

    for(int a = 0; a < qtd; a++){
        if(VerificaAprovacao(alunos[a]) == 1){
            ImprimeAluno(alunos[a]);
        }
    }

    return 0;
}
