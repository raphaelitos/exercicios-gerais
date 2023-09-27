#include "evento.h"
#include <stdio.h>

void LeEvento(Evento *evento){
    scanf("%*[^A-Za-z]");
    scanf("%s", evento->nome);
    scanf("%d %d %d", evento->dia, evento->mes, evento->ano);
}

void cadastrarEvento(Evento* eventos, int* numEventos){
    Evento *evenTemp;
    LeEvento(evenTemp);

    eventos[*numEventos] = *evenTemp;
    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    for(int i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int id = 0;
    scanf("%d", &id);

    if(id < *numEventos){
        printf("Indice invalido!\n");
        return;
    }

    if(scanf("%d %d %d", eventos[id].dia, eventos[id].mes, eventos[id].ano) == 3){
        printf("Data modificada com sucesso!\n");
    }  
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    
}