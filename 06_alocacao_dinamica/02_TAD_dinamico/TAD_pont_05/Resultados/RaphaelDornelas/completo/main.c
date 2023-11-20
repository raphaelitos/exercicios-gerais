#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    tBanco* banco = CriaBanco();
    char opcao = '\0';
    int num = 0;
    int id = 0, pos = 0, valor = 0;

    while(1){
        scanf("%c\n", &opcao);
        switch (opcao)
        {
        case 'A':
            AbreContaBanco(banco);
            break;
        case 'D':
            DepositoContaBanco(banco);      
            break;
        case 'S':
            SaqueContaBanco(banco);
            break;
        case 'T':
            TransferenciaContaBanco(banco);
            break;  
        case 'R':
            ImprimeRelatorioBanco(banco);
            break;
        case 'F':
            DestroiBanco(banco);
            exit(0);
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}