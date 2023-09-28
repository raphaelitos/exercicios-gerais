#include "evento.h"
#include <stdio.h>

/// @brief Verifica se um indice eh valido (se esta dentro da dimensoes do vetor)
/// @param id ponteiro para o indice a ser verificado
/// @param numElementos ponteiro para o numero de elementos do vetor
/// @return 1 se for válido, 0 caso contrário.
int ehIndiceValido(int * id, int *numElementos){
    return *id >= 0 && *id < *numElementos;
}

/// @brief Lê um evento.
/// @param evento ponteiro para o evento que será lido.
void LeEvento(Evento *evento){
    scanf("%*[^A-Za-z]");
    scanf("%s", evento->nome);
    scanf("%d %d %d", &evento->dia, &evento->mes, &evento->ano);
}

/// @brief Imprime mensagem indicando erro de indexacao.
void InvalidIDMsg(){
    printf("Indice invalido!\n");
}

void cadastrarEvento(Evento* eventos, int* numEventos){
    
    if(*numEventos == MAX_EVENTOS){
        printf("Limite de eventos atingido!\n");
        return;
    }

    LeEvento(&eventos[*numEventos]);

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

    if(!ehIndiceValido(&id, numEventos)){
        InvalidIDMsg();
        return;
    }

    if(scanf("%d %d %d", &eventos[id].dia, &eventos[id].mes, &eventos[id].ano) == 3){
        printf("Data modificada com sucesso!\n");
    }
    else{
        printf("Formato invalido!");
        return;
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if(!(ehIndiceValido(indiceA, numEventos) && ehIndiceValido(indiceB, numEventos))){
        InvalidIDMsg();
        return; 
    }
    
    Evento aux = eventos[*indiceA];
    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = aux;
    printf("Eventos trocados com sucesso!\n");
}