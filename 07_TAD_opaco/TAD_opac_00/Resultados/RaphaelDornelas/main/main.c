#include "circulo.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    float xCent, yCent, raio, xP, yP;
    scanf("%f %f %f %f %f", &xCent, &yCent, &raio,
                            &xP, &yP);


    tPonto pto = Pto_Cria(xP, yP);
    tCirculo circlo = Circulo_Cria(xCent, yCent, raio);

    printf("%d\n", Circulo_Interior(circlo, pto));

    Pto_Apaga(pto);
    Circulo_Apaga(circlo);
    return 0;
}