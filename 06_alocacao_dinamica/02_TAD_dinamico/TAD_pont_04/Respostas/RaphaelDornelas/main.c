#include <stdio.h>
#include "aluno.h"

/// @brief preenche um vetor de alunos
/// @param alunos um vetor de alunos
/// @param qtdalunos o tamanho do vetor de alunos
void LeAlunos(tAluno** alunos, int qtdalunos){
    int a = 0;

    for(a = 0; a < qtdalunos; a++){
        alunos[a] = CriaAluno();
    }
}

void OrdenaAlunos(tAluno* alunos[], int qtdAlunos){
    
    tAluno* aux;
    int teveTroca = 0;

    for(int a = 0; a < qtdAlunos - 1; a++){
        teveTroca = 0; 
        for(int b = a; b < qtdAlunos - (1 + a); b++){
            if(ComparaMatricula(alunos[b], alunos[b + 1]) == 1){
                aux = alunos[b];
                alunos[b] = alunos[b + 1];
                alunos[b + 1] = aux;
                teveTroca = 1;
            }
        }
        if(!teveTroca){
            break;
        }
    }
}

int main(){

    int qtdAlunos = 0;
    scanf("%d\n", &qtdAlunos);

    tAluno* alunos[qtdAlunos]; //vetor de ponteiros p tAluno
    //LeAlunos(alunos, qtdAlunos);
    for(int a = 0; a < qtdAlunos; a++){
        alunos[a] = CriaAluno();
        LeAluno(&(*alunos[a]));
    }


    OrdenaAlunos(alunos, qtdAlunos);

    for(int i  = 0; i < qtdAlunos; i++){
        if(VerificaAprovacao(&(*alunos[i]))){
            ImprimeAluno(alunos[i]);
        }
    }

    for(int t = 0; t < qtdAlunos; t++){
        ApagaAluno(alunos[t]);
    }

    return 0;
}