#include "tabuleiro.h"

tTabuleiro CriaTabuleiro(){
    tTabuleiro tabTemp;
    
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
        skin = '0';
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
        skin = 'X';
    }
    else{
        skin = '0';
    }
    return tabuleiro.posicoes[y][x] == skin;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y){
    return tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio;
}