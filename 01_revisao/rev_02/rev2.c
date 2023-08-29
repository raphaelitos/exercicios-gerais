#include <stdio.h>

void FazTriangulo(int N);

int main(){

    int N;
    scanf("%d", &N);

    FazTriangulo(N);

    return 0;
}

void FazTriangulo(int N){
    int i = 0, j = 1, num = 1, cont = 0;

    for(i = 0; i < N; i++){
        cont = 0;
        while(cont < j){
            printf("%d ", num);
            num++;
            cont++;
        }
        j++;
        printf("\n");
    }
}