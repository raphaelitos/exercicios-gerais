#include "tabuleiro.h"
#include <stdio.h>

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabTemp;
    
    tabTemp.pecaVazio = '-';
    tabTemp.peca1 = 'X';
    tabTemp.peca2 = '0';

    int rows = 0, cols = 0;
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
        skin = 'X';
    }
    else{
        skin = tabuleiro.peca2;;
    }
    
    if(EhPosicaoValidaTabuleiro(x, y)){
        if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
            tabuleiro.posicoes[y][x] = skin;
            printf("Jogada [%d,%d]!\n", x, y);
        }
        else{
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        }
    }
    else{
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )", x, y);
    }

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro){
    int i = 0, j = 0;

    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, j, i)){
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
    return ((x >= 0 && x < TAM_TABULEIRO) &&
            (y >= 0 && y < TAM_TABULEIRO));
}

void ImprimeTabuleiro(tTabuleiro tabuleiro){
    int i = 0, j = 0;

    for(i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(j = 0; j <  TAM_TABULEIRO; j++){
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}