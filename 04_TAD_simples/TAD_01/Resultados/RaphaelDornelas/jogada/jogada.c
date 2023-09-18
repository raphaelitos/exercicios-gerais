#include "jogada.h"
#include "tabuleiro.h"
#include <stdio.h>

tJogada LeJogada(){
    tJogada jogadaTemp;


    printf("Digite uma posicao (x e y):\n");
    if(scanf("%d %d", &jogadaTemp.x, &jogadaTemp.y) == 2){       
        jogadaTemp.sucesso = 1;
    }
    else{
        scanf("%*[^\n]");
        scanf("%*[\n]");
        jogadaTemp.sucesso = 0;
    }
    
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