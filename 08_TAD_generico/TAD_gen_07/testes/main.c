#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int nInt = 0, altura = 0, largura = 0, tipo = 0;
    scanf("%d\n%d %d %d\n", &nInt, &altura, &largura, &tipo);

    Imagem *img = CriarImagem(altura, largura, (Tipo)tipo);
    Histograma *histo = CalcularHistograma(img, nInt);

    MostrarHistograma(histo);

    DestruirImagem(img);
    DestruirHistograma(histo);

    return 0;
}
