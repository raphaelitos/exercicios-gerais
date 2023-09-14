#include "jogo.h"
#include <stdio.h>

int main(){
    tJogo jogo;
    jogo = CriaJogo();
    
    do{
        ComecaJogo(jogo);
    }while(ContinuaJogo());

    return 0;
}