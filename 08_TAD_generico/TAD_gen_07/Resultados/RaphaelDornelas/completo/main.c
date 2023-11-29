#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int nInt = 0, altura = 0, largura = 0, tipo = 0;
    scanf("%d\n", &nInt);

    Imagem *img = LerImagem();
    Histograma *histo = CalcularHistograma(img, nInt);

    MostrarHistograma(histo);

    DestruirImagem(img);
    DestruirHistograma(histo);

    return 0;
}