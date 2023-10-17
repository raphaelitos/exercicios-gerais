#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

tTabuleiro* CriaTabuleiro(){
    tTabuleiro* ptabTemp;

    ptabTemp = (tTabuleiro*) malloc((sizeof(tTabuleiro)));

    if(ptabTemp == NULL){
        printf("erro de alocacao [ptabtemp]");
        exit(0);
    }
    
    ptabTemp->posicoes = (char**) malloc(TAM_TABULEIRO * TAM_TABULEIRO * sizeof(char));

    if(ptabTemp->posicoes == NULL){
        printf("erro de alocacao [ptabTemp->posicoes]");
        exit(0);
    }

    ptabTemp->pecaVazio = '-';
    ptabTemp->peca1 = 'X';
    ptabTemp->peca2 = '0';

    int rows = 0, cols = 0;
    for(rows = 0; rows < TAM_TABULEIRO; rows++){
        for(cols = 0; cols < TAM_TABULEIRO; cols++){
            (ptabTemp->posicoes)[rows][cols] = ptabTemp->pecaVazio;
        }
    }

    return ptabTemp;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro){
    free(tabuleiro->posicoes);
    free(tabuleiro);    
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    char skin;
    
    if(peca == PECA_1){
        skin = tabuleiro->peca1;
    }
    else{
        skin = tabuleiro->peca2;;
    }
    
    tabuleiro->posicoes[y][x] = skin;

}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
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

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    char skin;
    if(peca == PECA_1){
        skin = tabuleiro->peca1;
    }
    else{
        skin = tabuleiro->peca2;
    }
    return tabuleiro->posicoes[y][x] == skin;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    return tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    return ((x >= 0 && x < TAM_TABULEIRO) &&
            (y >= 0 && y < TAM_TABULEIRO));
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    int i = 0, j = 0;

    for(i = 0; i < TAM_TABULEIRO; i++){
        printf("\t");
        for(j = 0; j <  TAM_TABULEIRO; j++){
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}