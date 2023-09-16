#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"
#include <stdio.h>

tJogador CriaJogador(int idJogador){
    tJogador jogadorTemp;
    
    jogadorTemp.id = idJogador;

    return jogadorTemp;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    
    tJogada jogada;
    
    do{
        printf("Jogador %d\n", jogador.id);
        printf("Digite uma posicao (x e y):\n");
        jogada = LeJogada();
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    }while(!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), jogador.id));

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){

    int rows = 0, cols = 0;
    int countV = 0, countH = 0; //vertical and horizontal counters
    
    for(rows = 0; rows < TAM_TABULEIRO; rows++){
        for(cols = 0; cols < TAM_TABULEIRO; cols++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, cols, rows, jogador.id)){ //verifying rows
                countH++; 
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, rows, cols, jogador.id)){ //verifying cols
                countV++; 
            }        
        }
        if(countV == 3 || countH == 3) return 1;
        countV = 0, countH = 0; 
    }
    
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador.id)&&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id)&&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador.id)){
        return 1;
    }
    if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id)&&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id)&&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id)){
        return 1;
    }
    //diagonals verified

    return 0;
}