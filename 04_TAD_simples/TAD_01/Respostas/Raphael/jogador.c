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

    int pecaTemp = 0;
    if(jogador.id == 1){
        pecaTemp = PECA_1;
    }
    else{
        pecaTemp = PECA_2;
    }
    
    MarcaPosicaoTabuleiro(tabuleiro, pecaTemp, ObtemJogadaX(jogada), ObtemJogadaY(jogada));

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
    char peca;
    if(jogador.id == 1){
        peca = 'X';
    }
    else{
        peca = '0';
    }
    int i = 0, j = 0;
    for(i = 0; i < TAM_TABULEIRO; i++){
        for(j = 0; j < TAM_TABULEIRO; j++){
            if(i == 0){
                
            }
        }
    }
}