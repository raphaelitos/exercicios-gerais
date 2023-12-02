#include <stdio.h>
#include <stdlib.h>
#include "estabelecimento.h"

int main(){
    tEstabelecimento *estab = CriaEstabelecimento();
    LeEstabelecimento(estab);
    ImprimeProdutosEmFaltaEstabelecimento(estab);
    DestroiEstabelecimento(estab);
    return 0;
}