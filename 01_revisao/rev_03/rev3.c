#include <stdio.h>

void LeVet(int* vet, int tam);
void resetavet(int* vet, int tam);
void ImprimeUnicos(int* livros, int tam, int* repetidos);

int main(){

    int N = 0;
    scanf("%d\n", &N);

    int livros[N];
    LeVet(livros, N);

    int repetidos[N];
    resetavet(repetidos, N);
    
    int i = 0, j = 0;

    for(i = 0; i < N; i++){
        for(j = i + 1; j < N; j++){
            if(livros[i] == livros[j]){
                repetidos[i] = livros[i];
                break;
            }
        }
    }

    ImprimeUnicos(livros, N, repetidos);

    return 0;
}

void LeVet(int* vet, int tam){
    int i = 0;

    for(i = 0; i < tam; i++){
        scanf("%d", &vet[i]);
    }
}


void resetavet(int* vet, int tam){
    int i = 0;
    for(i = 0; i < tam; i++){
        vet[i] = 0;
    }
}

void ImprimeUnicos(int* livros, int tam, int* repetidos){
    int i = 0, j = 0, flag = 0;
    for(i = 0; i < tam; i++){
        flag = 0;
        for(j = 0; j < tam; j++){
            if(repetidos[j] == 0){
                break;
            }
            if(repetidos[j] == livros[i]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("%d ", livros[i]);
        }
    }
}