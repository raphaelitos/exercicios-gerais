#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include <stdio.h>

/// @brief verifica se um numero eh par.
/// @param  num um numero inteiro.
/// @return 0 se eh impar, 1 se eh par.
int EhPar(int num){
    return !(num % 2);
}

/// @brief retorna qual jogador deve jogar com base na rodada.
/// @param jogo o jogo em seu estado atual.
/// @param rodada numero correspondente a rodada.
/// @return o jogador da vez (jogador1 ou jogador2).
tJogador SelecionaJogador(tJogo jogo, int rodada){
    if(!EhPar(rodada)){
        return jogo.jogador1;
    }
    return jogo.jogador2;
}

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
        

    }
}

int AcabouJogo(tJogo jogo){
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}

int ContinuaJogo(){
    printf("Jogar novamente? (s,n)");
    
    char resposta = '\0';
    scanf("%*[^sn]");
    scanf("%c", &resposta);
    
    scanf("%*[^\n]");
    scanf("%*[\n]");

    return (resposta == 's');
}