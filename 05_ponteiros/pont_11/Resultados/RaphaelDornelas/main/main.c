#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>

float soma(float n1, float n2){
    printf("%.2f + %.2f = ", n1, n2);
    return (n1 + n2);
}

float subtracao(float n1, float n2){
    printf("%.2f - %.2f = ", n1, n2);
    return (n1 - n2);
}

float multiplicacao(float n1, float n2){
    printf("%.2f x %.2f = ", n1, n2);
    return (n1 * n2);
}

float divisao(float n1, float n2){
    printf("%.2f / %.2f = ", n1, n2);
    return (n1 / n2);
}

int main(){

    char opcao;
    CalculatoraCallback operacao;
    float n1 = 0, n2 = 0;
    float resultado;
    while(1){
        scanf("%*[^A-Za-z]");
        scanf("%c", &opcao);

        if(opcao != 'f'){
            scanf("%f %f", &n1, &n2);
        }

        switch (opcao)
        {
        case 'f':
            exit(0);
            break;
        case 's':
            operacao = subtracao;
            break;
        
        case 'a':
            operacao = soma;
            break;
        case 'm':
            operacao = multiplicacao;
            break;
        case 'd':
            operacao = divisao;
        default:
            break;
        }
        
        resultado = Calcular(n1, n2, operacao);
        printf("%.2f\n", resultado);
    }

    return 0;
}