#include "data.h"
#include <stdio.h>

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    int qtdDiasNoMes;

    *data.ano = &ano;

    //Garante que o mes esta entre 1 e 12
    if (mes > 12){
        mes = 12;
    } else if (mes < 1){
        mes = 1;
    }
    *data.mes = mes;

    //Garante que o dia esta dentro dos limites permitidos para o mes
    qtdDiasNoMes = InformaQtdDiasNoMesMA(mes, ano);
    if ( dia > qtdDiasNoMes ){
        dia = qtdDiasNoMes;
    } else if (dia < 1){
        dia = 1;
    }
    *data.dia = dia;
    
    return *data;
}