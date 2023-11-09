#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto
{
    float x;
    float y;
}ponto;

float CalculaDistanciaCoordenadas(float x1, float y1, float x2, float y2){
    return pow((pow((x2 - x1), 2) + pow((x2 - x1), 2)), (1/2));
}

tPonto Pto_Cria (float x, float y){
    tPonto pontoTemp = (tPonto) malloc(sizeof(ponto));

    if(pontoTemp == NULL){
        printf("Falha em criar um ponto!\n");
        exit(0);
    } 

    pontoTemp->x = x;
    pontoTemp->y = y;

    return pontoTemp;
}

void Pto_Apaga (tPonto p){
    free(p);
}

float Pto_Acessa_x (tPonto p){
    return(p->x);
}

float Pto_Acessa_y (tPonto p){
    return(p->y);
}

void Pto_Atribui_x (tPonto p, float x){
    p->x = x; 
}

void Pto_Atribui_y (tPonto p, float y){
    p->y = y;
}

float Pto_Distancia (tPonto p1, tPonto p2){
    return CalculaDistanciaCoordenadas(p1->x, p1->y, p2->x, p2->y);
}