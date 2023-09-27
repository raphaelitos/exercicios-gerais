#include "utils.h"
#include <stdio.h>

void LeNumeros(int *array, int tamanho){
    for(int i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    *maior = array[0];
    *menor = array[0]; 
    int soma = array[0];
    for(int i = 1; i < tamanho; i++){
        if(*menor > array[i]){
            *menor = array[i];
        }
        if(*maior < array[i]){
            *maior = array[i];
        }
        soma += array[i];
    }    
    *media =  soma/tamanho;
}
