#include "conta.h"
#include <stdio.h>


int main(){

    int num = 0, opcao = 0;
    int id = 0, pos = 0;
    float valor = 0.0;
    scanf("%d", &num);
    tConta contas[num];
    while(1){
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            scanf("%d %f", &id, &valor);
            for(int c = 0; c < num; c++){
                if(VerificaConta(contas[c], id)){
                    contas[c] = SaqueConta(contas[c], valor);
                    break;
                }
            }
            break;
        
        case 2:
            scanf("%d %f", &id, &valor);
            for(int c = 0; c < num; c++){
                if(VerificaConta(contas[c], id)){
                    contas [c] = DepositoConta(contas[c], valor);
                    break;
                }
            }        

        case 3:
            char nome[50];
            char cpf[15];
            scanf("%*[^A-Za-z]");
            scanf("%s %s %d", nome, cpf, &id);
            contas[pos++] = CriaConta(id, CriaUsuario(nome, cpf));
            /*for(int c = 0; c < num; c++){
                if(VerificaConta(contas[c], id)){
                    contas[c] = CriaConta(id, CriaUsuario(nome, cpf));
                    break;
                }
            }*/

        default:
            exit(0);
        }
    }
    return 0;
}