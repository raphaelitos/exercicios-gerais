#include "data.h"
#include <stdio.h>
#include <stdlib.h>

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    int qtdDiasNoMes;

    data->ano = ano;

    //Garante que o mes esta entre 1 e 12
    if (mes > 12){
        mes = 12;
    } else if (mes < 1){
        mes = 1;
    }
    (*data).mes = mes;

    //Garante que o dia esta dentro dos limites permitidos para o mes
    qtdDiasNoMes = InformaQtdDiasNoMes(data);
    if ( dia > qtdDiasNoMes ){
        dia = qtdDiasNoMes;
    } else if (dia < 1){
        dia = 1;
    }
    data->dia = dia;
}

void LeData( tData *data ){

    int d, m, a;
    
    if ( scanf("%d %d %d", &d, &m, &a) != 3 ){
        printf("ERRO: Formato de entrada nao compativel!\n");
        exit(1); 
    }
    
    //Inicializa a data e garante q eh vailida
    InicializaDataParam( d, m, a, data);
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%04d'", (*data).dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){
    if ( !(data->ano%400) ){
        return 1;
    }
    if ( !(data->ano%100) ){
        return 0;
    }
    if ( !(data->ano%4) ){
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes( tData *data ){
    if ( data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11){
        return 30;
    }
    if ( data->mes == 2 ){
        if ( EhBissexto(data) ){
            return 29;
        }
        return 28;
    }
    return 31;
}

void AvancaParaDiaSeguinte( tData *data ){
    if ( data->dia < InformaQtdDiasNoMes(data) ){
        data->dia++;
    } else {
        data->dia = 1;
        if ( data->mes < 12 ){
            data->mes++;
        } else {
            data->mes = 1;
            data->ano++;
        }
    }
}

int EhIgual( tData *data1, tData *data2 ){
    return  data1->dia == data2->dia &&
            data1->mes == data2->mes &&
            data1->ano == data2->ano;  
}