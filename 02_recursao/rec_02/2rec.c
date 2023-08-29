#include <stdio.h>

void LeVet(int* vet, int tam);

int EhPar(int num);

int SomaElementosPares(int* vet, int numElementos);

int main(){
    int N = 0;
    scanf("%d", &N);

    int i = 0;
    int qtd = 0;

    for(i = 0; i < N; i++){
        scanf("%d", &qtd);
        int vet[qtd];
        LeVet(vet, qtd);
        printf("%d\n", SomaElementosPares(vet, qtd));
    }
    
    return 0;
}

void LeVet(int* vet, int tam){
    int i = 0;

    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
}

int EhPar(int num){
    return !(num % 2);
}

int SomaElementosPares(int* vet, int numElementos){
    if(numElementos == 0){
        return 0;
    }
    if(EhPar(vet[numElementos - 1])){
        return SomaElementosPares(vet, numElementos - 1) + vet[numElementos - 1];
    }
    else{
        return SomaElementosPares(vet, numElementos - 1) + 0;
    }
}
