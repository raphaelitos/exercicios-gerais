#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tImagem{
    int altura;
    int largura;
    Tipo tipo;
    void *pixels; 
};

int ObterAltura(Imagem *img){
    if(img) return img->altura;
    return 0;
}

int ObterLargura(Imagem *img){
    if(img) return img->largura;
    return 0;
}

Tipo ObterTipoImagem(Imagem *img){
    if(img) return img->tipo;
    return 0;    
}

void *ObterDadosImagem(Imagem *img){
    if(img) return img->pixels;
    return NULL;
}

void LeDadosInt(int* vet, int altura, int largura){
    for (int i = 0; i < altura * largura; i++) {
        scanf("%d", &vet[i]);
    }
}

void LeDadosFloat(float* vet, int altura, int largura){
    for (int i = 0; i < altura * largura; i++) {
        scanf("%f", &vet[i]);
    }
}

Imagem *CriarImagem(int altura, int largura, Tipo tipo){
    Imagem* img = (Imagem*)malloc(sizeof(Imagem));
    if(img == NULL){
        printf("Falha na criacao de imagem!\n");
        exit(0);
    }
    img->altura = altura;
    img->largura = largura;
    img->tipo = tipo;
    img->pixels = malloc(altura * largura * (tipo == INT ? sizeof(int) : sizeof(float)));
    
    if(img->pixels == NULL){
        printf("Falha em alocar vetor de dados da imagem!\n");
        free(img);
        exit(0);
    }

    tipo == INT ? LeDadosInt((int*)img->pixels, altura, largura) : LeDadosFloat((float*)img->pixels, altura, largura); 

    /*if(tipo == INT){
        LeDadosInt((int*)img->pixels, altura, largura);
    }
    else{
        LeDadosFloat((float*)img->pixels, altura, largura);
    }*/

    return img;
}

Imagem *LerImagem(){ 
    int altura, largura, tipo;
    scanf("%d %d %d", &altura, &largura, &tipo);
    Imagem *img = CriarImagem(altura, largura, (Tipo)tipo);
    
    return img;
}

void ImprimirImagem(Imagem *img){
    if(img == NULL){
        return;
    }
    for(int i = 0; i < img->altura; i++){
        for(int j = 0; j < img->largura; j++){
            img->tipo == INT ? printf("%d ", ((int *)img->pixels)[i*img->altura + j]) : printf("%f ", ((float*)img->pixels)[i*img->altura + j]);
        }
        printf("\n");
    }
}

void DestruirImagem(Imagem *img){
    if(img == NULL){
        return;
    }
    free(img->pixels);
    free(img);
}