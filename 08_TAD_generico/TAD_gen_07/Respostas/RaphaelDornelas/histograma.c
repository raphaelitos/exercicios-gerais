#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tHistograma{
    int *nPixels;    
    int nIntervalos;
    int tamIntervalos;
};

/*No cálculo do histograma, se a imagem for do tipo float, os valores dos pixels devem
ser convertidos de [0.0, 1.0] para [0, 255]. Para isso, multiplique o valor float por 255 e converta
o resultado para o tipo int.*/

Histograma *CalcularHistograma(Imagem *img, int nIntervalos){
    
}