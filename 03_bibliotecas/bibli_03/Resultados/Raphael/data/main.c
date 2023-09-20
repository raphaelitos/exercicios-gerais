#include "data.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    int dia1 = 0, mes1 = 0, ano1 = 0;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    
    int dia2 = 0, mes2 = 0, ano2 = 0;
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if(!(verificaDataValida(dia1, mes1, ano1) && verificaDataValida(dia2, mes2, ano2))){
        printf("A primeira e/ou segunda data(s) invalida(s)");
        exit(0);
    }

    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1){
        printf("Primeira data: ");
        imprimeDataExtenso(dia2, mes2, ano2);
        printf("Segunda data: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        printf("A segunda data eh mais antiga\n");
    }

    else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1){
        printf("Primeira data: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        printf("Segunda data: ");
        imprimeDataExtenso(dia2, mes2, ano2);
        printf("A primeira data eh mais antiga\n");
    }

    else{
        printf("Primeira data: ");
        imprimeDataExtenso(dia2, mes2, ano2);
        printf("Segunda data: ");
        imprimeDataExtenso(dia1, mes1, ano1);
        printf("As datas sao iguais\n");
    }

    if(calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2) < 10)
        printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));
    else
        printf("A diferenca em dias entre as datas eh: %d dias\n", calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2));

    return 0;
}