#include "data.h"
#include <stdio.h>
#include <string.h>

int verificaDataValida(int dia, int mes, int ano){
    return (dia >= 0 && dia <= numeroDiasMes(mes, ano));
}

void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro");
    }
    else if(mes == 2){
        printf("Fevereiro");
    }
    else if(mes == 3){
        printf("Marco");
    }
    else if(mes == 4){
        printf("Abril");
    }
    else if(mes == 5){
        printf("Maio");
    }
    else if(mes == 6){
        printf("Junho");
    }
    else if(mes == 7){
        printf("Julho");
    }
    else if(mes == 8){
        printf("Agosto");
    }
    else if(mes == 9){
        printf("Setembro");
    }
    else if(mes == 10){
        printf("Outubro");
    }
    else if(mes == 11){
        printf("Novembro");
    }
    else{
        printf("Dezembro");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%.2d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int verificaBissexto(int ano){

    if(!(ano % 400)){
    	return 1;
    }
    if(!(ano % 100)){
    	return 0;
    }
    if(!(ano % 4)){
    	return 1;
    }
   
    return 0;
}

int numeroDiasMes(int mes, int ano){
    if(mes == 2){
        if(verificaBissexto(ano)){
            return 29;
        }
        
        else{
            return 28;
        }
    }

    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }

    else{
        return 31;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 < ano2){
        return (-1);
    }
    if(ano2 <  ano1){
        return 1;
    }
    
    //se chegar aqui, os anos sao iguais

    if(mes1 < mes2){
        return (-1);
    }
    if(mes2 < mes1){
        return 1;
    }

    //meses iguais

    if(dia1 < dia2){
        return (-1);
    }
    if(dia2 < dia1){
        return 1;
    }

    return 0; //datas identicas
}

int calculaDiasAteMes(int mes, int ano){
    int i = 1, dias = 0;
    for(i = 1; i < mes; i++){
        dias += numeroDiasMes(i, ano);
    }

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int anoi = 0, anof = 0, mesi = 0, mesf = 0, diai = 0, diaf = 0;


    if(!comparaData(dia1, mes1, ano1, dia2, mes2, ano2)){ //datas iguais
        return 0;
    }
    
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1){
        diai = dia2, diaf = dia1, mesi = mes2, mesf = mes1, anoi = ano2, anof = ano1;
    }
    else{
        diai = dia1, diaf = dia2, mesi = mes1, mesf = mes2, anoi = ano1, anof = ano2;
    }
    
    int diferenca = 0;
    int a = 0, m = 0, d = 0;

    for(a = anoi; a < anof; a++){
        if(verificaBissexto(a)){
            diferenca += 366;
        }
        else{
            diferenca += 365;
        }
    } //calculo anual
    
    if(mesf > mesi){
        diferenca += calculaDiasAteMes(mesf, anof) - calculaDiasAteMes(mesi, anoi);
    }
    else if(mesf < mesi){
        diferenca -= calculaDiasAteMes(mesi, anoi) - calculaDiasAteMes(mesf, anof);
    }//calculo mensal

    if(diaf > diai){
        diferenca += diaf - diai;
    }
    else if(diaf < diai){
        diferenca -= diai - diaf;
    }//calculo diario

    return diferenca;
}

void imprimeProximaData(int dia, int mes, int ano){
    
    if(dia + 1 > numeroDiasMes(mes, ano)){
        dia = 1;
        if(mes == 12){
            mes = 1;
            ano++;
        }
        else{
            mes++;
        }
    }
    else{
        dia++;
    }
    imprimeData(dia, mes, ano);
}