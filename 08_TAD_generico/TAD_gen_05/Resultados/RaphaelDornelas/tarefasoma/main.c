#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>

int EhPreixoValido(char p){
    return(p == 'I' || p == 'M' || p == 'S');
}

char ObtemPrefixoValido(){
    char pref = '\0';
    while (1){
        scanf("%c ", &pref);
        if(EhPreixoValido(pref)){
            return pref;
        }
        printf("Digite um prefixo valido (I, M, S)!\n");
        scanf("%*[^\n]");
        scanf("%*c");
    }
}

void CadastraTarefas(char pref, int prioridade, tAgendaTarefas* agenda){
    
    float n1 = 0, n2 = 0;
    char msg[501];

    if(pref == 'I'){
        scanf("%[^\n]\n", msg);
        tImpr *imp = CriaTarefaImprimir(msg);
        CadastraTarefaNaAgenda(agenda, prioridade, imp, ExecutaTarefaImprimir, DestroiTarefaImprimir);
    }
    else if(pref == 'M'){
        scanf("%f %f", &n1, &n2);
        tMult *mult = CriaTarefaMultiplicar(n1, n2);
        CadastraTarefaNaAgenda(agenda, prioridade, mult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
    }
    else{
        scanf("%f %f", &n1, &n2);
        tSoma *sum = CriaTarefaSoma(n1, n2);
        CadastraTarefaNaAgenda(agenda, prioridade, sum, ExecutaTarefaSoma, DestroiTarefaSoma);  
    }
}

int main(){
    
    printf("Digite o numero de tarefas: ");
    int qtd = 0;
    scanf("%d\n", &qtd);

    char pref = '\0';
    int prioridade = 0;
    
    tAgendaTarefas *agenda = CriaAgendaDeTarefas(qtd);

    for(int i = 0; i < qtd; i++){
        while(1){
            scanf("%d %c ", &prioridade, &pref);
            if(EhPreixoValido(pref)){
                break;
            }
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^\n]");
            scanf("%*c");
        }
        CadastraTarefas(pref, prioridade, agenda);
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}