#include "jogo.h"
#include <stdio.h>

int main(){
    tJogo* pjogo;
    
    do{
        pjogo = CriaJogo();
        ComecaJogo(pjogo);
        DestroiJogo(pjogo);
    }while(ContinuaJogo());

    return 0;
}