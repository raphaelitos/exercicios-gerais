#include "jogo.h"
#include <stdio.h>

int main(){
    tJogo jogo;
    jogo = CriaJogo();
    
    ComecaJogo(jogo);
    ContinuaJogo();

    return 0;
}