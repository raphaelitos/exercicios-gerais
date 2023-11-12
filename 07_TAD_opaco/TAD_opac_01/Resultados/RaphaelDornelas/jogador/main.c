#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    tJogo* pjogo;
    
    do{
        pjogo = CriaJogo();
        ComecaJogo(pjogo);
        DestroiJogo(pjogo);
    }while(ContinuaJogo());

    return 0;
}