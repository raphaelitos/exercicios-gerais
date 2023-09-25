#include "utils.h"
#include <stdio.h>

void LeIntervalo(int * m, int * n){
    scanf("%d %d", m, n);
}

int EhPrimo(int n){
    int den = 2;
    
    for(den = 2; den < n; den++){
        if(!(n % den)){ //finding divisors
            return 0;
        }
    }

    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    
    *menor = n;
    *maior = m;
    
    for(int i = m; i <= n; i++){
        if(EhPrimo(i)){
            if(i < *menor){
                *menor = i;
            }
            else if(i > *maior){
                *maior = i;
            }
        }
    }
}