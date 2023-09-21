#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int dia = 0, mes = 0, ano = 0;
    scanf("%d/%d/%d", &dia, &mes, &ano);

    if(!verificaDataValida(dia, mes, ano)){
        printf("Essa data nao eh valida");
        exit(0);
    }

    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);
    printf("O ano informado ");
    if(verificaBissexto(ano)){
        printf("eh bissexto\n");
    }
    else{
        printf("nao eh bissexto\n");
    }
    printf("O mes informado posui %d dias\n", numeroDiasMes);
    imprimeProximaData(dia, mes, ano);
    return 0;
}