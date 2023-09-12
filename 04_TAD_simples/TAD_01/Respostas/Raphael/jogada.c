#include "jogada.h"

tJogada LeJogada(){
    tJogada jogadaTemp;

    scanf("%*[^0-9]");
    if(scanf("%d %d", &jogadaTemp.x, &jogadaTemp.y) == 2){
        
        if((jogadaTemp.x >= 0 && jogadaTemp.x <= 2) && // dentro dos limites do tabuleiro
            (jogadaTemp.y >= 0 && jogadaTemp.y <= 2)){
            jogadaTemp.sucesso = 1;
        }
        else{
            jogadaTemp.sucesso = 0;
        }
    }
    else{
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