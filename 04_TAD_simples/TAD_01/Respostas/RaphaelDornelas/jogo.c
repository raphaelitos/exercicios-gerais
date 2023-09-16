#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include <stdio.h>

tJogo CriaJogo(){
    tJogo jogoi;

    jogoi.tabuleiro = CriaTabuleiro();
    jogoi.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogoi.jogador2 = CriaJogador(ID_JOGADOR_2);

    return jogoi;
}

void ComecaJogo(tJogo jogo){

    while(!AcabouJogo(jogo)){
        
        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if(VenceuJogador(jogo.jogador1, jogo.tabuleiro)){
            printf("JOGADOR 1 Venceu!\n");
            break;
        }

        jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);
        if(VenceuJogador(jogo.jogador2, jogo.tabuleiro)){
            printf("JOGADOR 2 Venceu!\n");
            break;
        }

        if(AcabouJogo(jogo)){
            printf("Sem vencedor!\n");
            break;
        }
    }
}

int AcabouJogo(tJogo jogo){
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}

int ContinuaJogo(){
    printf("Jogar novamente? (s,n)\n");
    
    char resposta = '\0';
    scanf("%*[^ns]");
    scanf("%c", &resposta);

    return (resposta == 's');
}