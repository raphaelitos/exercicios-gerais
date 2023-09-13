#include "jogada.h"
#include "tabuleiro.h"
#include <stdio.h>

tJogada LeJogada(){
    tJogada jogadaTemp;

    scanf("%*[^0-9]");
    if(scanf("%d %d", &jogadaTemp.x, &jogadaTemp.y) == 2){       
        if(EhPosicaoValidaTabuleiro(jogadaTemp.x, jogadaTemp.y)){
            if(EstaLivrePosicaoTabuleiro){
                jogadaTemp.sucesso = 1;
            }
            else{
                printf("Posicao invalida (OCUPADA - [%d,%d] )!", jogadaTemp.x, jogadaTemp.y);
                jogadaTemp.sucesso = 0;
            }
        }
        else{
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!", jogadaTemp.x, jogadaTemp.y);
            jogadaTemp.sucesso = 0;
        }
    }
    else{
        jogadaTemp.sucesso = 0;
    }

    return jogadaTemp;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}