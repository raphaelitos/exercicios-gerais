#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"

// if(EstaLivrePosicaoTabuleiro()){
//                 printf("Jogada [%d,%d]!\n", jogadaTemp.x, jogadaTemp.y);
//                 jogadaTemp.sucesso = 1;
//             }
//             else{
//                 printf("Posicao invalida (OCUPADA - [%d,%d] )!", jogadaTemp.x, jogadaTemp.y);
//                 jogadaTemp.sucesso = 0;
//             }

tJogador CriaJogador(int idJogador){
    tJogador jogadorTemp;
    
    jogadorTemp.id = idJogador;

    return jogadorTemp;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){
    
    tJogada jogada;
    printf("Jogador %d\n", jogador.id);
    do{
        jogada = LeJogada();

        if(EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y)){
            printf("Jogada [%d,%d]!\n", jogada.x, jogada.y);
            jogada.sucesso = 1;
        }
        else{
            printf("Posicao invalida (OCUPADA - [%d,%d] )!", jogada.x, jogada.y);
            jogada.sucesso = 0;
        }

    }while(!FoiJogadaBemSucedida(jogada));
    
    // printf("Jogador %d\n", jogador.id);
    // tJogada jogada = LeJogada();

    // while(!FoiJogadaBemSucedida(jogada)){
    //     jogada = LeJogada(jogada);
    // }
    
    MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){

    int rows = 0, cols = 0;
    int countV = 0, countH = 0; //vertical and horizontal counters
    
    for(rows = 0; rows < TAM_TABULEIRO; rows++){
        for(cols = 0; cols < TAM_TABULEIRO; cols++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, cols, rows, jogador.id)){
                countH++; //verifying rows
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, rows, cols, jogador.id)){
                countV++; //verifying cols
            }        
        }
        if(countV == 3 || countH == 3) return 1;
        countV = 0, countH = 0; 
    }
    
    if(tabuleiro.posicoes[0][0] == tabuleiro.posicoes[1][1] &&
        tabuleiro.posicoes[1][1] == tabuleiro.posicoes[2][2]){
        return 1;
    }
    if(tabuleiro.posicoes[0][2] == tabuleiro.posicoes[1][1] &&
        tabuleiro.posicoes[1][1] == tabuleiro.posicoes[2][0]){
        return 1;
    }
    //diagonals verified

    return 0;
}