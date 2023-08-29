#include <stdio.h>
#include <math.h>

#define BASE 8

int FazConversao(int decimal);

int main(){
    int decimal = 0;
    scanf("%d", &decimal);

    int convertido = FazConversao(decimal);

    printf("%d\n", convertido);
    return 0;
}

int FazConversao(int decimal){
    int i = 0, resto = 0, convertido = 0;

    while(decimal != 0){
        resto = decimal % BASE;
        
        convertido = convertido + resto * pow(10, i);
        
        decimal /= BASE;
        
        i++;
    }

    return convertido;
}