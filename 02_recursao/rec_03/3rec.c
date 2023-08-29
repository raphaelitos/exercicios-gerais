#include <stdio.h>

int LeVet(int* vet, int tam);

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int main(){

    int N = 0;
    scanf("%d", &N);

    int c = 0;
    for(c = 0; c < N; c++){
        int X = 0, qtd = 0;
        scanf("%d %d", &X, &qtd);
        
        int vet[qtd];
        LeVet(vet, qtd);

        printf("%d\n", ContaOcorrencias(vet, qtd, X));
    }

    return 0;
}

int LeVet(int* vet, int tam){
    int i = 0;

    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    
    if(numElementos == 0){
        return 0;
    }
    
    if(vet[numElementos - 1] == numeroProcurado){
        return (ContaOcorrencias(vet, numElementos - 1, numeroProcurado) + 1);
    }

    return((ContaOcorrencias(vet, numElementos - 1, numeroProcurado)));   
}