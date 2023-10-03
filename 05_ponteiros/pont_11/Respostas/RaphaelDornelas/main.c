#include "calculadora.h"
#include <stdio.h>

float soma(int n1, int n2){
    return (n1 + n2);
}

float subtracao(int n1, int n2){
    return (n1 - n2);
}

float multiplicacao(int n1, int n2){
    return (n1 * n2);
}

float divisao(int n1, int n2){
    return (n1 / n2);
}

int main(){

    char opcao;
    CalculatoraCallback operacao;
    int n1 = 0, n2 = 0;
    float resultado;
    while(1){
        scanf("%*[^A-Za-z]");
        scanf("%c", &opcao);

        if(opcao != 'f'){
            scanf("%d %d", &n1, &n2);
        }

        switch (opcao)
        {
        case 'f':
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
            printf("Opcao invalida!\n");
        }
    }
    

    return 0;
}