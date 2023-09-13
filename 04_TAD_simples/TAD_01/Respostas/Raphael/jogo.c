#include "jogo.h"
#include "tabuleiro.h"
#include <stdio.h>

tJogo CriaJogo(){
    tJogo jogoi;

    jogoi.tabuleiro = CriaTabuleiro();
    jogoi.jogador1 = CriaJogador(1);
    jogoi.jogador2 = CriaJogador(2);

    return jogoi;
}


int AcabouJogo(tJogo jogo){
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}