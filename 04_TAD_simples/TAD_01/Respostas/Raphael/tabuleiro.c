#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabTemp;
    
    int rows = 0, cols = 0;
    tabTemp.pecaVazio = '-';
    tabTemp.peca1 = "X";
    tabTemp.peca2 = "0";

    for(rows = 0; rows < TAM_TABULEIRO; rows++){
        for(cols = 0; cols < TAM_TABULEIRO; cols++){
            tabTemp.posicoes[rows][cols] = tabTemp.pecaVazio;
        }
    }

    return tabTemp;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y){
    char skin;
    
    if(peca == PECA_1){
        skin = tabuleiro.peca1;
    }
    else{
        skin = tabuleiro.peca2;;
    }
    
    tabuleiro.posicoes[y][x] = skin;

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i = 0, j = 0;

    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(tabuleiro.posicoes[i][j] == tabuleiro.pecaVazio){
                return 1;
            }
        }
    }
    
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca){
    char skin;
    if(peca == PECA_1){
        skin = tabuleiro.peca1;
    }
    else{
        skin = tabuleiro.peca2;
    }
    return tabuleiro.posicoes[y][x] == skin;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    return tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    return ((x >= 0 && x < TAM_TABULEIRO) && //inside the board
            (y >= 0 && y < TAM_TABULEIRO));
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i = 0, j = 0;

    for(i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(j = 0; j <  TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
            if(j == TAM_TABULEIRO - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
}