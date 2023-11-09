#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct circulo
{
    tPonto centro;
    float raio;
}circulo;

tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo cTemp = (tCirculo) malloc(sizeof(circulo));

    if(cTemp == NULL){
        printf("Falha em criar circulo!\n");
        exit(0);
    }

    cTemp->centro = Pto_Cria(x, y);
    cTemp->raio = r;

    return cTemp;
}

void Circulo_Apaga (tCirculo c){
    if(c->centro) Pto_Apaga(c->centro);
    if(c) free(c);
}

tPonto Circulo_Acessa_Centro (tCirculo c){
    return(c->centro);
}

float Circulo_Acessa_Raio (tCirculo c){
    return(c->raio);
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    if(!c) return;

    c->centro = 
}