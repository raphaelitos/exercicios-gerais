#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>

typedef void (*FuncPtr)(void*);

typedef struct tarefa{
    int prioridade;     
    void* conteudo;
    FuncPtr executa;
    FuncPtr destroi;
}tTarefa;

struct agendatarefas{
    int nAlnAlocados;
    int nElementos;
    tTarefa** tarefas;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas *agI = (tAgendaTarefas*)malloc(sizeof(tAgendaTarefas));
    if(agI == NULL){
        printf("Falha ao alocar nova agenda!\n");
        exit(0);
    }
    agI->nElementos = numElem;
    agI->nAlnAlocados = 0;
    agI->tarefas = (tTarefa**) malloc(numElem * sizeof(tTarefa*));
    if(agI->tarefas == NULL){
        printf("Falha ao alocar nova tarefas!\n");
        exit(0);
    }

    for(int i = 0; i < numElem; i++){
        agI->tarefas[i] = NULL;
    }
    
    return agI;
}

void DestroiTarefa(tTarefa* t){
    if(t != NULL){
        if(t->conteudo != NULL){
            t->destroi(t->conteudo);
        }
        free(t);
    }
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    if(tar != NULL && tar->tarefas != NULL){
        for(int i = 0; i < tar->nAlnAlocados; i++){
            DestroiTarefa(tar->tarefas[i]);
        }
        free(tar->tarefas);
    }
    free(tar);
}

tTarefa* CadastraTarefa(int prioridade, void *conteudo, void (*executa)(void*), void (*destroi)(void*)){
    tTarefa *tarefa = (tTarefa*)malloc(sizeof(tTarefa));
    if(tarefa == NULL){
        printf("falha em alocar tarefa para cadastro\n");
        exit(0);
    }
    tarefa->prioridade = prioridade;
    tarefa->conteudo = conteudo;
    tarefa->executa = executa;
    tarefa->destroi = destroi;
    
    return tarefa;
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    if(tar == NULL || tar->tarefas == NULL){
        printf("agenda ou vetor de tarefas invalido\n");
        return;
    }
    if(tar->nAlnAlocados > tar->nElementos){
        tar->tarefas = realloc(tar->tarefas, tar->nElementos * sizeof(tTarefa*)); //a new chunk with the actual size    
        tar->nElementos += tar->nElementos;
    }
    tar->tarefas[tar->nAlnAlocados] = CadastraTarefa(prioridade, tarefa, executa, destroi);
    (tar->nAlnAlocados)++;
}

void ExecutaTarefa(tTarefa* t){
    t->executa(t->conteudo);
}

int Comparar(tTarefa* t1, tTarefa* t2){
    return(t2->prioridade - t1->prioridade);
}


void OrdenaTarefas(tTarefa** tarefas, int tam){
    
    int troca = 1;
    while(troca){
        troca = 0;
        for(int i = 0; i < (tam - 1); i++){
            if(Comparar(tarefas[i], tarefas[i + 1]) > 0){
                tTarefa *temp = tarefas[i];
                tarefas[i] = tarefas[i + 1];
                tarefas[i + 1] = temp;
                troca = 1;
            }
        }
    }
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    
    OrdenaTarefas(tar->tarefas, tar->nAlnAlocados);
    
    for(int t = 0; t < tar->nAlnAlocados; t++){
        ExecutaTarefa(tar->tarefas[t]);
    }
}