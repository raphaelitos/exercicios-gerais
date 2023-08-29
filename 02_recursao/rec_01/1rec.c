#include <stdio.h>
#include <string.h>

#define MAX_LETRAS 1000

void ImprimeInvertido(char* string);

int main(){

    char palavra[MAX_LETRAS];
    while(scanf("%s", palavra) == 1){
        ImprimeInvertido(palavra);
        printf(" ");
    }

    return 0;
}

void ImprimeInvertido(char* string){
    int tam = strlen(string);
    
    if(tam == 0){
        return;
    }
    printf("%c", string[tam - 1]);
    string[tam - 1] = '\0';
    ImprimeInvertido(string);
}