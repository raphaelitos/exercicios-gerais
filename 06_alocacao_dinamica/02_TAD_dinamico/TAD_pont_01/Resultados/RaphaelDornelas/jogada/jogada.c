#include "jogada.h"
#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

tJogada* CriaJogada(){

    tJogada* pJogada = (tJogada *) malloc(sizeof(tJogada));
    
    if(pJogada == NULL){
        printf("memoria nao alocada :/");
        exit(0);
    }

    return pJogada;
}

void LeJogada(tJogada* jogada){

    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d", &(jogada->x), &(jogada->y)) == 2){       
        jogada->sucesso = 1;
    }
    else{
        scanf("%*[^\n]");
        scanf("%*[\n]");
        jogada->sucesso = 0;
    }
}

void DestroiJogada(tJogada* jogada){
    free(jogada);
}

int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada){
    return jogada->sucesso;
}