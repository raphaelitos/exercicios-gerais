#include "jogo.h"
#include "tabuleiro.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

tJogo* CriaJogo(){
    tJogo* pjogoi = (tJogo *) malloc(sizeof(tJogo));

    if(pjogoi == NULL){
        exit(0);
    }

    pjogoi->tabuleiro = CriaTabuleiro();
    pjogoi->jogador1 = CriaJogador(ID_JOGADOR_1);
    pjogoi->jogador2 = CriaJogador(ID_JOGADOR_2);

    return pjogoi;
}

void ComecaJogo(tJogo* jogo){

    do{

        JogaJogador(jogo->jogador1, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if(VenceuJogador(jogo->jogador1, jogo->tabuleiro)){
            printf("JOGADOR 1 Venceu!\n");
            DestroiJogo(jogo);
            break;
        }

        if(AcabouJogo(jogo)){
            printf("Sem vencedor!\n");
            DestroiJogo(jogo);
            break;
        }

        JogaJogador(jogo->jogador2, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if(VenceuJogador(jogo->jogador2, jogo->tabuleiro)){
            printf("JOGADOR 2 Venceu!\n");
            DestroiJogo(jogo);
            break;
        }

        if(AcabouJogo(jogo)){
            printf("Sem vencedor!\n");
            DestroiJogo(jogo);
            break;
        }

    }while(!AcabouJogo(jogo));
}

int AcabouJogo(tJogo* jogo){
    return !TemPosicaoLivreTabuleiro(jogo->tabuleiro);
}

int ContinuaJogo(){
    printf("Jogar novamente? (s,n)\n");
    
    char resposta = '\0';
    scanf("%*[^ns]");
    scanf("%c", &resposta);

    return (resposta == 's');
}

void DestroiJogo(tJogo* jogo){

    DestroiTabuleiro(jogo->tabuleiro);
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    free(jogo);
}