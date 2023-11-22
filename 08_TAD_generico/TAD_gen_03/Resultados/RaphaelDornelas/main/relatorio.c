#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define NOTA_MIN 6
#define MASC 'M'
#define FEM 'F'
#define OUTROS 'O'
#define PORCENT '%'

int FoiAprovadoAluno(tAluno* aluno){
    return(GetNotaAluno(aluno) >= NOTA_MIN);
}

void IncrementaSexoAlunos(int* oQtd, int* fQtd, int* mQtd, tAluno* aluno){
    if(GetGeneroAluno(aluno) == MASC){
        (*mQtd)++;
    }
    else if(GetGeneroAluno(aluno) == FEM){
        (*fQtd)++;
    }
    else{
        (*oQtd)++;
    }
}

float  CalculaPorcentagem(int qtd, int tam){
    return(((float)qtd/tam) * 100);
}

void ImprimeRelatorio(Vector *alunos){
    int mQtd = 0, fQtd = 0, oQtd = 0, qtdApv = 0, tam = VectorSize(alunos);
    float somaNotas = 0.0;

    for(int i = 0; i < tam; i++){
        tAluno *copia = (tAluno*) VectorGet(alunos, i);
        somaNotas += GetNotaAluno(copia);
        if(FoiAprovadoAluno(copia)){
            qtdApv++;
        }
        IncrementaSexoAlunos(&oQtd, &fQtd, &mQtd, copia);
    }

    float nMedia = somaNotas/tam, pctApv = CalculaPorcentagem(qtdApv, tam);
    float oMedia = CalculaPorcentagem(oQtd, tam), mMedia = CalculaPorcentagem(mQtd, tam), fMedia = CalculaPorcentagem(fQtd, tam);

    printf("Media das notas: %.2f\nPorcentagem de alunos aprovados: %.2f%c\n", nMedia, pctApv, PORCENT);
    printf("Porcentagem de cada genero:\nMasculino: %.2f%c\n", mMedia, PORCENT);
    printf("Feminino: %.2f%c\nOutro: %.2f%c", fMedia, PORCENT, oMedia, PORCENT);
}