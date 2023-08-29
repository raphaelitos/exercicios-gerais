#include <stdio.h>
#include <string.h>

#define MAX_LETRAS 1000

int palindromo(char* string, int tamanho);

int SelecionaId(int tam, int atual);

int main(){

    char palavra[MAX_LETRAS];

    while (scanf("%s", palavra) == 1){
        if(palindromo(palavra, strlen(palavra))){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
    }  

    return 0;
}

int palindromo(char* string, int tamanho){
    int tam = strlen(string);
    
    if(SelecionaId(tam, tamanho - 1) == -1){
        return 1;
    }

    else if((tamanho -1) - SelecionaId(tam, tamanho - 1) == 1){
        if(string[tamanho - 1] == string[SelecionaId(tam, tamanho - 1)]){
            return 1;
        }
    }

    if(string[tamanho - 1] == string[SelecionaId(tam, tamanho - 1)]){
        return palindromo(string, tamanho - 1);
    }

    else{
        return 0;
    }
}   

int SelecionaId(int tam, int atual){
    int i = 0;
    for(i = 0; i < atual; i++){
        if((atual + i) == tam - 1){
            return i;
        }
    }
    return -1; //caso em que a posicao esta no meio de um vetor impar
}
