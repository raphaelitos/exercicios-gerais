#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"


tJogador CriaJogador(int idJogador){
    tJogador jogadorTemp;
    
    jogadorTemp.id = idJogador;

    return jogadorTemp;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    tJogada jogada = LeJogada();

    while(!FoiJogadaBemSucedida(jogada)){
        jogada = LeJogada(jogada);
    }
    
    MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){

    int i = 0, j = 0, count = 0;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id)){
                count++;
            }        
        }
        if(count == 3) return 1;
        count = 0;
    }//verifying cols
    
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador.id)){
                count++;
            }        
        }
        if(count == 3) return 1;
        count = 0;
    }//verifying rows
    
    if(tabuleiro.posicoes[0][0] == tabuleiro.posicoes[1][1] &&
        tabuleiro.posicoes[1][1] == tabuleiro.posicoes[2][2])
        return 1;
    
    if(tabuleiro.posicoes[0][2] == tabuleiro.posicoes[1][1] &&
        tabuleiro.posicoes[1][1] == tabuleiro.posicoes[2][0])
        return 1;
    //verifying diagonals

    return 0;
}