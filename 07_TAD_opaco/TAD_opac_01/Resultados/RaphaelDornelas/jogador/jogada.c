#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogada
{
    int x;
    int y;
    int sucesso;
};


tJogada* CriaJogada(){
    tJogada* jogadaI = (tJogada*)malloc(sizeof(tJogada));
    if(jogadaI == NULL){
        printf("falha em alocar jogada!\n");
        exit(0);
    }

    return jogadaI;
}

void DestroiJogada(tJogada* jogada){
    if(jogada) free(jogada);
}

void LeJogada(tJogada* jogada){
    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d", &jogada->x, &jogada->y) == 2){       
        jogada->sucesso = 1;
    }
    else{
        scanf("%*[^\n]");
        scanf("%*[\n]");
        jogada->sucesso = 0;
    }
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