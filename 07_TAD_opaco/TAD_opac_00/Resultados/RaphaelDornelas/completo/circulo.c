#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct circulo
{
    tPonto centro;
    float raio;
}circulo;

//AUXILIARES//

/// @brief atualiza as coordenadas de p1
/// atribuindo a elas as coordenadas de p2
void AtualizaPonto(tPonto p1, tPonto p2){
    Pto_Atribui_x(p1, Pto_Acessa_x(p2));
    Pto_Atribui_y(p1, Pto_Acessa_y(p2));
}

/***********/

tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo cTemp = (tCirculo) malloc(sizeof(circulo));

    if(cTemp == NULL){
        printf("Falha em criar circulo!\n");
        exit(0);
    }

    cTemp->centro = Pto_Cria(x, y);
    cTemp->raio = r;

    //printf("centro:{%f,%f}\n", Pto_Acessa_x(cTemp->centro), Pto_Acessa_y(cTemp->centro));
    //printf("raio: %f\n", cTemp->raio);

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
    if(!c || !p) return;

    AtualizaPonto(Circulo_Acessa_Centro(c), p);
}

void Circulo_Atribui_Raio (tCirculo c, float r){
    c->raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p){
    
    //printf("dist:%f\nraio:%f\n", Pto_Distancia(c->centro, p), c->raio);
    
    return(Pto_Distancia(c->centro, p) <= c->raio);
}