#include <stdio.h>
#include <math.h>

float CalculaDistanciaEntreOsCentros(float x1, float y1, float x2, float y2);

int Colidiu(float distancia, float raio1, float raio2);

int main(){

    float x1, y1, raio1;
    float x2, y2, raio2;

    scanf("%f %f %f %f %f %f", &x1, &y1, &raio1, &x2, &y2, &raio2);

    float distancia = CalculaDistanciaEntreOsCentros(x1, y1, x2, y2);

    if(Colidiu(distancia, raio1, raio2)){
        printf("ACERTOU\n");
    }
    else{
        printf("ERROU\n");
    }

    return 0;
}

float CalculaDistanciaEntreOsCentros(float x1, float y1, float x2, float y2){
    float distancia;

    distancia = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    
    return distancia;
}

int Colidiu(float distancia, float raio1, float raio2){
    return (distancia <= raio1 + raio2);
}