#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct tHistograma
{
    int nPixels;
    int nIntervalos;
    int tamIntervalos;
    int *vetHistograma;
};


/*No cálculo do histograma, se a imagem for do tipo float, os valores dos pixels devem
ser convertidos de [0.0, 1.0] para [0, 255]. Para isso, multiplique o valor float por 255 e converta
o resultado para o tipo int.*/

Histograma *CalcularHistograma(Imagem *img, int nIntervalos){
    if(img == NULL){
        printf("A imagem fornecida para o calculo do histograma nao eh valida\n");
        exit(0);
    }
    
    int *copia = (int *)malloc(sizeof(int) * ObterAltura(img) * ObterLargura(img));
    if(copia == NULL){
        printf("falha em criar copia de dados\n");
        exit(0);
    }

    if (ObterTipoImagem(img) == FLOAT){

        for (int i = 0; i < ObterAltura(img) * ObterLargura(img); i++){
            copia[i] = (int)(((float*)ObterDadosImagem(img))[i] * 255);
        }
    }
    else{
        memcpy(copia, (int*)ObterDadosImagem(img), sizeof(int) * ObterAltura(img) * ObterLargura(img));
    }

    Histograma *h = (Histograma*) malloc(sizeof(Histograma));
    if(h == NULL){
        printf("falha na criacao de histograma!\n");
        exit(0);
    }

    h->nIntervalos = nIntervalos;
    h->tamIntervalos = (int)ceil(256.0 / nIntervalos);
    h->nPixels = ObterAltura(img) * ObterAltura(img);

    h->vetHistograma = (int*)malloc(nIntervalos * sizeof(int));
    if(h->vetHistograma == NULL){
        printf("falha em alocar vetor de intervalos!\n");
        exit(0);
    }
    //reset dos valores no histograma
    for(int i = 0; i < nIntervalos; i++){
        h->vetHistograma[i] = 0;
    }//

    //Contagem do histograma
    for(int c = 0; c < (ObterAltura(img) * ObterLargura(img)); c++){
        int id = copia[c]/h->tamIntervalos;
        
        if(0 <= id && id <= h->nIntervalos){
            h->vetHistograma[id]++;
        }
        else{
            printf("aiai:/\n");
        }
    }//

    free(copia);
    return h;
}

void MostrarHistograma(Histograma *histograma){
    for(int h = 0; h < histograma->nIntervalos; h++){
        int fim = (h + 1)*(histograma->tamIntervalos);
        int inicio = h * (histograma->tamIntervalos);
        printf("[%d, %d): %d\n", inicio, fim, histograma->vetHistograma[h]);
    }
}

void DestruirHistograma(Histograma *histograma){
    if(histograma == NULL){
        return;
    }
    free(histograma->vetHistograma);
    free(histograma);
}