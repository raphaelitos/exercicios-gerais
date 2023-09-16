#include "jogada.h"
#include "tabuleiro.h"
#include <stdio.h>

tJogada LeJogada(){
    tJogada jogadaTemp;
    jogadaTemp.sucesso = 0;

    do{
        scanf("%*[^0-2]");
        if(scanf("%d %d", &jogadaTemp.x, &jogadaTemp.y) == 2){       
            jogadaTemp.sucesso = 1;
        }
        else{
            scanf("%*[^\n]");
            scanf("%*[\n]");
            jogadaTemp.sucesso = 0;
        }
    }while(!FoiJogadaBemSucedida(jogadaTemp));
    return jogadaTemp;
}

int ObtemJogadaX(tJogada jogada){
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada){
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada){
    return jogada.sucesso;
}